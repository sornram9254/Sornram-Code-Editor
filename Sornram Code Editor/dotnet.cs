using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Sornram_Code_Editor
{
    public partial class dotnet : Form
    {
        string currSelect;
        //public string dotnet_ver { get; set; }
        public string dotnet_ver
        {
            get { return currSelect; }
        }

        public dotnet()
        {
            InitializeComponent();
        }

        private void dotnet_Load(object sender, EventArgs e)
        {
            string path = Environment.ExpandEnvironmentVariables(@"%windir%\Microsoft.NET\Framework");
            if (Directory.Exists(path))
            {
                var pathList = new List<string>();
                foreach (string element in Directory.GetDirectories(path))
                {
                    pathList.Add(element);
                }
                var pathArr = pathList.ToArray();

                for (int i = 0; i < pathArr.Length; i++)
                {
                    cbDotNetList.Items.Add(pathArr[i]);
                }
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void cbDotNetList_SelectedIndexChanged(object sender, EventArgs e)
        {
            currSelect = cbDotNetList.SelectedItem.ToString();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            currSelect = null;
            this.Close();
        }
    }
}
