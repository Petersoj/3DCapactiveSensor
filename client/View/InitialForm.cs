using System;
using System.Windows.Forms;
using Controller;

namespace Client3DCapacitiveSensorView {

    /// <summary>
    /// <see cref="InitialForm"/> is the <see cref="Form"/> that prompts the user for data at the 
    /// start of the program.
    /// </summary>
    public partial class InitialForm : Form {

        private readonly SerialInterface mainController;

        public InitialForm() {
            
        }

        public void Start() {
            InitializeComponent();
        }

        private void StartButtonClick(object sender, EventArgs eventArgs) {
            
        }
    }
}
