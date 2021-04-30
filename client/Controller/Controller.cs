using System;
using Client3DCapacitiveSensor.View;

namespace Client3DCapacitiveSensor.Controller {

    public static class Controller {

        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        public static void Main() {
            ViewController viewController = new ViewController();
            viewController.Start();
        }
    }
}
