using System;
using System.Windows.Forms;

namespace Client3DCapacitiveSensor.View {

    /// <summary>
    /// Controls the view.
    /// </summary>
    public class ViewController {

        private InitialForm initialForm;
        private bool isErrorShown;

        /// <summary>
        /// Instantiates a new <see cref="ViewController"/>.
        /// <param name="startButtonClickHandler"><see cref="InitialForm.StartButtonClickHandler"/></param>
        /// <param name="stopButtonClickHandler"><see cref="InitialForm.StopButtonClickHandler"/></param>
        /// </summary>
        public ViewController(InitialForm.StartButtonClickHandler startButtonClickHandler,
            InitialForm.StopButtonClickHandler stopButtonClickHandler) {
            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            initialForm = new InitialForm(startButtonClickHandler, stopButtonClickHandler);
            isErrorShown = false;
        }

        /// <summary>
        /// Starts the <see cref="ViewController"/> synchronously.
        /// </summary>
        public void Start() {
            Application.Run(initialForm);
        }

        /// <summary>
        /// Shows an error <see cref="MessageBox"/> to the user. Not thread safe.
        /// </summary>
        /// <param name="message"></param>
        /// <returns></returns>
        public bool ShowError(string message) {
            if (isErrorShown) {
                Console.WriteLine("");
                return false;
            }

            isErrorShown = true;
            initialForm.Invoke(new Action(() => {
                MessageBox.Show(message, "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error, MessageBoxDefaultButton.Button1);
                isErrorShown = false;
            }));
            return true;
        }
    }
}
