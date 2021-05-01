using System;
using Client3DCapacitiveSensor.View;
using System.Threading;
using System.IO.Ports;

namespace Client3DCapacitiveSensor.Controller {

    /// <summary>
    /// This class serves as the application controller.
    /// </summary>
    public class Controller {

        /*
         * Note that no XYZ coordinate inputs should be negative!
         * Also note that (0,0,0) is inner-most corner of the cubic 3D Capacitor and that
         * ('MAX_X_INPUT','MAX_X_INPUT','MAX_X_INPUT') should be the furthest coordinate from
         * the inner-most corner (aka no hand detected in the 3D Capacitor).
         */
        private static readonly int MAX_X_INPUT = 100;
        private static readonly int MAX_Y_INPUT = 100;
        private static readonly int MAX_Z_INPUT = 100;
        private static readonly int Z_MIN_OF_MOUSE_LEFT_BUTTON_DOWN = 0;
        private static readonly int Z_MAX_OF_MOUSE_LEFT_BUTTON_DOWN = 20;
        private static readonly string SERIAL_INPUT_COORDINATES_DELIMITER = ",";

        private ViewController viewController;
        private Thread viewControllerthread;
        private CursorController cursorController;
        private SerialInterface serialInterface;
        private Thread serialInterfaceThread;
        private bool serialInterfaceStopFlag;

        /// <summary>
        /// Instantiates a new <see cref="Controller"/>.
        /// </summary>
        public Controller() {
            viewController = new ViewController(StartButtonClickHandler, StopButtonClickHandler);
            viewControllerthread = new Thread((ThreadStart)delegate {
                viewController.Start();
            });
            cursorController = new CursorController(MAX_X_INPUT, MAX_Y_INPUT);
            serialInterfaceStopFlag = false;
        }

        /// <summary>
        /// Starts the controller.
        /// </summary>
        public void Start() {
            viewControllerthread.Start();
        }

        /// <summary>
        /// <see cref="InitialForm.StartButtonClickHandler"/>
        /// </summary>
        public bool StartButtonClickHandler(string comPortNumber, string baudRate, string parity, string dataBits, string stopBits) {
            int parsedBaudRate;
            Parity parsedParity;
            int parsedDataBits;
            StopBits parsedStopBits;

            // Parse UI parameters
            try {
                parsedBaudRate = int.Parse(baudRate);

                switch (parity) {
                    case "None":
                        parsedParity = Parity.None;
                        break;
                    case "Even":
                        parsedParity = Parity.Even;
                        break;
                    default:
                        throw new ArgumentException("Unsupported parity: " + parity);
                }

                parsedDataBits = int.Parse(dataBits);

                switch (stopBits) {
                    case "One":
                        parsedStopBits = StopBits.One;
                        break;
                    case "Two":
                        parsedStopBits = StopBits.Two;
                        break;
                    case "None":
                        parsedStopBits = StopBits.None;
                        break;
                    default:
                        throw new ArgumentException("Unsupported stop bits: " + stopBits);
                }
            } catch (Exception exception) {
                viewController.ShowError("Invalid inputs!\n" + exception.Message);
                return false;
            }

            try {
                serialInterface = new SerialInterface(comPortNumber, parsedBaudRate, parsedParity, parsedDataBits, parsedStopBits);
                serialInterface.Start();
            } catch (Exception exception) {
                viewController.ShowError("Could not establish serial interface!\n" + exception.Message);
                return false;
            }

            serialInterfaceStopFlag = false;

            serialInterfaceThread = new Thread(new ThreadStart(SerialInterfaceHandlerLoop));
            serialInterfaceThread.Start();

            return true;
        }

        /// <summary>
        /// <see cref="InitialForm.StopButtonClickHandler"/>
        /// </summary>
        public bool StopButtonClickHandler() {
            try {
                serialInterfaceStopFlag = true;
                serialInterface.Stop();

                // Wait for thread to stop (throw exception if not stopped after 5 seconds)
                serialInterfaceThread.Join(5000);
            } catch (Exception exception) {
                viewController.ShowError("Error stopping serial interface!\n" + exception.Message);
            }

            return true;
        }

        /// <summary>
        /// Handles the serial interface data loop.
        /// </summary>
        private void SerialInterfaceHandlerLoop() {
            while (!serialInterfaceStopFlag) {
                string serialLine;
                try {
                    serialLine = serialInterface.ReadLine();
                } catch (Exception exception) {
                    if (!serialInterfaceStopFlag) {
                        viewController.ShowError("Error reading serial interface!\n" + exception.Message);
                    }
                    return;
                }

                // Parse the data
                int x, y, z;
                string[] coordinateStrings = serialLine.Split(SERIAL_INPUT_COORDINATES_DELIMITER);
                try {
                    x = int.Parse(coordinateStrings[0]);
                    y = int.Parse(coordinateStrings[1]);
                    z = int.Parse(coordinateStrings[2]);
                } catch (Exception exception) {
                    System.Diagnostics.Debug.WriteLine("Invalid input: " + serialLine + "\n" + exception.Message);
                    continue;
                }

                // Confirm positive coordinates
                if (x < 0 || y < 0 || z < 0) {
                    System.Diagnostics.Debug.WriteLine("Coordinates cannot be negative: " + coordinateStrings);
                    continue;
                }

                // Clamp coordinates just in case
                if (x > MAX_X_INPUT) {
                    x = MAX_X_INPUT;
                }
                if (y > MAX_Y_INPUT) {
                    y = MAX_Y_INPUT;
                }
                if (z > MAX_Z_INPUT) {
                    z = MAX_Z_INPUT;
                }

                // Check if z coordinate should change mouse left button state
                if (z >= Z_MIN_OF_MOUSE_LEFT_BUTTON_DOWN && z <= Z_MAX_OF_MOUSE_LEFT_BUTTON_DOWN) {
                    if (!cursorController.IsLeftButtonDown()) {
                        cursorController.LeftButtonDown();
                    }
                } else {
                    if (cursorController.IsLeftButtonDown()) {
                        cursorController.LeftButtonUp();
                    }
                }

                // Update cursor coordinates
                cursorController.SetXY(x, y);
            }
        }

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        public static void Main() {
            new Controller().Start();
        }
    }
}
