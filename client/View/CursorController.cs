using System;
using System.Windows.Forms;
using System.Drawing;
using System.Runtime.InteropServices;

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
        private bool leftButtonDown;

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

            leftButtonDown = false;
        }

        /// <summary>
        /// Sets the X,Y coordinates of the cursor.
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        public void SetXY(int x, int y) {
            Cursor.Position = new Point(
                (int)((double)x / maxInputX * screenWidth + minScreenX),
                (int)((double)y / maxInputY * screenHeight + minScreenY));
        }

        /// <summary>
        /// Simulates the user's left mouse button presseing down.
        /// </summary>
        public void LeftButtonDown() {
            mouse_event((int)MouseEventFlags.LeftDown, GetX(), GetY(), 0, 0);
            leftButtonDown = true;
        }

        /// <summary>
        /// Simulates the user's left mouse button presseing up.
        /// </summary>
        public void LeftButtonUp() {
            mouse_event((int)MouseEventFlags.LeftUp, GetX(), GetY(), 0, 0);
            leftButtonDown = false;
        }

        /// <summary>
        /// <see href="https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event"/>
        /// </summary>
        /// <param name="dwFlags"></param>
        /// <param name="dx"></param>
        /// <param name="dy"></param>
        /// <param name="dwData"></param>
        /// <param name="dwExtraInfo"></param>
        [DllImport("user32.dll")]
        private static extern void mouse_event(int dwFlags, int dx, int dy, int dwData, int dwExtraInfo);

        /// <summary>
        /// Gets <see cref="Cursor.Position.X"/>.
        /// </summary>
        /// <returns><see cref="Cursor.Position.X"/></returns>
        public int GetX() {
            return Cursor.Position.X;
        }

        /// <summary>
        /// Gets <see cref="Cursor.Position.Y"/>.
        /// </summary>
        /// <returns><see cref="Cursor.Position.Y"/></returns>
        public int GetY() {
            return Cursor.Position.Y;
        }

        /// <summary>
        /// True if <see cref="leftButtonDown"/>.
        /// </summary>
        /// <returns><see cref="leftButtonDown"/></returns>
        public bool IsLeftButtonDown() {
            return leftButtonDown;
        }

        /// <summary>
        /// Bit fields for <see cref="mouse_event(int, int, int, int, int)"/>.
        /// </summary>
        [Flags]
        private enum MouseEventFlags {
            LeftDown = 0x00000002,
            LeftUp = 0x00000004,
            MiddleDown = 0x00000020,
            MiddleUp = 0x00000040,
            RightDown = 0x00000008,
            RightUp = 0x00000010
        }
    }
}
