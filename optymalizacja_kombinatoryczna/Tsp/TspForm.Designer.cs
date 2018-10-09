//////////////////////////////////////////////////////////////////////////////////////////////////
// File Name: Tsp.Form.Designer.cs
//      Date: 06/01/2006
// Copyright (c) 2006 Michael LaLena. All rights reserved.
// Permission to use, copy, modify, and distribute this Program and its documentation,
//  if any, for any purpose and without fee is hereby granted, provided that:
//   (i) you not charge any fee for the Program, and the Program not be incorporated
//       by you in any software or code for which compensation is expected or received;
//   (ii) the copyright notice listed above appears in all copies;
//   (iii) both the copyright notice and this Agreement appear in all supporting documentation; and
//   (iv) the name of Michael LaLena or lalena.com not be used in advertising or publicity
//          pertaining to distribution of the Program without specific, written prior permission. 
///////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tsp
{
    partial class TspForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tourDiagram = new System.Windows.Forms.PictureBox();
            this.populationSizeTextBox = new System.Windows.Forms.TextBox();
            this.PopulationSizeLabel = new System.Windows.Forms.Label();
            this.lastIterationLabel = new System.Windows.Forms.Label();
            this.lastIterationValue = new System.Windows.Forms.Label();
            this.lastTourLabel = new System.Windows.Forms.Label();
            this.lastFitnessValue = new System.Windows.Forms.Label();
            this.StartButton = new System.Windows.Forms.Button();
            this.fileNameLabel = new System.Windows.Forms.Label();
            this.fileNameTextBox = new System.Windows.Forms.TextBox();
            this.maxGenerationLabel = new System.Windows.Forms.Label();
            this.maxGenerationTextBox = new System.Windows.Forms.TextBox();
            this.openCityListButton = new System.Windows.Forms.Button();
            this.StatusLabel = new System.Windows.Forms.Label();
            this.selectFileButton = new System.Windows.Forms.Button();
            this.mutationTextBox = new System.Windows.Forms.TextBox();
            this.mutationLabel = new System.Windows.Forms.Label();
            this.NumberCitiesLabel = new System.Windows.Forms.Label();
            this.NumberCitiesValue = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.tourDiagram)).BeginInit();
            this.SuspendLayout();
            // 
            // tourDiagram
            // 
            this.tourDiagram.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tourDiagram.BackColor = System.Drawing.Color.White;
            this.tourDiagram.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.tourDiagram.Location = new System.Drawing.Point(12, 28);
            this.tourDiagram.Name = "tourDiagram";
            this.tourDiagram.Size = new System.Drawing.Size(500, 500);
            this.tourDiagram.TabIndex = 0;
            this.tourDiagram.TabStop = false;
            // 
            // populationSizeTextBox
            // 
            this.populationSizeTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.populationSizeTextBox.Location = new System.Drawing.Point(706, 56);
            this.populationSizeTextBox.Name = "populationSizeTextBox";
            this.populationSizeTextBox.Size = new System.Drawing.Size(116, 21);
            this.populationSizeTextBox.TabIndex = 1;
            this.populationSizeTextBox.Text = "10000";
            // 
            // PopulationSizeLabel
            // 
            this.PopulationSizeLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.PopulationSizeLabel.AutoSize = true;
            this.PopulationSizeLabel.Location = new System.Drawing.Point(706, 40);
            this.PopulationSizeLabel.Name = "PopulationSizeLabel";
            this.PopulationSizeLabel.Size = new System.Drawing.Size(94, 13);
            this.PopulationSizeLabel.TabIndex = 0;
            this.PopulationSizeLabel.Text = "Population Size";
            // 
            // lastIterationLabel
            // 
            this.lastIterationLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lastIterationLabel.AutoSize = true;
            this.lastIterationLabel.Location = new System.Drawing.Point(12, 602);
            this.lastIterationLabel.Name = "lastIterationLabel";
            this.lastIterationLabel.Size = new System.Drawing.Size(92, 13);
            this.lastIterationLabel.TabIndex = 0;
            this.lastIterationLabel.Text = "Last Iteration: ";
            // 
            // lastIterationValue
            // 
            this.lastIterationValue.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lastIterationValue.Location = new System.Drawing.Point(109, 602);
            this.lastIterationValue.Name = "lastIterationValue";
            this.lastIterationValue.Size = new System.Drawing.Size(117, 13);
            this.lastIterationValue.TabIndex = 0;
            // 
            // lastTourLabel
            // 
            this.lastTourLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lastTourLabel.AutoSize = true;
            this.lastTourLabel.Location = new System.Drawing.Point(232, 602);
            this.lastTourLabel.Name = "lastTourLabel";
            this.lastTourLabel.Size = new System.Drawing.Size(106, 13);
            this.lastTourLabel.TabIndex = 0;
            this.lastTourLabel.Text = "Last Tour Length:";
            // 
            // lastFitnessValue
            // 
            this.lastFitnessValue.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lastFitnessValue.Location = new System.Drawing.Point(349, 602);
            this.lastFitnessValue.Name = "lastFitnessValue";
            this.lastFitnessValue.Size = new System.Drawing.Size(85, 13);
            this.lastFitnessValue.TabIndex = 0;
            // 
            // StartButton
            // 
            this.StartButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.StartButton.Location = new System.Drawing.Point(726, 436);
            this.StartButton.Name = "StartButton";
            this.StartButton.Size = new System.Drawing.Size(87, 34);
            this.StartButton.TabIndex = 10;
            this.StartButton.Text = "Start";
            this.StartButton.UseVisualStyleBackColor = true;
            this.StartButton.Click += new System.EventHandler(this.StartButton_Click);
            // 
            // fileNameLabel
            // 
            this.fileNameLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.fileNameLabel.AutoSize = true;
            this.fileNameLabel.Location = new System.Drawing.Point(710, 308);
            this.fileNameLabel.Name = "fileNameLabel";
            this.fileNameLabel.Size = new System.Drawing.Size(109, 13);
            this.fileNameLabel.TabIndex = 0;
            this.fileNameLabel.Text = "Instance filename";
            // 
            // fileNameTextBox
            // 
            this.fileNameTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.fileNameTextBox.Location = new System.Drawing.Point(706, 324);
            this.fileNameTextBox.Name = "fileNameTextBox";
            this.fileNameTextBox.Size = new System.Drawing.Size(116, 21);
            this.fileNameTextBox.TabIndex = 6;
            this.fileNameTextBox.Text = "tsp.txt";
            // 
            // maxGenerationLabel
            // 
            this.maxGenerationLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.maxGenerationLabel.AutoSize = true;
            this.maxGenerationLabel.Location = new System.Drawing.Point(706, 152);
            this.maxGenerationLabel.Name = "maxGenerationLabel";
            this.maxGenerationLabel.Size = new System.Drawing.Size(135, 13);
            this.maxGenerationLabel.TabIndex = 0;
            this.maxGenerationLabel.Text = "Maximum Generations";
            // 
            // maxGenerationTextBox
            // 
            this.maxGenerationTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.maxGenerationTextBox.Location = new System.Drawing.Point(706, 167);
            this.maxGenerationTextBox.Name = "maxGenerationTextBox";
            this.maxGenerationTextBox.Size = new System.Drawing.Size(116, 21);
            this.maxGenerationTextBox.TabIndex = 4;
            this.maxGenerationTextBox.Text = "10000000";
            // 
            // openCityListButton
            // 
            this.openCityListButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.openCityListButton.Location = new System.Drawing.Point(707, 378);
            this.openCityListButton.Name = "openCityListButton";
            this.openCityListButton.Size = new System.Drawing.Size(113, 23);
            this.openCityListButton.TabIndex = 8;
            this.openCityListButton.Text = "Open City List";
            this.openCityListButton.UseVisualStyleBackColor = true;
            this.openCityListButton.Click += new System.EventHandler(this.openCityListButton_Click);
            // 
            // StatusLabel
            // 
            this.StatusLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.StatusLabel.Location = new System.Drawing.Point(14, 627);
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(422, 13);
            this.StatusLabel.TabIndex = 9;
            this.StatusLabel.Text = "Open a City List or click the map to place cities.";
            // 
            // selectFileButton
            // 
            this.selectFileButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.selectFileButton.Location = new System.Drawing.Point(707, 349);
            this.selectFileButton.Name = "selectFileButton";
            this.selectFileButton.Size = new System.Drawing.Size(113, 23);
            this.selectFileButton.TabIndex = 7;
            this.selectFileButton.Text = "Browse";
            this.selectFileButton.UseVisualStyleBackColor = true;
            this.selectFileButton.Click += new System.EventHandler(this.selectFileButton_Click);
            // 
            // mutationTextBox
            // 
            this.mutationTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.mutationTextBox.Location = new System.Drawing.Point(706, 94);
            this.mutationTextBox.Name = "mutationTextBox";
            this.mutationTextBox.Size = new System.Drawing.Size(116, 21);
            this.mutationTextBox.TabIndex = 2;
            this.mutationTextBox.Text = "3";
            // 
            // mutationLabel
            // 
            this.mutationLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.mutationLabel.AutoSize = true;
            this.mutationLabel.Location = new System.Drawing.Point(706, 80);
            this.mutationLabel.Name = "mutationLabel";
            this.mutationLabel.Size = new System.Drawing.Size(71, 13);
            this.mutationLabel.TabIndex = 10;
            this.mutationLabel.Text = "Mutation %";
            // 
            // NumberCitiesLabel
            // 
            this.NumberCitiesLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.NumberCitiesLabel.Location = new System.Drawing.Point(724, 625);
            this.NumberCitiesLabel.Name = "NumberCitiesLabel";
            this.NumberCitiesLabel.Size = new System.Drawing.Size(64, 13);
            this.NumberCitiesLabel.TabIndex = 12;
            this.NumberCitiesLabel.Text = "# Cities: ";
            // 
            // NumberCitiesValue
            // 
            this.NumberCitiesValue.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.NumberCitiesValue.Location = new System.Drawing.Point(786, 626);
            this.NumberCitiesValue.Name = "NumberCitiesValue";
            this.NumberCitiesValue.Size = new System.Drawing.Size(48, 13);
            this.NumberCitiesValue.TabIndex = 13;
            // 
            // TspForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(842, 649);
            this.Controls.Add(this.NumberCitiesValue);
            this.Controls.Add(this.NumberCitiesLabel);
            this.Controls.Add(this.mutationTextBox);
            this.Controls.Add(this.mutationLabel);
            this.Controls.Add(this.selectFileButton);
            this.Controls.Add(this.StatusLabel);
            this.Controls.Add(this.openCityListButton);
            this.Controls.Add(this.maxGenerationTextBox);
            this.Controls.Add(this.maxGenerationLabel);
            this.Controls.Add(this.fileNameTextBox);
            this.Controls.Add(this.fileNameLabel);
            this.Controls.Add(this.StartButton);
            this.Controls.Add(this.lastFitnessValue);
            this.Controls.Add(this.lastTourLabel);
            this.Controls.Add(this.lastIterationValue);
            this.Controls.Add(this.lastIterationLabel);
            this.Controls.Add(this.PopulationSizeLabel);
            this.Controls.Add(this.populationSizeTextBox);
            this.Controls.Add(this.tourDiagram);
            this.Font = new System.Drawing.Font("Verdana", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "TspForm";
            this.Text = "Traveling Salesman Problem";
            ((System.ComponentModel.ISupportInitialize)(this.tourDiagram)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox tourDiagram;
        private System.Windows.Forms.TextBox populationSizeTextBox;
        private System.Windows.Forms.Label PopulationSizeLabel;
        private System.Windows.Forms.Label lastIterationLabel;
        private System.Windows.Forms.Label lastIterationValue;
        private System.Windows.Forms.Label lastTourLabel;
        private System.Windows.Forms.Label lastFitnessValue;
        private System.Windows.Forms.Button StartButton;
        private System.Windows.Forms.Label fileNameLabel;
        private System.Windows.Forms.TextBox fileNameTextBox;
        private System.Windows.Forms.Label maxGenerationLabel;
        private System.Windows.Forms.TextBox maxGenerationTextBox;
        private System.Windows.Forms.Button openCityListButton;
        private System.Windows.Forms.Label StatusLabel;
        private System.Windows.Forms.Button selectFileButton;
        private System.Windows.Forms.TextBox mutationTextBox;
        private System.Windows.Forms.Label mutationLabel;
        private System.Windows.Forms.Label NumberCitiesLabel;
        private System.Windows.Forms.Label NumberCitiesValue;
    }
}

