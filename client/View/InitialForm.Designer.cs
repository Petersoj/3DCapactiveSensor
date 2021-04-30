
namespace Client3DCapacitiveSensor.View {
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
            this.baudRateTextBox = new System.Windows.Forms.TextBox();
            this.buadRateLabel = new System.Windows.Forms.Label();
            this.parityLabel = new System.Windows.Forms.Label();
            this.dataBitsTextBox = new System.Windows.Forms.TextBox();
            this.dataBitsLabel = new System.Windows.Forms.Label();
            this.stopBitsLabel = new System.Windows.Forms.Label();
            this.parityComboBox = new System.Windows.Forms.ComboBox();
            this.stopBitsComboBox = new System.Windows.Forms.ComboBox();
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
            this.comPortNumberLabel.Size = new System.Drawing.Size(108, 15);
            this.comPortNumberLabel.TabIndex = 2;
            this.comPortNumberLabel.Text = "COM Port number:";
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(150, 279);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 24);
            this.startButton.TabIndex = 3;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.OnStartButtonClick);
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
            // baudRateTextBox
            // 
            this.baudRateTextBox.Location = new System.Drawing.Point(182, 146);
            this.baudRateTextBox.MaximumSize = new System.Drawing.Size(400, 4);
            this.baudRateTextBox.Name = "baudRateTextBox";
            this.baudRateTextBox.Size = new System.Drawing.Size(150, 23);
            this.baudRateTextBox.TabIndex = 5;
            // 
            // buadRateLabel
            // 
            this.buadRateLabel.AutoSize = true;
            this.buadRateLabel.Location = new System.Drawing.Point(38, 149);
            this.buadRateLabel.Name = "buadRateLabel";
            this.buadRateLabel.Size = new System.Drawing.Size(63, 15);
            this.buadRateLabel.TabIndex = 6;
            this.buadRateLabel.Text = "Baud Rate:";
            // 
            // parityLabel
            // 
            this.parityLabel.AutoSize = true;
            this.parityLabel.Location = new System.Drawing.Point(38, 177);
            this.parityLabel.Name = "parityLabel";
            this.parityLabel.Size = new System.Drawing.Size(40, 15);
            this.parityLabel.TabIndex = 7;
            this.parityLabel.Text = "Parity:";
            // 
            // dataBitsTextBox
            // 
            this.dataBitsTextBox.Location = new System.Drawing.Point(182, 204);
            this.dataBitsTextBox.MaximumSize = new System.Drawing.Size(400, 4);
            this.dataBitsTextBox.Name = "dataBitsTextBox";
            this.dataBitsTextBox.Size = new System.Drawing.Size(150, 23);
            this.dataBitsTextBox.TabIndex = 9;
            // 
            // dataBitsLabel
            // 
            this.dataBitsLabel.AutoSize = true;
            this.dataBitsLabel.Location = new System.Drawing.Point(38, 207);
            this.dataBitsLabel.Name = "dataBitsLabel";
            this.dataBitsLabel.Size = new System.Drawing.Size(117, 15);
            this.dataBitsLabel.TabIndex = 13;
            this.dataBitsLabel.Text = "Number of Data Bits:";
            // 
            // stopBitsLabel
            // 
            this.stopBitsLabel.AutoSize = true;
            this.stopBitsLabel.Location = new System.Drawing.Point(38, 236);
            this.stopBitsLabel.Name = "stopBitsLabel";
            this.stopBitsLabel.Size = new System.Drawing.Size(51, 15);
            this.stopBitsLabel.TabIndex = 14;
            this.stopBitsLabel.Text = "Stop Bit:";
            // 
            // parityComboBox
            // 
            this.parityComboBox.FormattingEnabled = true;
            this.parityComboBox.Items.AddRange(new object[] {
            "None",
            "Even"});
            this.parityComboBox.Location = new System.Drawing.Point(182, 175);
            this.parityComboBox.Name = "parityComboBox";
            this.parityComboBox.Size = new System.Drawing.Size(150, 23);
            this.parityComboBox.TabIndex = 15;
            this.parityComboBox.UseWaitCursor = true;
            // 
            // stopBitsComboBox
            // 
            this.stopBitsComboBox.FormattingEnabled = true;
            this.stopBitsComboBox.Items.AddRange(new object[] {
            "One",
            "Two",
            "None"});
            this.stopBitsComboBox.Location = new System.Drawing.Point(182, 233);
            this.stopBitsComboBox.Name = "stopBitsComboBox";
            this.stopBitsComboBox.Size = new System.Drawing.Size(150, 23);
            this.stopBitsComboBox.TabIndex = 16;
            // 
            // InitialForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 324);
            this.Controls.Add(this.stopBitsComboBox);
            this.Controls.Add(this.parityComboBox);
            this.Controls.Add(this.stopBitsLabel);
            this.Controls.Add(this.dataBitsLabel);
            this.Controls.Add(this.dataBitsTextBox);
            this.Controls.Add(this.parityLabel);
            this.Controls.Add(this.buadRateLabel);
            this.Controls.Add(this.baudRateTextBox);
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
        private System.Windows.Forms.TextBox baudRateTextBox;
        private System.Windows.Forms.Label buadRateLabel;
        private System.Windows.Forms.Label parityLabel;
        private System.Windows.Forms.TextBox dataBitsTextBox;
        private System.Windows.Forms.Label dataBitsLabel;
        private System.Windows.Forms.Label stopBitsLabel;
        private System.Windows.Forms.ComboBox parityComboBox;
        private System.Windows.Forms.ComboBox stopBitsComboBox;
    }
}

