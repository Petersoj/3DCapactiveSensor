using System;
using System.IO.Ports;
using System.Threading;

namespace Controller {

    public class MainController {

        private SerialPort serialPort;
        private string portNumber;

        public MainController() {

        }

        public void ReadAsync(string portNumber) {
            this.portNumber = portNumber;

            Thread thread = new Thread(ReadThreadDelegate);
            thread.Start();
        }

        private void ReadThreadDelegate() {
            serialPort = new SerialPort("COM" + portNumber, 115200, Parity.None, 8, StopBits.One);
            serialPort.Open();

            byte[] buffer = new byte[1];

            while (serialPort.Read(buffer, 0, 1) > 0) {
                System.Diagnostics.Debug.WriteLine((char)buffer[0]);
            }
        }
    }
}
