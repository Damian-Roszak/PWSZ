using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Speech.Synthesis;

namespace L4z2
{
    public partial class Form1 : Form
    {
        //public static Form1 f1;
        public Form1()
        {
            InitializeComponent();
           // f1 = this;
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void folderBrowserDialog1_HelpRequest(object sender, EventArgs e)
        {

        }

        private void otwórzToolStripButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog openfile = new OpenFileDialog();
            openfile.Title = "Otwieracz pliczkowskiego";
            if (openfile.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Clear();
                using (StreamReader sr = new StreamReader(openfile.FileName))
                {
                    richTextBox1.Text = sr.ReadToEnd();
                    sr.Close();
                }
            }
        }

        private void nowyToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
        }

        private void zapiszToolStripButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog zapiszPlik = new SaveFileDialog();
            zapiszPlik.Title = "Zapisz plik jako...";
            if (zapiszPlik.ShowDialog() == DialogResult.OK) 
            {
                StreamWriter txtNaZew = new StreamWriter(zapiszPlik.FileName);
                txtNaZew.Write(richTextBox1.Text);
                txtNaZew.Close();
            }
        }

        private void drukujToolStripButton_Click(object sender, EventArgs e)
        {
           
        }

        private void wytnijToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void kopiujToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void wklejToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            richTextBox1.Undo();
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            richTextBox1.Redo();
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectAll();
        }

        private void nowyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            nowyToolStripButton.PerformClick();
        }

        private void otwórzToolStripMenuItem_Click(object sender, EventArgs e)
        {
            otwórzToolStripButton.PerformClick();
        }

        private void zapiszjakoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            zapiszToolStripButton.PerformClick();
        }

        private void zakończToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void cofnijToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripButton1.PerformClick();
        }

        private void ponówToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripButton2.PerformClick();
        }

        private void wytnijToolStripMenuItem_Click(object sender, EventArgs e)
        {
            wytnijToolStripButton.PerformClick();
        }

        private void kopiujToolStripMenuItem_Click(object sender, EventArgs e)
        {
            kopiujToolStripButton.PerformClick();
        }

        private void wklejToolStripMenuItem_Click(object sender, EventArgs e)
        {
            wklejToolStripButton.PerformClick();
        }

        private void zaznaczwszystkoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripButton3.PerformClick();
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            richTextBox1.SelectionFont = fontDialog1.Font;
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            richTextBox1.SelectionColor = colorDialog1.Color;
        }

        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            SpeechSynthesizer głos = new SpeechSynthesizer();
            głos.SelectVoiceByHints(VoiceGender.Male);
            głos.SpeakAsync(richTextBox1.Text);
        }

        private void toolStripButton7_Click(object sender, EventArgs e)
        {
            SpeechSynthesizer głos1 = new SpeechSynthesizer();
            głos1.SelectVoiceByHints(VoiceGender.Female);
            głos1.SpeakAsync(richTextBox1.Text);
        }

        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            int start = 0;
            int end = richTextBox1.Text.LastIndexOf(textBox1.Text);

            richTextBox1.SelectAll();
            richTextBox1.SelectionBackColor = Color.Black;
            while (start < end)
            {
                richTextBox1.Find(textBox1.Text, start, richTextBox1.TextLength, RichTextBoxFinds.MatchCase);
                richTextBox1.SelectionBackColor = Color.Yellow;
                start = richTextBox1.Text.IndexOf(textBox1.Text, start) + 1;
            }
                         


        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            ZnajdźZmień f2 = new ZnajdźZmień(this);
            f2.ShowDialog();
           
            
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void Form1_Load(object sender, EventArgs e)
        {
            otwórzToolStripButton.PerformClick();
        }
    }
}
