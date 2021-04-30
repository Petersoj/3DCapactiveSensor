using System;
using System.Windows.Forms;

namespace Client3DCapacitiveSensor.View {

    /// <summary>
    /// <see cref="InitialForm"/> is the <see cref="Form"/> that prompts the user for data at the 
    /// start of the program.
    /// </summary>
    public partial class InitialForm : Form {

        /// <summary>
        /// Instantiates a new <see cref="InitialForm"/>.
        /// </summary>
        public InitialForm() {
            InitializeComponent();

            // Set default values
            baudRateTextBox.Text = "115200";
            parityComboBox.SelectedIndex = 0;
            dataBitsTextBox.Text = "8";
            stopBitsComboBox.SelectedIndex = 0;
        }

        /// <summary>
        /// Handles click for <see cref="startButton"/>.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="eventArgs"></param>
        private void OnStartButtonClick(object sender, EventArgs eventArgs) {

        }
    }
}
