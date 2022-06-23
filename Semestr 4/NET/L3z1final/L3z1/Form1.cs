using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace L3z1
{
    public partial class Form1 : Form
    {
        public abstract class Samochody
        {
            public  string marka;
            public string kolor;
            public double cena;
            public string model;
            public int pojSilnika;
            //public void setMarka(string m) { marka = m; }
            public Samochody(string m, string k, double c, string mo, int p) 
            { 
                marka = m; kolor = k; cena = c; model = mo; pojSilnika = p;
            }
            public virtual string Pisz()
            {
                return "Marka: " + this.marka + "\nKolor: " + this.kolor + "\nCena: " + this.cena.ToString("C")
                     + "\nModel: " + this.model + "\nPoj. Sil: " + this.pojSilnika+" L\n\n";
            }
        }
        public class Terenowy : Samochody
        {
            public string napęd { get; set; }
            public int moc;
            public string dodatkoweOśw;
            public int prześwit;
            public string homologacjaCiężarowa;
            //public void setNapęd(string m) { napęd = m; }

            public Terenowy(string m, string k, double c, string mo, int p, string n, int power, string dodOś, 
                int prze, string hom): base(m,k,c,mo,p)
            { 
                    napęd = n; dodatkoweOśw = dodOś; 
                   moc = power; prześwit = prze; homologacjaCiężarowa = hom;
            }
            public string pokaBaze()
            {
                return "Terenowy pokaBaze";
            }
            public override string Pisz()
            {
                return  base.Pisz()+"\nNapęd: " + napęd + " "  + "\nDod. Ośw: " + this.dodatkoweOśw + "\nMoc: "
                    + this.moc + "KM\nPrześwit: " + this.prześwit + "cm\nHom. Cięż: " + this.homologacjaCiężarowa;
            }
        }
        public class Sportowy : Samochody
        {
            public string nitro;
            public int moc;
            public double przyspiesz;
            public string hamulce;
            public string tunning;
            //public void setNapęd(string m) { napęd = m; }

            public Sportowy(string m, string k, double c, string mo, int p, string n, int power, double a, string ham, 
                string t) : base(m, k, c, mo, p) 
            {
                nitro = n; moc = power; przyspiesz = a; hamulce = ham; tunning = t;
            }
            public string pokaBaze()
            {
                return "Sportowy pokaBaze";
            }
            public override string Pisz()
            {
                return base.Pisz() + "\nMoc: " + moc + "KM\nNitro: " + nitro + "\n0-100km/h: " + przyspiesz 
                    + "s\nhamulce: " + hamulce + "\ntunning: " + tunning;
            }
        }
        public class Rodzinny : Samochody
        {
            public string nadwozie;
            public int pojBag;
            public string asPark;
            public string relingiDach;
            public string tempomat;
            //public void setNapęd(string m) { napęd = m; }

            public Rodzinny(string m, string k, double c, string mo, int p, string n, int poj, string ap, string rd
                , string tmp) : base(m, k, c, mo, p) 
            {
                nadwozie = n; pojBag = poj; asPark = ap; relingiDach = rd;  tempomat = tmp;
            }
            public string pokaBaze()
            {
                return "Rodzinny pokaBaze";
            }
            public override string Pisz()
            {
                return   base.Pisz() + "\n" + "Nadwozie: " + nadwozie + "\nPoj Bag: " + pojBag
                    + "L\nAs Park: " + asPark + "\nRelingi Dach: " + relingiDach + "\nTempomat: " + tempomat;
            }
        }

         Terenowy batmobil = new Terenowy("Warszawa", "czarny", 10000000.99, "deLux", 5, "4x4", 2500,"Halogeny",
             10, "pickup");
          Rodzinny fiat = new Rodzinny("Fiat", "biały", 200000.99, "economy", 5, "minivan", 100, "tak", "tak", "aktywny");
          Sportowy jaguar = new Sportowy("Jaguar", "500KM", 2000000.99, "tuning", 5, "cabrio", 500, 3.1, "ceramiczne", "nitro");
          List<Samochody> samochody = new List<Samochody>();
       
        public Form1()
        {
           
            InitializeComponent();
            samochody.Add(batmobil);
            samochody.Add(fiat);
            samochody.Add(jaguar);
            listBox1.Items.Add(batmobil.marka);
            listBox1.Items.Add(fiat.marka);
            listBox1.Items.Add(jaguar.marka);

            listBox2.Items.Add(batmobil.marka);
            listBox2.Items.Add(fiat.marka);
            listBox2.Items.Add(jaguar.marka);

        }
        private void button1_Click(object sender, EventArgs e)
        {
            
             string s = "\nAuta:\n";
             for (int i = 0; i < samochody.Count; i++)
                 s += $"{i + 1}: {samochody[i].Pisz()}\n";
            label1.Text = s;
            
            
        }

        private void button2_Click(object sender, EventArgs e)
        {/*
          * Ten button MA wszystko zerować
          *

            */
        }

        private void button3_Click(object sender, EventArgs e)
        {
           
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex != -1)
            {
                if (samochody[listBox1.SelectedIndex] is Terenowy)
                {
                    label1.Text = ((Terenowy)samochody[listBox1.SelectedIndex]).Pisz();
                    // textBox3.Text = ((Terenowy)samochody[listBox1.SelectedIndex]).napęd;
                    // textBox4.Text = samochody[listBox1.SelectedIndex].marka;
                };
                if (samochody[listBox1.SelectedIndex] is Sportowy)
                {
                    label1.Text = ((Sportowy)samochody[listBox1.SelectedIndex]).Pisz();
                    // textBox3.Text = ((Sportowy)samochody[listBox1.SelectedIndex]).pokaBaze();
                    // textBox4.Text = samochody[listBox1.SelectedIndex].marka;
                };
                if (samochody[listBox1.SelectedIndex] is Rodzinny)
                {
                    label1.Text = ((Rodzinny)samochody[listBox1.SelectedIndex]).Pisz();
                    // textBox3.Text = samochody[listBox1.SelectedIndex].marka;
                    //  textBox4.Text = ((Rodzinny)samochody[listBox1.SelectedIndex]).nadwozie;
                };
            }
            
        }
        public void pokaListeBazy(int i)
        {

            textBox1.Text = samochody[listBox2.SelectedIndex].marka;
            textBox2.Text = samochody[listBox2.SelectedIndex].model;
            textBox6.Text = samochody[listBox2.SelectedIndex].cena.ToString();
            textBox7.Text = samochody[listBox2.SelectedIndex].kolor;
            textBox8.Text = samochody[listBox2.SelectedIndex].pojSilnika.ToString();
        }
        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBox2.SelectedIndex != -1)
            {

                if (samochody[listBox2.SelectedIndex] is Terenowy)
                {
                    pokaListeBazy(listBox2.SelectedIndex);

                    textBox9.Text = ((Terenowy)samochody[listBox2.SelectedIndex]).napęd;
                    textBox12.Text = ((Terenowy)samochody[listBox2.SelectedIndex]).moc.ToString();
                    textBox13.Text = ((Terenowy)samochody[listBox2.SelectedIndex]).dodatkoweOśw;
                    textBox10.Text = ((Terenowy)samochody[listBox2.SelectedIndex]).prześwit.ToString();
                    textBox11.Text = ((Terenowy)samochody[listBox2.SelectedIndex]).homologacjaCiężarowa;

                    textBox14.Text = "wyłączony";
                    textBox17.Text = "wyłączony";
                    textBox18.Text = "wyłączony";
                    textBox15.Text = "wyłączony";
                    textBox16.Text = "wyłączony";
                    textBox23.Text = "wyłączony";
                    textBox21.Text = "wyłączony";
                    textBox22.Text = "wyłączony";
                    textBox19.Text = "wyłączony";
                    textBox20.Text = "wyłączony";

                };
                if (samochody[listBox2.SelectedIndex] is Sportowy)
                {
                    pokaListeBazy(listBox2.SelectedIndex);

                    textBox9.Text = "wyłączony";
                    textBox12.Text = "wyłączony";
                    textBox13.Text = "wyłączony";
                    textBox10.Text = "wyłączony";
                    textBox11.Text = "wyłączony";

                    textBox14.Text = ((Sportowy)samochody[listBox2.SelectedIndex]).nitro;
                    textBox17.Text = ((Sportowy)samochody[listBox2.SelectedIndex]).moc.ToString();
                    textBox18.Text = ((Sportowy)samochody[listBox2.SelectedIndex]).przyspiesz.ToString();
                    textBox15.Text = ((Sportowy)samochody[listBox2.SelectedIndex]).hamulce;
                    textBox16.Text = ((Sportowy)samochody[listBox2.SelectedIndex]).tunning;

                    textBox23.Text = "wyłączony";
                    textBox21.Text = "wyłączony";
                    textBox22.Text = "wyłączony";
                    textBox19.Text = "wyłączony";
                    textBox20.Text = "wyłączony";
                };
                if (samochody[listBox2.SelectedIndex] is Rodzinny)
                {
                    pokaListeBazy(listBox2.SelectedIndex);

                    textBox9.Text = "wyłączony";
                    textBox12.Text = "wyłączony";
                    textBox13.Text = "wyłączony";
                    textBox10.Text = "wyłączony";
                    textBox11.Text = "wyłączony";

                    textBox14.Text = "wyłączony";
                    textBox17.Text = "wyłączony";
                    textBox18.Text = "wyłączony";
                    textBox15.Text = "wyłączony";
                    textBox16.Text = "wyłączony";

                    textBox23.Text = ((Rodzinny)samochody[listBox2.SelectedIndex]).nadwozie;
                    textBox21.Text = ((Rodzinny)samochody[listBox2.SelectedIndex]).pojBag.ToString();
                    textBox22.Text = ((Rodzinny)samochody[listBox2.SelectedIndex]).asPark;
                    textBox19.Text = ((Rodzinny)samochody[listBox2.SelectedIndex]).relingiDach;
                    textBox20.Text = ((Rodzinny)samochody[listBox2.SelectedIndex]).tempomat;

                };
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            if (!radioButton1.Checked && !radioButton2.Checked && !radioButton3.Checked)
            {
                MessageBox.Show("Zaznacz rodzaj pojazdu", "Błąd", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            textBox1.Text = "";
            textBox2.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";

            textBox9.Text = "";
            textBox12.Text = "";
            textBox13.Text = "";
            textBox10.Text = "";
            textBox11.Text = "";

            textBox14.Text = "";
            textBox17.Text = "";
            textBox18.Text = "";
            textBox15.Text = "";
            textBox16.Text = "";

            textBox23.Text = "";
            textBox21.Text = "";
            textBox22.Text = "";
            textBox19.Text = "";
            textBox20.Text = "";
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (!radioButton1.Checked && !radioButton2.Checked && !radioButton3.Checked)
            {
                MessageBox.Show("Zaznacz rodzaj pojazdu", "Błąd", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (radioButton1.Checked)
            {
                samochody.Add(new Sportowy(textBox1.Text, textBox2.Text, double.Parse(textBox6.Text), textBox7.Text,
                    int.Parse(textBox8.Text), textBox14.Text, int.Parse(textBox17.Text), double.Parse(textBox18.Text), textBox15.Text, textBox16.Text));
                listBox2.Items.Add(samochody[samochody.Count-1].marka);
                listBox1.Items.Add(samochody[samochody.Count - 1].marka);
            }
            if (radioButton2.Checked)
            {
                samochody.Add(new Terenowy(textBox1.Text, textBox2.Text, double.Parse(textBox6.Text), textBox7.Text,
                    int.Parse(textBox8.Text), textBox9.Text, int.Parse(textBox12.Text), textBox13.Text, int.Parse(textBox10.Text), textBox11.Text));
                listBox2.Items.Add(samochody[samochody.Count-1].marka);
                listBox1.Items.Add(samochody[samochody.Count - 1].marka);
            }
            if (radioButton3.Checked)
            {
                samochody.Add(new Rodzinny(textBox1.Text, textBox2.Text, double.Parse(textBox6.Text), textBox7.Text,
                    int.Parse(textBox8.Text), textBox23.Text, int.Parse(textBox21.Text), textBox22.Text, textBox19.Text, textBox20.Text));
                listBox2.Items.Add(samochody[samochody.Count-1].marka);
                listBox1.Items.Add(samochody[samochody.Count - 1].marka);
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            int i = listBox2.SelectedIndex;
            if(i != -1)
            {
                samochody.Remove(samochody[listBox2.SelectedIndex]);
                listBox2.Items.RemoveAt(i);
                listBox1.Items.RemoveAt(i);
                return;
            }
            MessageBox.Show("Nic nie zostało wybrane", "Błąd", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
