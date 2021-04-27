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
using Controller;

namespace Client3DCapacitiveSensorView {

    public partial class InitialForm : Form {

        private readonly MainController mainController;

        public InitialForm() {
            mainController = new MainController();
        }

        public void Start() {
            InitializeComponent();
        }

        private void StartButtonClick(object sender, EventArgs eventArgs) {
            mainController.ReadAsync(comPortNumberTextBox.Text);
        }
    }
}
