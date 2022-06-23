using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L4z1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        bool zawodnikX = true;
        int ruch = 0;
        bool wygrana = false;
        Button[] all = new Button[9];
        int CPUwybranePole = -1;
        bool tryb = false;
        String winer = "nikt";
        private void Form1_Load(object sender, EventArgs e)
        {
            ruch = 0;
            all[0] = b1;
            all[1] = b2;
            all[2] = b3;
            all[3] = b4;
            all[4] = b5;
            all[5] = b6;
            all[6] = b7;
            all[7] = b8;
            all[8] = b9;
            foreach (Button b in all)
            {
                b.Enabled = true;
                b.Text = "";
            }
        }

        private void bNowaGra_Click(object sender, EventArgs e)
        {
            NowaGra();
            bNowaGra.Text = "Nowa Giera";
            kto.Text = "X";
            zawodnikX = true;
        }
        public void czyjRuch()
        {
            if (!zawodnikX) ruchCPU();
            //if (kto.Text == "O") ruchCPU();
           // MessageBox.Show("kto.Text", kto.Text, MessageBoxButtons.OK, MessageBoxIcon.Warning);

        }
        private void NowaGra()
        {
            ruch = 0;           
            all[0] = b1;
            all[1] = b2;
            all[2] = b3;
            all[3] = b4;
            all[4] = b5;
            all[5] = b6;
            all[6] = b7; 
            all[7] = b8;
            all[8] = b9;
            foreach(Button b in all)
            {
                b.Enabled = true;
                b.Text = "";
            }
        }
        private void Czek()
        {
            if (b1.Text != "" && b1.Text == b2.Text && b2.Text == b3.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b4.Text != "" && b4.Text == b5.Text && b5.Text == b6.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b7.Text != "" && b7.Text == b8.Text && b8.Text == b9.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b1.Text != "" && b1.Text == b4.Text && b4.Text == b7.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b2.Text != "" && b2.Text == b5.Text && b5.Text == b8.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b3.Text != "" && b3.Text == b6.Text && b9.Text == b6.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b1.Text != "" && b1.Text == b5.Text && b5.Text == b9.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (b3.Text != "" && b3.Text == b5.Text && b5.Text == b7.Text)
            {
                winer = kto.Text;
                WinWIn();
                return;
            }
            else if (ruch==9)
            {
                MessageBox.Show("Remisik", "Remisik", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
             //czyjRuch();
        }

        private void WinWIn()
        {
            MessageBox.Show("Wygraniusia zawodnika: " + kto.Text, "Wygraniusia", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            wygrana = true;
            bNowaGra.PerformClick();
            return;
        }

        private void b1_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if(ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 1";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            czyjRuch();
        }


        private void b2_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 2";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if(tryb) czyjRuch();
        }

        private void b3_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 3";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b4_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 4";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b5_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 5";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b6_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 6";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b7_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 7";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b8_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 8";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void b9_Click(object sender, EventArgs e)
        {
            ruch++;
            ((Button)sender).Text = zawodnikX ? "X" : "O";
            ((Button)sender).Enabled = false;
            if (ruch >= 5)
            {
                Czek();
            }
            textBox1.Text += "Zawodnik " + kto.Text + " wykonał ruch na pole nr: 9";
            zawodnikX = !zawodnikX;
            kto.Text = zawodnikX ? "X" : "O";
            if (tryb) czyjRuch();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            tryb = false;
        }
        public void ruchCPU()
        {
            Random rnd = new Random();
            String znakCPU = "O";
            int wyznacznik = 0;
            int czyPoleWolne = -1;
            
                if (kto.Text == "O")
                {
                    while (true)
                    {
                        if (all[4].Enabled == true) { all[4].PerformClick(); break; };
                        czyPoleWolne = rnd.Next(8);
                    czyCzWygra();
                        if (all[czyPoleWolne].Enabled == true) { all[czyPoleWolne].PerformClick(); break; };
                    }
                // while(all[CPUwybranePole].Enabled == false)
                //     CPUwybranePole = rnd.Next(8) ;
                }

           // zawodnikX = !zawodnikX;
           // kto.Text = zawodnikX ? "X" : "O";

        }

        private void czyCzWygra()
        {
            
        }

        private async void CZvsCPU_CheckedChanged(object sender, EventArgs e)
        {
            tryb = true;
            if(!zawodnikX) ruchCPU();
            //MessageBox.Show("CZvsCPU_CheckedChanged", "CZvsCPU_CheckedChanged", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
        private void czyCPUWygra()
        {
            if (b1.Text != "" && b1.Text == b2.Text && b2.Text == b3.Text)
            {
                
            }
            else if (b4.Text != "" && b4.Text == b5.Text && b5.Text == b6.Text)
            {
                
            }
            else if (b7.Text != "" && b7.Text == b8.Text && b8.Text == b9.Text)
            {
                
            }
            else if (b1.Text != "" && b1.Text == b4.Text && b4.Text == b7.Text)
            {
                
            }
            else if (b2.Text != "" && b2.Text == b5.Text && b5.Text == b8.Text)
            {
                
            }
            else if (b3.Text != "" && b3.Text == b6.Text && b9.Text == b6.Text)
            {
                
            }
            else if (b1.Text != "" && b1.Text == b5.Text && b5.Text == b9.Text)
            {
                
            }
            else if (b3.Text != "" && b3.Text == b5.Text && b5.Text == b7.Text)
            {
               
            }
            else if (ruch == 9)
            {
                MessageBox.Show("Remisik", "Remisik", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

    }
}
