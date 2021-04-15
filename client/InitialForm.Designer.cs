
namespace Client3DCapacitiveSensor {
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
            this.SuspendLayout();
            // 
            // comPortNumberTextBox
            // 
            this.comPortNumberTextBox.Location = new System.Drawing.Point(182, 81);
            this.comPortNumberTextBox.Name = "comPortNumberTextBox";
            this.comPortNumberTextBox.Size = new System.Drawing.Size(150, 23);
            this.comPortNumberTextBox.TabIndex = 0;
            // 
            // titleLabel
            // 
            this.titleLabel.AutoSize = true;
            this.titleLabel.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.titleLabel.Location = new System.Drawing.Point(86, 20);
            this.titleLabel.Name = "titleLabel";
            this.titleLabel.Size = new System.Drawing.Size(225, 32);
            this.titleLabel.TabIndex = 1;
            this.titleLabel.Text = "3DCapacitiveSensor";
            // 
            // comPortNumberLabel
            // 
            this.comPortNumberLabel.AutoSize = true;
            this.comPortNumberLabel.Location = new System.Drawing.Point(38, 84);
            this.comPortNumberLabel.Name = "comPortNumberLabel";
            this.comPortNumberLabel.Size = new System.Drawing.Size(138, 15);
            this.comPortNumberLabel.TabIndex = 2;
            this.comPortNumberLabel.Text = "Enter COM Port number:";
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(152, 126);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 23);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.StartButtonClick);
            // 
            // InitialForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 161);
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
    }
}

