using System;
using System.IO.Ports;

namespace Client3DCapacitiveSensor.Controller {

    /// <summary>
    /// This class is for easy interfacing with an <see cref="SerialPort"/> asynchronously.
    /// </summary>
    public class SerialInterface {

        /// <summary>
        /// The COM port number.
        /// </summary>
        public string COMPortNumber { get; private set; }
        /// <summary>
        /// The serial baud rate.
        /// </summary>
        public int BaudRate { get; private set; }
        /// <summary>
        /// The serial parity.
        /// </summary>
        public Parity Parity { get; private set; }
        /// <summary>
        /// The number of data bits.
        /// </summary>
        public int DataBits { get; private set; }
        /// <summary>
        /// The number of stop bits.
        /// </summary>
        public StopBits StopBits { get; private set; }

        private readonly SerialPort serialPort;


        /// <summary>
        /// Instantiates a new <see cref="SerialInterface"/>.
        /// </summary>
        /// <param name="comPortNumber"></param>
        /// <param name="baudRate"></param>
        /// <param name="parity"></param>
        /// <param name="dataBits"></param>
        /// <param name="stopBits"></param>
        public SerialInterface(string comPortNumber, int baudRate, Parity parity, int dataBits, StopBits stopBits) {
            COMPortNumber = comPortNumber;
            BaudRate = baudRate;
            Parity = parity;
            DataBits = dataBits;
            StopBits = stopBits;

            // Create and configure 'serialPort'
            serialPort = new SerialPort("COM" + COMPortNumber, BaudRate, Parity, DataBits, StopBits);
            serialPort.NewLine = "\n";
            serialPort.ReadTimeout = 1000; // Timeout on read after not seeing data for 1 second.
        }

        /// <summary>
        /// Establishes a serial interface connection.
        /// </summary>
        /// <exception cref="Exception">Thrown for a variety of exceptions.</exception>
        public void Start() {
            serialPort.Open();
        }

        /// <summary>
        /// Reads a line (a string ending with '\n' (LF)) from the <see cref="SerialPort"/>.
        /// </summary>
        /// <returns>The line read from the <see cref="SerialPort"/></returns>
        /// <exception cref="Exception">Thrown for a variety of exceptions.</exception>
        public string ReadLine() {
            return serialPort.ReadLine();
        }
    }
}
