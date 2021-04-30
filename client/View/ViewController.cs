using System;
using System.Windows.Forms;

namespace Client3DCapacitiveSensor.View {

    public class ViewController {

        private InitialForm initialForm;

        /// <summary>
        /// Instantiates a new <see cref="ViewController"/>.
        /// </summary>
        public ViewController() {
            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            initialForm = new InitialForm();
        }

        /// <summary>
        /// Starts the <see cref="ViewController"/>.
        /// </summary>
        public void Start() {
            Application.Run(initialForm);
        }
    }
}
