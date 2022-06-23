using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace chart
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int[] tLiniowa = new int[10];
        int[] tKwadrat = new int[10];
        int A, B, C;
        int wynikLiniowa, wynikKwadrat;
        Chart chart1 = new Chart();
            string[] seriesArray = { "Liniowa", "Kwadratowa" };

        private void Form1_Load(object sender, EventArgs e)
        {

            chart1.Titles.Add("Wykresy Funkcji:");
            

            A = int.Parse(textBox2.Text);
            B = int.Parse(textBox21.Text);
            C = int.Parse(textBox23.Text);

            tLiniowa[0] = int.Parse(textBox1.Text);
            tLiniowa[1] = int.Parse(textBox11.Text);
            tLiniowa[2] = int.Parse(textBox10.Text);
            tLiniowa[3] = int.Parse(textBox9.Text);
            tLiniowa[4] = int.Parse(textBox8.Text);
            tLiniowa[5] = int.Parse(textBox3.Text);
            tLiniowa[6] = int.Parse(textBox4.Text);
            tLiniowa[7] = int.Parse(textBox5.Text);
            tLiniowa[8] = int.Parse(textBox6.Text);
            tLiniowa[9] = int.Parse(textBox7.Text);

            tKwadrat[0] = int.Parse(textBox22.Text);
            tKwadrat[1] = int.Parse(textBox12.Text);
            tKwadrat[2] = int.Parse(textBox13.Text);
            tKwadrat[3] = int.Parse(textBox14.Text);
            tKwadrat[4] = int.Parse(textBox15.Text);
            tKwadrat[5] = int.Parse(textBox20.Text);
            tKwadrat[6] = int.Parse(textBox19.Text);
            tKwadrat[7] = int.Parse(textBox18.Text);
            tKwadrat[8] = int.Parse(textBox17.Text);
            tKwadrat[9] = int.Parse(textBox16.Text);
            /*
            for (int i = 0; i < 2; i++)
            {
                chart1.Series.Add(seriesArray[i]);
            }*/

            for (int i = 0; i < 10; i++)
            {
                wynikLiniowa = B * tLiniowa[i] + C;
                chart1.Series["Liniowa"].Points.AddXY(tLiniowa[i], wynikLiniowa);

                wynikKwadrat = A * tKwadrat[i] * tKwadrat[i];
                chart1.Series["Kwadratowa"].Points.AddXY(tKwadrat[i], wynikKwadrat);
            }
            ///foreach (Stałe st in stałeBindingSource.DataSource as List<Stałe>)
            
            /*
                        // Data arrays.
                        string[] seriesArray = { "Liniowa", "Kwadratowa" };
                        // int[] pointsArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
                        int[] pointsArray = new int[20];


                        this.chart1.Palette = ChartColorPalette.SeaGreen;


                        this.chart1.Titles.Add("Wykresy Funkcji:");

                            for (int i = 0; i < seriesArray.Length; i++)
                            {
                            Series series = this.chart1.Series.Add(seriesArray[i]);
                            series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;

                            for (int j=0; j< pointsArray.Length; j++)
                            {               

                            }

                            }*/


        }
        DataGridView data = new DataGridView();
        Chart chart = new Chart();
        
        ChartArea chartArea1 = new ChartArea();
        Legend legend1 = new Legend();
        Series series1 = new Series();

        List<int> array1 = new List<int>();
        List<int> array2 = new List<int>();

        private void button1_Click(object sender, EventArgs e)
        {
            chart1.Series.Clear();

            A = int.Parse(textBox2.Text);
            B = int.Parse(textBox21.Text);
            C = int.Parse(textBox23.Text);

            tLiniowa[0] = int.Parse(textBox1.Text);
            tLiniowa[1] = int.Parse(textBox11.Text);
            tLiniowa[2] = int.Parse(textBox10.Text);
            tLiniowa[3] = int.Parse(textBox9.Text);
            tLiniowa[4] = int.Parse(textBox8.Text);
            tLiniowa[5] = int.Parse(textBox3.Text);
            tLiniowa[6] = int.Parse(textBox4.Text);
            tLiniowa[7] = int.Parse(textBox5.Text);
            tLiniowa[8] = int.Parse(textBox6.Text);
            tLiniowa[9] = int.Parse(textBox7.Text);

            tKwadrat[0] = int.Parse(textBox22.Text);
            tKwadrat[1] = int.Parse(textBox12.Text);
            tKwadrat[2] = int.Parse(textBox13.Text);
            tKwadrat[3] = int.Parse(textBox14.Text);
            tKwadrat[4] = int.Parse(textBox15.Text);
            tKwadrat[5] = int.Parse(textBox20.Text);
            tKwadrat[6] = int.Parse(textBox19.Text);
            tKwadrat[7] = int.Parse(textBox18.Text);
            tKwadrat[8] = int.Parse(textBox17.Text);
            tKwadrat[9] = int.Parse(textBox16.Text);
            
            for (int i = 0; i < 2; i++)
            {
                chart1.Series.Add(seriesArray[i]);
                chart1.Series[i].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
                chart1.Series[i].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            }
            
            
            for (int i = 0; i < 10; i++)
            {
                wynikLiniowa = B * tLiniowa[i] + C;
                chart1.Series["Liniowa"].Points.AddXY(tLiniowa[i], wynikLiniowa);

                wynikKwadrat = A * tKwadrat[i] * tKwadrat[i];
                chart1.Series["Kwadratowa"].Points.AddXY(tKwadrat[i], wynikKwadrat);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
        }

      
    }
}
 
