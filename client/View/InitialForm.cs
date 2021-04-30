using System;
using System.Windows.Forms;

namespace Client3DCapacitiveSensor.View {

    /// <summary>
    /// <see cref="InitialForm"/> is the <see cref="Form"/> that prompts the user for data at the 
    /// start of the program.
    /// </summary>
    public partial class InitialForm : Form {

        /// <summary>
        /// Handles the start button click.
        /// </summary>
        /// <param name="comPortNumber"></param>
        /// <param name="baudRate"></param>
        /// <param name="parity"></param>
        /// <param name="dataBits"></param>
        /// <param name="stopBits"></param>
        /// <returns>True if the start was sucessful.</returns>
        public delegate bool StartButtonClickHandler(string comPortNumber, string baudRate, string parity,
            string dataBits, string stopBits);

        /// <summary>
        /// Handles the stop button click.
        /// </summary>
        /// <returns>True if the stop was sucessful.</returns>
        public delegate bool StopButtonClickHandler();

        private static readonly string START_BUTTON_START_TEXT = "Start";
        private static readonly string START_BUTTON_STOP_TEXT = "Stop";

        private StartButtonClickHandler startButtonClickHandler;
        private StopButtonClickHandler stopButtonClickHandler;

        /// <summary>
        /// Instantiates a new <see cref="InitialForm"/>.
        /// <param name="startButtonClickHandler"><see cref="StartButtonClickHandler"/></param>
        /// <param name="stopButtonClickHandler"><see cref="StopButtonClickHandler"/></param>
        /// </summary>
        public InitialForm(StartButtonClickHandler startButtonClickHandler, StopButtonClickHandler stopButtonClickHandler) {
            this.startButtonClickHandler = startButtonClickHandler;
            this.stopButtonClickHandler = stopButtonClickHandler;

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
            if (startButton.Text.Equals(START_BUTTON_START_TEXT)) {
                bool startSuccess = startButtonClickHandler.Invoke(
                    comPortNumberTextBox.Text,
                    baudRateTextBox.Text,
                    (string)parityComboBox.SelectedItem,
                    dataBitsTextBox.Text,
                    (string)stopBitsComboBox.SelectedItem);

                if (startSuccess) {
                    // Minimize window
                    WindowState = FormWindowState.Minimized;

                    startButton.Text = START_BUTTON_STOP_TEXT;
                }
            } else {
                if (stopButtonClickHandler.Invoke()) {
                    startButton.Text = START_BUTTON_START_TEXT;
                }
            }
        }
    }
}
