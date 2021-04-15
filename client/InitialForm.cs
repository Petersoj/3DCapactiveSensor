using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Windows.Forms;
using System.Threading;

namespace Client3DCapacitiveSensor {
    public partial class InitialForm : Form {

        private SerialPort serialPort;

        public InitialForm() {
            InitializeComponent();
        }

        private void StartButtonClick(object sender, EventArgs eventArgs) {
            Thread thread = new Thread(Read);
            thread.Start();
        }

        private void Read() {
            serialPort = new SerialPort("COM" + comPortNumberTextBox.Text, 115200, Parity.None, 8, StopBits.One);
            serialPort.Open();

            byte[] buffer = new byte[1];

            while (serialPort.Read(buffer, 0, 1) > 0) {
                System.Diagnostics.Debug.WriteLine((char)buffer[0]);
            }
        }
    }
}
