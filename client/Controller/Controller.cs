using System;
using Client3DCapacitiveSensor.View;
using System.Threading;

namespace Client3DCapacitiveSensor.Controller {

    /// <summary>
    /// This class serves as the application controller.
    /// </summary>
    public class Controller {

        private static readonly int MAX_X_INPUT = 100;
        private static readonly int MAX_Y_INPUT = 100;
        private static readonly int MAX_Z_INPUT = 100;

        private ViewController viewController;
        private Thread viewControllerthread;
        private CursorController cursorController;
        private SerialInterface serialInterface;
        private Thread serialInterfaceThread;

        /// <summary>
        /// Instantiates a new <see cref="Controller"/>.
        /// </summary>
        public Controller() {
            viewController = new ViewController(StartButtonClickHandler, StopButtonClickHandler);
            viewControllerthread = new Thread((ThreadStart)delegate {
                viewController.Start();
            });
            cursorController = new CursorController(MAX_X_INPUT, MAX_Y_INPUT);
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
            // TODO
            return true;
        }

        /// <summary>
        /// <see cref="InitialForm.StopButtonClickHandler"/>
        /// </summary>
        public bool StopButtonClickHandler() {
            // TODO
            return true;
        }

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        public static void Main() {
            new Controller().Start();
        }
    }
}
