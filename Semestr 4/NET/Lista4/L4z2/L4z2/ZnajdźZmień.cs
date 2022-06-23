using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L4z2
{
    public partial class ZnajdźZmień : Form
    {
        Form1 f1;
        public ZnajdźZmień(Form1 frm1)
        {
            InitializeComponent();
            this.f1 = frm1;
        }

        private void ZnajdźZmień_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            f1.richTextBox1.Text =  f1.richTextBox1.Text.Replace(textBox1.Text, textBox2.Text);
            
        }
    }
}
