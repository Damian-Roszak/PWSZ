using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L3z2
{
    public partial class Form1 : Form
    {
        Graphics g = null;
        Pen myPen = new Pen(Color.Yellow);
        public class Punkt
        {
            public double x;
            public double y;
            public void setPkt(double xx, double yy) { x = xx; y = yy; }
            public Punkt() { }
            public Punkt (double xx, double yy) { x = xx; y = yy; }
            public void rysuj(Graphics g)
            {

            }
            public void rysujPunkt(Graphics g, int xPx, int yPy)
            {
                // Punkt
                Brush myPenPunkt = new SolidBrush(Color.LightCyan);
                //myPenPunkt.Width = 10;
                g.FillEllipse(myPenPunkt, xPx, yPy, 10F, 10F);

                //Napis
                String s = "PUNKT";
                Font font = new Font("Arial", 20);
                SolidBrush brasz = new SolidBrush(Color.Wheat);
                PointF pkt = new PointF((float)xPx+7, (float)yPy);
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s, font, brasz, pkt, format);

            }
        }
        public class Koło
        {
            public Punkt środek;
            public double promień;
            public  Koło(double xx, double yy, double r)
            { 
                środek = new Punkt(xx, yy);
                promień = r;
            }
            public void rysujKoło(Graphics g)
            {
                Pen myPenKoło = new Pen(Color.HotPink);
                myPenKoło.Width = 3;
                g.DrawEllipse(myPenKoło, (int)(środek.x - promień), (int)(środek.y - promień), 2* (int)promień,  2 * (int)promień);
                // g.DrawEllipse(myPenKoło, 10, 10, 200, 200);
                
                //Napis
                String s = "KOŁO";
                Font font = new Font("Arial", 20);
                SolidBrush brasz = new SolidBrush(Color.Wheat);
                PointF pkt = new PointF((float)środek.x, (float)środek.y);
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s, font, brasz, pkt, format);
            }

        }
        public class Trójkąt 
        {
            public Punkt wsp1;
            public Punkt wsp2;
            public Punkt wsp3;
            public string typ;
            public Trójkąt() { }
            public Trójkąt(Punkt pkt1, Punkt pkt2, Punkt pkt3 ) 
            {
                wsp1 = pkt1;     wsp2 = pkt2;     wsp3 = pkt3; 
            }
            public void rysRozwartokątny(Graphics g)
            {
                int gru = 5;
                Pen pen1 = new Pen(Color.LightGreen);
                pen1.Width = gru;
                g.DrawLine(pen1, 800, 900, 1200, 900);
                Pen pen2 = new Pen(Color.Red);
                pen2.Width = gru;
                g.DrawLine(pen1, 800, 900, 500, 700);
                Pen pen3 = new Pen(Color.LightSeaGreen);
                pen3.Width = gru;
                g.DrawLine(pen1, 500, 700, 1200, 900);
                //Napis
                String s = "==TRÓJKĄT Rozwartokątny==";
                Font font = new Font("Arial", 20);
                SolidBrush brasz = new SolidBrush(Color.Yellow);
                PointF pkt = new PointF(800.0F, 920.0F);
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s, font, brasz, pkt, format);

            }
            public void rysProstokątny(Graphics g)
            {
                int gru = 5;
                Pen pen1 = new Pen(Color.LightGreen);
                pen1.Width = gru;
                g.DrawLine(pen1, 200, 800, 200, 1000);
                Pen pen2 = new Pen(Color.Red);
                pen2.Width = gru;
                g.DrawLine(pen1, 200, 1000, 600, 1000);
                Pen pen3 = new Pen(Color.LightSeaGreen);
                pen3.Width = gru;
                g.DrawLine(pen1, 600, 1000, 200, 800);
                //Napis
                String s = "==TRÓJKĄT Prostokątny==";
                Font font = new Font("Arial", 20);
                SolidBrush brasz = new SolidBrush(Color.Yellow);
                PointF pkt = new PointF(230.0F, 800.0F);
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s, font, brasz, pkt, format);

            }
            public void rysRównoramienny(Graphics g)
            {
                int gru = 5;
                Pen pen1 = new Pen(Color.LightGreen);
                pen1.Width = gru;               
                g.DrawLine(pen1, 800, 100, 1200, 100);
                Pen pen2 = new Pen(Color.Red);
                pen2.Width = gru;
                g.DrawLine(pen1, 800, 100, 1000, 700);
                Pen pen3 = new Pen(Color.LightSeaGreen);
                pen3.Width = gru;
                g.DrawLine(pen1, 1000, 700, 1200, 100);
                //Napis
                String s = "==TRÓJKĄT Równoramienny==";
                Font font = new Font("Arial", 20);
                SolidBrush brasz = new SolidBrush(Color.Yellow);
                PointF pkt = new PointF(800.0F, 60.0F);
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s, font, brasz, pkt, format);
                
            }
            public void rysuj(Graphics g)
            {     

                //Napis
                String s1 = "TRÓJKĄT - Punkty Modyfikowalne";
                Font font1 = new Font("Arial", 20);
                SolidBrush brasz1 = new SolidBrush(Color.Yellow);
                PointF pkt1 = new PointF((float)wsp1.x, (float)wsp1.y);
                
                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s1, font1, brasz1, pkt1, format);
                ////Trrójkąt 
                Pen myPenTrójkąt = new Pen(Color.GreenYellow);
                myPenTrójkąt.Width = 3;
                Point[] punkty =
                {
                    new Point( (int)wsp1.x, (int)wsp1.y),
                    new Point((int)wsp2.x, (int)wsp2.y),
                    new Point((int)wsp3.x, (int)wsp3.y),
                    new Point( (int)wsp1.x, (int)wsp1.y)
                };
                               
                g.DrawLines(myPenTrójkąt, punkty);
            }
            public void rysujTypTrójkąta()
            {
                
            }
        }

        public class Wielobok 
        {
            Punkt[] wierzch;
            public Wielobok() { }
            public Wielobok(Punkt p1, Punkt p2, Punkt p3, Punkt p4, Punkt p5) {
                wierzch = new Punkt[5];
                wierzch[0] = p1; wierzch[1] = p2; wierzch[2] = p3; wierzch[3] = p4; wierzch[4] = p5;
            }
            public void rysujWielobok(Graphics g)
            {

                //Napis
                String s1 = "WIELOBOK";
                Font font1 = new Font("Arial", 20);
                SolidBrush brasz1 = new SolidBrush(Color.Yellow);
                PointF pkt1 = new PointF((float)wierzch[0].x, (float)wierzch[0].y);

                StringFormat format = new StringFormat();
                format.FormatFlags = StringFormatFlags.NoFontFallback;
                g.DrawString(s1, font1, brasz1, pkt1, format);
                ////WIELOBOK 
                Pen myPenW = new Pen(Color.Orange);
                myPenW.Width = 3;
                Point[] punkty =
                {
                    new Point( (int)wierzch[0].x, (int)wierzch[0].y),
                    new Point((int)wierzch[1].x, (int)wierzch[1].y),
                    new Point((int)wierzch[2].x, (int)wierzch[2].y),
                    new Point( (int)wierzch[3].x, (int)wierzch[3].y),
                    new Point( (int)wierzch[4].x, (int)wierzch[4].y),
                    new Point( (int)wierzch[0].x, (int)wierzch[0].y)
                };

                g.DrawLines(myPenW, punkty);
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }
        public void napisRysuj(String s, Color c, int x, int y)
        {
            Font font = new Font("Arial", 20);
            SolidBrush brasz = new SolidBrush(c);
            PointF pkt = new PointF((float)x, (float)y);
            StringFormat format = new StringFormat();
            format.FormatFlags = StringFormatFlags.NoFontFallback;
            g.DrawString(s, font, brasz, pkt, format);
        }
        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            pictureBox1.BackColor = Color.Black;
            myPen.Width = 3;
            Brush myBrush = new SolidBrush(Color.Yellow);
           // g.FillEllipse(myBrush, 10, 10, 100, 100);
           // napisRysuj("Słoneczko", Color.Red, 10, 10);

           
            //g = pictureBox1.CreateGraphics();
            Punkt p = new Punkt(300, 100);
            Punkt p1 = new Punkt(12, 456);
            Punkt p2 = new Punkt(50, 300);

            //rysujPunkt
            Punkt pktZad = new Punkt();
            int p1x = int.Parse(boxX.Text);
            int p1y = int.Parse(boxY.Text);
            pktZad.rysujPunkt(g, p1x, p1y);

            //======== KOŁO
            int kołoŚrodekX = int.Parse(textBox4.Text);
            int kołoŚrodekY = int.Parse(textBox3.Text);
            int kołoPromień = int.Parse(textBox2.Text);
            Koło koło = new Koło(kołoŚrodekX, kołoŚrodekY, kołoPromień);
            koło.rysujKoło(g);

            //=== TRÓJKĄT
            Punkt qTr = new Punkt(double.Parse(textBox10.Text), double.Parse(textBox8.Text));
            Punkt rTr = new Punkt(double.Parse(textBox9.Text), double.Parse(textBox7.Text));
            Punkt sTr = new Punkt(double.Parse(textBox6.Text), double.Parse(textBox1.Text));
            Trójkąt trPrzykład = new Trójkąt(qTr, rTr, sTr);
            trPrzykład.rysuj(g);

            // ===== TRÓJKĄT TYP =================
            if (comboBox1.Text == "Równoramienny")
            {
                Trójkąt równoramienny = new Trójkąt();
                równoramienny.rysRównoramienny(g);
            }
            else if (comboBox1.Text == "Prostokątny")
            {
                Trójkąt prostokątny = new Trójkąt();
                prostokątny.rysProstokątny(g);
            }
            else if (comboBox1.Text == "Rozwartokątny")
            {
                Trójkąt rozwartokątny = new Trójkąt();
                rozwartokątny.rysRozwartokątny(g);
            }

            //Napis 
            p1.x = double.Parse(pktX1.Text);
            p1.y = double.Parse(pktY1.Text);
            p2.x = double.Parse(pktX2.Text);
            p2.y = double.Parse(pktY2.Text);

            String s = "Prosta";
            Font font = new Font("Arial", 20);
            SolidBrush brasz = new SolidBrush(Color.Yellow);
            PointF pkt = new PointF((float)p1.x, (float)p1.y);
            StringFormat format = new StringFormat();
            format.FormatFlags = StringFormatFlags.NoFontFallback;
            g.DrawString(s, font, brasz, pkt, format);
            g.DrawLine(myPen, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);

            //Wielobok
            Punkt w1 = new Punkt(double.Parse(textBox15.Text), double.Parse(textBox13.Text));
            Punkt w2 = new Punkt(double.Parse(textBox14.Text), double.Parse(textBox12.Text));
            Punkt w3 = new Punkt(double.Parse(textBox11.Text), double.Parse(textBox5.Text));
            Punkt w4 = new Punkt(double.Parse(textBox19.Text), double.Parse(textBox18.Text));
            Punkt w5 = new Punkt(double.Parse(textBox17.Text), double.Parse(textBox16.Text));

            Wielobok W = new Wielobok(w1, w2, w3, w4, w5);
            W.rysujWielobok(g);

        }

        public void rysujLinie(Punkt p1, Punkt p2)
        {

            g.DrawLine(myPen, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
        }//koniec rysuj()

        private void button1_Click(object sender, EventArgs e)
        {
             Punkt p1 = new Punkt();
             Punkt p2 = new Punkt();

            p1.x = double.Parse(pktX1.Text);
            p1.y = double.Parse(pktY1.Text);
            p2.x = double.Parse(pktX2.Text);
            p2.y = double.Parse(pktY2.Text);

            /*
            Graphics g = e.Graphics;
            Pen ziel = new Pen(Color.Green);
            Punkt p1 = new Punkt(200, 200);
            Punkt p2 = new Punkt(400, 400);
            g.DrawLine(ziel, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
            */

            pictureBox1.Refresh();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }

        private void boxX_TextChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click_1(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            

        }

        private void textBox18_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
