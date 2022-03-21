using System;                                   // edit line : 56 , 124
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

using ScintillaNET;
using WindowsExplorer;
using System.Collections;
using Microsoft.VisualBasic;

namespace Sornram_Code_Editor
{
    public partial class Form1 : Form
    {
        public Boolean isChecked;
        public Scintilla scintilla1;
        public TabPage newTab;

        public string exampleCode;
        public string saveFileName;
        public string openFileName;
        public string openListBox;
        public string fileExtension;
        public string appDir;
        public string ccs;
        public string ccsInclude;
        public string buildResultOutput;
        public string fileListBox;
        public string perlCMD;
        public string perlCMDArgs;
        public string tabTitle;
        public string about;
        public string output;
        public string buildPath;
        public string buildResult;
        public string displayText;
        public string cmdArgs;
        public string programName = "Sornram9254 Code Editor";

        public int tabCount = 1;
        public int tabNumber = 1;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Untitled - " + programName;
            toolStripStatusLabel1.Text = "Untitled - " + Convert.ToString(tabNumber);
            setupScintilla();
        }

        private void enableBuild()
        {
            if (fileExtension == "cpp")
            {
                buildMCUToolStripMenuItem.Enabled = true;
                buildPerlToolStripMenuItem.Enabled = false;
                buildCSharpToolStripMenuItem1.Enabled = false;
            }
            else if (fileExtension == "perl")
            {
                buildMCUToolStripMenuItem.Enabled = false;
                buildPerlToolStripMenuItem.Enabled = true;
                buildCSharpToolStripMenuItem1.Enabled = false;
            }
            else if (fileExtension == "csharp")
            {
                buildMCUToolStripMenuItem.Enabled = false;
                buildPerlToolStripMenuItem.Enabled = false;
                buildCSharpToolStripMenuItem1.Enabled = true;
            }
        }

        private void setupScintilla()
        {
            //=============================================
            scintilla1 = new Scintilla();
            scintilla1.Dock = DockStyle.Fill;
            scintilla1.Name = "scintilla1";

            tabTitle = "Untitled - " + tabCount++;
            newTab = new TabPage();
            newTab.Name = "newTab";
            newTab.Text = tabTitle;
            tabControlIDE.TabPages.Add(newTab);
            newTab.Controls.Add(scintilla1);

            scintilla1.LineWrapping.Mode = LineWrappingMode.None;
            scintilla1.Margins[0].Width = 20;
            scintilla1.Styles[1].BackColor = Color.Red;
            scintilla1.Styles[2].ForeColor = Color.Red;
            scintilla1.Styles[2].Font = new Font("Times New Roman", 16, FontStyle.Italic);
            exampleCode = @"##### " + tabTitle + " #####" + Environment.NewLine +
                            "#!/usr/bin/heart" + Environment.NewLine +
                            "use heart;" + Environment.NewLine +
                            "while(true)" + Environment.NewLine +
                            "{" + Environment.NewLine +
                            "	print \"I ♥ U\";" + Environment.NewLine +
                            "	nextday();" + Environment.NewLine +
                            "}" + Environment.NewLine;
            scintilla1.Text = exampleCode;
            scintilla1.GetRange(0).SetStyle(1);
            scintilla1.GetRange(1).SetStyle(2);
            scintilla1.Margins[2].Width = 15;
            scintilla1.ConfigurationManager.Language = "perl";
            //=============================================

            appDir = Application.StartupPath;
            rightMenu();
            //=============================================
            buildMCUToolStripMenuItem.Enabled = false;
            buildPerlToolStripMenuItem.Enabled = false;
            //buildCSharpToolStripMenuItem1.Enabled = false;
            txtOutput.ReadOnly = true;
            //=============================================
            wordWarpToolStripMenuItem.Checked = false;
            //=============================================
        }
        private void tabControlIDE_Selected(object sender, TabControlEventArgs e)
        {
            tabNumber = e.TabPageIndex;
            if (saveFileName == null)
            {
                toolStripStatusLabel1.Text = "Untitled - " + Convert.ToString(tabNumber + 1);
            }
            else
            {
                toolStripStatusLabel1.Text = "Untitled - " + Convert.ToString(tabNumber + 1);
            }
        }

        //====================================================================
        //SAVE
        private void save()
        {
            if (saveFileName == null)
            {
                saveFileDialog1.Title = "Save";
                saveFileDialog1.Filter = "C files (*.c)|*.c|All files (*.*)|*.*";
                saveFileDialog1.FilterIndex = 2;

                if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    System.IO.File.WriteAllText(saveFileDialog1.FileName, scintilla1.Text);
                    saveFileName = saveFileDialog1.FileName;
                    //=============================================
                    openFileName = saveFileName;
                    Form1.ActiveForm.Text = openFileName + " - " + programName;
                    toolStripStatusLabel1.Text = saveFileName;
                    enableBuild();
                    //=============================================
                }
            }
            else
            {
                System.IO.File.WriteAllText(saveFileName, scintilla1.Text);
            }
        }
        //====================================================================
        //SAVE AS
        private void saveAs()
        {
            saveFileDialog1.Title = "Save As";
            saveFileDialog1.Filter = "C files (*.c)|*.c|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 2;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(saveFileDialog1.FileName, scintilla1.Text);
                //=============================================
                openFileName = saveFileName;
                Form1.ActiveForm.Text = openFileName + " - " + programName;
                toolStripStatusLabel1.Text = saveFileName;
                enableBuild();
                //=============================================
            }
        }

        //====================================================================
        //OPEN
        public void settingOpen()
        {

            if (fileExtension == "java" || fileExtension == "JAVA")
            {
                fileExtension = "js";
            }
            else if (fileExtension == "c" || fileExtension == "C")
            {
                fileExtension = "cpp";
            }
            else if (fileExtension == "pl" || fileExtension == "PL")
            {
                fileExtension = "perl";
            }
            else if (fileExtension == "cs" || fileExtension == "CS")
            {
                fileExtension = "csharp";
            }

            scintilla1.ConfigurationManager.Language = fileExtension;

            System.IO.StreamReader sr = new System.IO.StreamReader(openFileName);
            //===============
            if (tabControlIDE.SelectedTab.Controls.ContainsKey("scintilla1"))
            {
                scintilla1 = (Scintilla)tabControlIDE.SelectedTab.Controls["scintilla1"];
                scintilla1.Text = sr.ReadToEnd();
            }
            sr.Close();
            //=============================================
            saveFileName = openFileName;

            newTab = tabControlIDE.SelectedTab;
            tabControlIDE.Invalidate();
            newTab.Text = System.IO.Path.GetFileName(saveFileName);

            Form1.ActiveForm.Text = openFileName + " - " + programName;
            toolStripStatusLabel1.Text = openFileName;
            enableBuild();
            //=============================================
        }
        private void open()
        {
            openFileDialog1.FileName = "";
            openFileDialog1.Title = "Open";
            openFileDialog1.Filter = "C files (*.c)|*.c|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                openFileName = openFileDialog1.FileName;
                fileExtension = System.IO.Path.GetExtension(openFileName);
                fileExtension = fileExtension.Substring(1);

                settingOpen();
            }
        }
        private void scintilla1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Control && e.KeyCode == Keys.O)
            {
                open();
            }
            else if (e.Control && e.KeyCode == Keys.S)
            {
                save();
            }
            else if (e.Control && e.Alt && e.KeyCode == Keys.A)
            {
                saveAs();
            }
        }

        //====================================================================
        //File
        private void newTabToolStripMenuItem_Click(object sender, EventArgs e)
        {
            setupScintilla();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            open();
        }
        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            save();
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveAs();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //====================================================================
        //Help
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            about = @"Designed & Developed by Sornram9254" + Environment.NewLine +
                   "© Copyright 2014 - sornram9254.com" + Environment.NewLine;
            MessageBox.Show(about, "", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        //====================================================================
        //Language
        private void cToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // C
            scintilla1.ConfigurationManager.Language = "cpp";
        }

        private void csharpToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            // C#
            scintilla1.ConfigurationManager.Language = "cs";
        }

        private void cppToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // C++
            scintilla1.ConfigurationManager.Language = "cpp";
        }

        private void perlToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Perl
            scintilla1.ConfigurationManager.Language = "perl";
        }

        private void javaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // JAVA
            scintilla1.ConfigurationManager.Language = "js";
        }

        //====================================================================
        private void buildMCUToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ccs = appDir + "\\bin\\Ccsc.exe";
            ccsInclude = appDir + "\\bin\\include";
            ccs = "\"" + ccs + "\" -D -T -A -L -M -J +EA I=\"" + ccsInclude + "\" \"" + openFileName + "\"";

            Process p = new Process();
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.FileName = ccs;
            p.Start();
            output = p.StandardOutput.ReadToEnd();
            p.WaitForExit();

            buildPath = System.IO.Path.GetDirectoryName(openFileName);
            buildResult = System.IO.Path.GetFileNameWithoutExtension(openFileName);

            System.IO.StreamReader sr = new
                System.IO.StreamReader(buildPath + "\\" + buildResult + ".err");
            //MessageBox.Show(sr.ReadToEnd());
            buildResultOutput = sr.ReadToEnd();
            sr.Close();
            System.IO.File.Delete(buildPath + "\\" + buildResult + ".err");
            System.IO.File.Delete(buildPath + "\\" + buildResult + ".esym");

            txtOutput.Text = buildResultOutput;
        }
        private void copyDisplayOutput(object sender, EventArgs e)
        {
            
            txtOutput.Copy();
        }
        private void clearDisplayOutput(object sender, EventArgs e)
        {
            txtOutput.Clear();
        }
        private void selectAllDisplayOutput(object sender, EventArgs e)
        {
            txtOutput.SelectAll();
        }
        private void rightMenu()
        {
            ContextMenu mnuContextMenu = new ContextMenu();
            mnuContextMenu.MenuItems.Add("&Copy", new EventHandler(copyDisplayOutput));
            mnuContextMenu.MenuItems.Add("&Clear", new EventHandler(clearDisplayOutput));
            mnuContextMenu.MenuItems.Add("&Select All", new EventHandler(selectAllDisplayOutput));
            txtOutput.ContextMenu = mnuContextMenu;
        }

        private void buildPerl()
        {
            perlCMD = "perl";

            toolStripProgressBar1.Value = 100;
            StreamReader outputReader = null;
            ProcessStartInfo processStartInfo = new ProcessStartInfo(perlCMD, perlCMDArgs);
            processStartInfo.ErrorDialog = false;
            processStartInfo.UseShellExecute = false;
            processStartInfo.RedirectStandardError = true;
            processStartInfo.RedirectStandardInput = true;
            processStartInfo.RedirectStandardOutput = true;
            processStartInfo.CreateNoWindow = true;
            Process process = new Process();
            process.StartInfo = processStartInfo;
            bool processStarted = process.Start();
            if (processStarted)
            {
                toolStripProgressBar1.Value = 0;
                toolStripStatusLabel1.Text = "Processing...";
                timer1.Enabled = true;

                outputReader = process.StandardOutput;
                //process.WaitForExit();
                displayText = "========== Output ==========" + Environment.NewLine;
                displayText += outputReader.ReadToEnd();
                txtOutput.Text += displayText + Environment.NewLine;
            }
        }

        private void withArgsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            cmdArgs = Interaction.InputBox("Argument", "Perl Interpreter", null);
            perlCMDArgs = "\"" + openFileName + "\" " + cmdArgs;
            buildPerl();
        }

        private void noArgsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            perlCMDArgs = "\"" + openFileName + "\"";
            buildPerl();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Stop();
            toolStripStatusLabel1.Text = openFileName;
            toolStripProgressBar1.Value = toolStripProgressBar1.Maximum;
        }

        //====================================================================

        private void wordWarpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (isChecked == false)
            {
                wordWarpToolStripMenuItem.Checked = true;
                scintilla1.LineWrapping.Mode = LineWrappingMode.Word;
                isChecked = true;
            }
            else if (isChecked == true)
            {
                wordWarpToolStripMenuItem.Checked = false;
                scintilla1.LineWrapping.Mode = LineWrappingMode.None;
                isChecked = false;
            }
        }

        private void explorerTree1_PathChanged(object sender, EventArgs e)
        {
            ArrayList listFile = new ArrayList();
            string[] files = Directory.GetFiles(@"" + explorerTree1.SelectedPath + "", "*.*");
            foreach (string file in files)
            {
                fileListBox = System.IO.Path.GetFileName(file);
                listFile.Add(fileListBox);
            }
            listBox1.DataSource = listFile;
        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            openListBox = listBox1.SelectedItem.ToString();
            openFileName = explorerTree1.SelectedPath + "\\" + openListBox;
            fileExtension = System.IO.Path.GetExtension(openFileName);
            fileExtension = fileExtension.Substring(1);

            settingOpen();
        }

        private void currentFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(openFileName);
        }

        private void buildCSharpToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            dotnet frmDotnet = new dotnet();
            frmDotnet.ShowDialog();
            string dotnet_ver = frmDotnet.dotnet_ver;
            //string inputFile = tabControlIDE.SelectedTab.Text;
            string inputFile = openFileName;
            string outputFile = inputFile + ".exe";
            if (dotnet_ver != null)
            {
                Process p = new Process();
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.FileName = dotnet_ver + @"\csc.exe";
                p.StartInfo.Arguments = "/out:" + outputFile + " " + inputFile + "";
                p.Start();
                output = p.StandardOutput.ReadToEnd();
                p.WaitForExit();

                txtOutput.Text = output;
            }
        }
    }
}
