
namespace Client3DCapacitiveSensorView {
    partial class InitialForm {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.comPortNumberTextBox = new System.Windows.Forms.TextBox();
            this.titleLabel = new System.Windows.Forms.Label();
            this.comPortNumberLabel = new System.Windows.Forms.Label();
            this.startButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // comPortNumberTextBox
            // 
            this.comPortNumberTextBox.Location = new System.Drawing.Point(182, 117);
            this.comPortNumberTextBox.MaximumSize = new System.Drawing.Size(400, 4);
            this.comPortNumberTextBox.Name = "comPortNumberTextBox";
            this.comPortNumberTextBox.Size = new System.Drawing.Size(150, 23);
            this.comPortNumberTextBox.TabIndex = 0;
            // 
            // titleLabel
            // 
            this.titleLabel.AutoSize = true;
            this.titleLabel.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.titleLabel.Location = new System.Drawing.Point(87, 9);
            this.titleLabel.Name = "titleLabel";
            this.titleLabel.Size = new System.Drawing.Size(225, 32);
            this.titleLabel.TabIndex = 1;
            this.titleLabel.Text = "3DCapacitiveSensor";
            // 
            // comPortNumberLabel
            // 
            this.comPortNumberLabel.AutoSize = true;
            this.comPortNumberLabel.Location = new System.Drawing.Point(38, 120);
            this.comPortNumberLabel.Name = "comPortNumberLabel";
            this.comPortNumberLabel.Size = new System.Drawing.Size(138, 15);
            this.comPortNumberLabel.TabIndex = 2;
            this.comPortNumberLabel.Text = "Enter COM Port number:";
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(152, 162);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 24);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.StartButtonClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(65, 58);
            this.label1.MaximumSize = new System.Drawing.Size(300, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(257, 30);
            this.label1.TabIndex = 4;
            this.label1.Text = "Uses a large \"3D\" capacitor to measure the XYZ coordinates of a user\'s hand in ph" +
    "ysical space.";
            // 
            // InitialForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 255);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.comPortNumberLabel);
            this.Controls.Add(this.titleLabel);
            this.Controls.Add(this.comPortNumberTextBox);
            this.Name = "InitialForm";
            this.Text = "3DCapacitiveSensor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox comPortNumberTextBox;
        private System.Windows.Forms.Label titleLabel;
        private System.Windows.Forms.Label comPortNumberLabel;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Label label1;
    }
}

