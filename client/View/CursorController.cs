using System;
using System.Windows.Forms;
using System.Drawing;

namespace Client3DCapacitiveSensor.View {

    /// <summary>
    /// This class is for easy controlling of the user's mouse.
    /// </summary>
    public class CursorController {

        private readonly int maxInputX;
        private readonly int maxInputY;
        private readonly int minScreenX;
        private readonly int minScreenY;
        private readonly int screenWidth;
        private readonly int screenHeight;

        /// <summary>
        /// Instantiates a new <see cref="CursorController"/>
        /// </summary>
        /// <param name="maxInputX">The max X value that <see cref="SetXY(int, int)"/> will get.</param>
        /// <param name="maxInputY">The max Y value that <see cref="SetXY(int, int)"/> will get.</param>
        public CursorController(int maxInputX, int maxInputY) {
            this.maxInputX = maxInputX;
            this.maxInputY = maxInputY;

            Rectangle primaryScreenBounds = Screen.PrimaryScreen.Bounds;
            minScreenX = primaryScreenBounds.X;
            minScreenY = primaryScreenBounds.Y;
            screenWidth = primaryScreenBounds.Width;
            screenHeight = primaryScreenBounds.Height;
        }

        public void SetXY(int x, int y) {
            Cursor.Position = new Point(
                (x / maxInputX) * screenWidth + minScreenX,
                (y / maxInputY) * screenHeight + minScreenY);
        }

        public void LeftButtonDown() {
        }

        public void LeftButtonUp() {
        }

        /// <summary>
        /// Gets the X value of the cursor.
        /// </summary>
        /// <returns></returns>
        public int GetX() {
            return Cursor.Position.X;
        }

        /// <summary>
        /// Gets the Y value of the cursor.
        /// </summary>
        /// <returns></returns>
        public int GetY() {
            return Cursor.Position.Y;
        }
    }
}
