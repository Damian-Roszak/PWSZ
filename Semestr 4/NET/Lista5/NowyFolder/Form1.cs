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

namespace Lista5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //listBox1.Width = (panel1.Size.Width / 2);
           // listBox2.Width = (panel1.Size.Width / 2);
        }
        private void przypiszIkone2(string[] pliki) 
        {
            listView1.Items.Clear();
            foreach(string file in pliki)
            {
                if (file.EndsWith(".jpg"))
                    listView1.Items.Add(file, 0);
                else
                    listView1.Items.Add(file, 0);
            }
        }
        private int przypiszIkone(string pliki)
        {
            if (pliki.EndsWith(".bmp") || pliki.EndsWith(".BMP"))
                return 1;            
            else if (pliki.EndsWith(".jpg") || pliki.EndsWith(".JPG"))
                return 2;
            else if (pliki.EndsWith(".png") || pliki.EndsWith(".PNG"))
                return 3;
            else if (pliki.EndsWith(".txt") || pliki.EndsWith(".TXT"))
                return 4;
            else if (pliki.EndsWith(".pdf") || pliki.EndsWith(".PDF"))
                return 5;
            else if (pliki.EndsWith(".gif") || pliki.EndsWith(".GIF"))
                return 6;
            else if (pliki.EndsWith(".avi") || pliki.EndsWith(".AVI") || pliki.EndsWith(".mov") || pliki.EndsWith(".MOV")
                || pliki.EndsWith(".mp4") || pliki.EndsWith(".MP4") || pliki.EndsWith(".mpeg") || pliki.EndsWith(".MPEG"))
                return 7;
            else if (pliki.EndsWith(".doc") || pliki.EndsWith(".DOC"))
                return 8;
            else if (pliki.EndsWith(".exe") || pliki.EndsWith(".EXE"))
                return 9;
            else if (pliki.EndsWith(".msi") || pliki.EndsWith(".MSI"))
                return 10;
            else if (pliki.EndsWith(".dll") || pliki.EndsWith(".DLL"))
                return 11;
            else if (pliki.EndsWith(".cs") || pliki.EndsWith(".CS"))
                return 12;
            else if (pliki.EndsWith(".hdd") || pliki.EndsWith(".HDD"))
                return 13;
            else if (pliki.EndsWith(".bin") || pliki.EndsWith(".BIN"))
                return 14;
            else if (pliki.EndsWith(".lnk") || pliki.EndsWith(".LNK"))
                return 15;
            else
                return 16;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ids = Directory.GetLogicalDrives();
            foreach (string id in ids)
            {
                DriveInfo dysk = new DriveInfo(id);
                string ext1 = "DYSK";
            // if (Path.GetExtension(id) == "") ext1 = "Folder";
            //else ext1 = Path.GetExtension(id);
            string idLoad = @"C:\Users\Damian\Documents\NET\Lista5";
                ListViewItem item = new ListViewItem(new[] {
                        idLoad
                        , ext1
                        , (dysk.TotalSize/(1024*1024*1024)).ToString() + "GB"
                        , "---"
                        , "---"
                        , idLoad}, 13);
                listView1.Items.Add(item);
                label1.Text = (dysk.TotalFreeSpace/1024).ToString() +"kB wolne z "+ (dysk.TotalSize/1024).ToString();
                label2.Text = id;

                ListViewItem item2 = new ListViewItem(new[] {
                        idLoad
                        , ext1
                        , (dysk.TotalSize/(1024*1024*1024)).ToString() + "GB"
                        , "---"
                        , "---"
                        , idLoad}, 13);
                listView2.Items.Add(item2);
                label3.Text = (dysk.TotalFreeSpace / 1024).ToString() + "kB wolne z " + (dysk.TotalSize / 1024).ToString();
                label4.Text = id;              
            }
        }
        

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //MessageBox.Show(listView1.Items.ToString(), "1111: ");
            try
            {
                if (listView1.SelectedItems.Count > 0)
                {
                    // MessageBox.Show(listView1.SelectedItems[0].SubItems[5].Text);
                    listView1.FullRowSelect = true;
                }
            }
            catch (Exception excep)
            {
                MessageBox.Show(excep.Message, "Błąd List 1 SelIndChange: ");

            }
        }
        string rootDirL1;
        string sciezkaL1 = @"C:\";
        string sL1 = "";
        private void f()
        {
            try
            {
                
                // listView1.Columns["Nazwa"].SelectedItems[0].Text;//  SelectedItems[0].Text;
                //  MessageBox.Show(listView1.Items[0].Text, "333: ");
                if (listView1.SelectedItems.Count > 0)
                {
                    sL1 = listView1.SelectedItems[0].SubItems[5].Text;
                    //  MessageBox.Show(s, "4444: ");
                    sciezkaL1 = sL1;
                    //   MessageBox.Show(sciezka, "555: ");
                }
                label2.Text = sciezkaL1;
                string extL1 = "";
                string[] dirs = { Path.GetFullPath(Path.Combine(sciezkaL1, @"..\")) };

                  FileAttributes attr = File.GetAttributes(sciezkaL1);
                 if (!attr.HasFlag(FileAttributes.Directory))
                //if (Path.GetExtension(sciezkaL1) != "")
                {
                    System.Diagnostics.Process.Start(sciezkaL1);
                    sciezkaL1 = Path.Combine(sciezkaL1, @"..\");               
                }
                else
                {
                    // MessageBox.Show(sciezkaL1 + " = '" + Path.GetExtension(sciezkaL1) + "'", "f(): IF");
                    //System.Diagnostics.Process.Start( sciezkaL1);
                    //return ;
                    listView1.Items.Clear();
                    try
                    {
                        dirs = Directory.GetDirectories(sciezkaL1);
                    }
                    catch (Exception excep)
                    {
                        MessageBox.Show(excep.Message + sciezkaL1, "f(): dirs");
                    }
                    rootDirL1 = Path.GetFullPath(Path.Combine(sciezkaL1, @"..\"));
                    ListViewItem item3 = new ListViewItem(new[] {
                        "[..]"
                        , " "
                        , "<DIR>"
                        , Directory.GetLastWriteTimeUtc(sciezkaL1).ToString()
                        , Directory.GetCreationTimeUtc(sciezkaL1).ToString()
                        , rootDirL1}, 0);
                    listView1.Items.Add(item3);
                    foreach (string dir in dirs)
                    {
                        //if (Path.GetExtension(dir) == "") ext = "Folder";
                        // else ext =  Path.GetExtension(dir);
                        ListViewItem item = new ListViewItem(new[] {
                        Path.GetFileName(dir)
                        , " "
                        , "<DIR>"
                        , Directory.GetLastWriteTimeUtc(dir).ToString()
                        , Directory.GetCreationTimeUtc(dir).ToString()
                        , dir}, 0);
                        listView1.Items.Add(item);
                        //listView1.Items.Add(Path.GetFileName(dir), 1).SubItems.Add(dir).SubItems.Add(dir); 
                        //listView1.Items.Add("path").SubItems.Add(dir);
                    }
                    string[] filePath = Directory.GetFiles(sciezkaL1);

                    string rozmiarL1 = "";
                    // if (sciezka != @"C:\") rozmiar = (fi.Length / 1024).ToString();
                    foreach (string id in filePath)
                    {
                        //listView1.Items.Add(Path.GetFileName(id), 1); 
                        //if (Path.GetExtension(id) == "") ext = "Folder";
                        //else ext = Path.GetExtension(id);
                        FileInfo fi = new FileInfo(id);
                        // DateTime fi1 = File.GetLastWriteTimeUtc(id).ToString();
                        ListViewItem item = new ListViewItem(new[] {
                        Path.GetFileName(id)
                        , Path.GetExtension(id)
                        , ((fi.Length / 1024).ToString()).PadRight(3) + "k"
                        , File.GetLastWriteTimeUtc(id).ToString()
                        , File.GetCreationTimeUtc(id).ToString()
                        , id}, przypiszIkone(id));
                        listView1.Items.Add(item);
                    }
                }
            }
            catch (Exception excep)
            {
                MessageBox.Show(excep.Message, "Błąd 2xKlik: ");

            }
        }
        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            f();
        }

        string rootDirL2;
        string sciezkaL2 = @"C:\";
        string sL2 = "";
        private void f2()
        {
            try
            {

                // listView2.Columns["Nazwa"].SelectedItems[0].Text;//  SelectedItems[0].Text;
                //  MessageBox.Show(listView2.Items[0].Text, "333: ");
                if (listView2.SelectedItems.Count > 0)
                {
                    sL2 = listView2.SelectedItems[0].SubItems[5].Text;
                    //  MessageBox.Show(s, "4444: ");
                    sciezkaL2 = sL2;
                    //   MessageBox.Show(sciezka, "555: ");
                }
                label4.Text = sciezkaL2;
                string extL2 = "";
                string[] dirs = { Path.GetFullPath(Path.Combine(sciezkaL2, @"..\")) };

                FileAttributes attr = File.GetAttributes(sciezkaL2);
                if (!attr.HasFlag(FileAttributes.Directory))
                //if (Path.GetExtension(sciezkaL2) != "")
                {
                    System.Diagnostics.Process.Start(sciezkaL2);
                    sciezkaL2 = Path.Combine(sciezkaL2, @"..\");
                }
                else
                {
                    // MessageBox.Show(sciezkaL2 + " = '" + Path.GetExtension(sciezkaL2) + "'", "f(): IF");
                    //System.Diagnostics.Process.Start( sciezkaL2);
                    //return ;
                    listView2.Items.Clear();
                    try
                    {
                        dirs = Directory.GetDirectories(sciezkaL2);
                    }
                    catch (Exception excep)
                    {
                        MessageBox.Show(excep.Message + sciezkaL2, "f(): dirs");
                    }
                    rootDirL2 = Path.GetFullPath(Path.Combine(sciezkaL2, @"..\"));
                    ListViewItem item3 = new ListViewItem(new[] {
                        "[..]"
                        , " "
                        , "<DIR>"
                        , Directory.GetLastWriteTimeUtc(sciezkaL2).ToString()
                        , Directory.GetCreationTimeUtc(sciezkaL2).ToString()
                        , rootDirL2}, 0);
                    listView2.Items.Add(item3);
                    foreach (string dir in dirs)
                    {
                        //if (Path.GetExtension(dir) == "") ext = "Folder";
                        // else ext =  Path.GetExtension(dir);
                        ListViewItem item = new ListViewItem(new[] {
                        Path.GetFileName(dir)
                        , " "
                        , "<DIR>"
                        , Directory.GetLastWriteTimeUtc(dir).ToString()
                        , Directory.GetCreationTimeUtc(dir).ToString()
                        , dir}, 0);
                        listView2.Items.Add(item);
                        //listView2.Items.Add(Path.GetFileName(dir), 2).SubItems.Add(dir).SubItems.Add(dir); 
                        //listView2.Items.Add("path").SubItems.Add(dir);
                    }
                    string[] filePath = Directory.GetFiles(sciezkaL2);

                    string rozmiarL2 = "";
                    // if (sciezka != @"C:\") rozmiar = (fi.Length / 1024).ToString();
                    foreach (string id in filePath)
                    {
                        //listView2.Items.Add(Path.GetFileName(id), 2); 
                        //if (Path.GetExtension(id) == "") ext = "Folder";
                        //else ext = Path.GetExtension(id);
                        FileInfo fi = new FileInfo(id);
                        // DateTime fi2 = File.GetLastWriteTimeUtc(id).ToString();
                        ListViewItem item = new ListViewItem(new[] {
                        Path.GetFileName(id)
                        , Path.GetExtension(id)
                        , ((fi.Length / 1024).ToString()).PadRight(3) + "k"
                        , File.GetLastWriteTimeUtc(id).ToString()
                        , File.GetCreationTimeUtc(id).ToString()
                        , id}, przypiszIkone(id));
                        listView2.Items.Add(item);
                        
                    }
                }
            }
            catch (Exception excep)
            {
                MessageBox.Show(excep.Message, "Błąd 2xKlik: ");

            }
        }
        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (listView2.SelectedItems.Count > 0)
                {
                   //  MessageBox.Show(listView2.Activation.ToString());
                    listView2.FullRowSelect = true;
                }
            }
            catch (Exception excep)
            {
                MessageBox.Show(excep.Message, "Błąd List 2 SelIndChange: ");

            }
        }

        private void listView1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                f();
            }   
        }

        private void listView2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                f2();
            }
        }

        private void listView2_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            f2();
        }

        private async void But(string sourceDirPath, string targetDirPath)
        {
            //var sourceDirPath = Path.Combine(Environment.CurrentDirectory, "KopiujTo");
            var sourceDirectoryInfo = new DirectoryInfo(sourceDirPath);

           // var targetDirPath = Path.Combine(Environment.CurrentDirectory, "Dokąd");
            var targetDirectoryInfo = new DirectoryInfo(targetDirPath);

            await Task.Run(() => CopyFiles(sourceDirectoryInfo, targetDirectoryInfo));
        }

        private void CopyFiles(DirectoryInfo source, DirectoryInfo target)
        {
            try
            {


                Directory.CreateDirectory(target.FullName);

                foreach (var file in source.GetFiles())
                {
                    if (File.Exists(Path.Combine(target.FullName, file.Name)))
                    {
                        if (DialogResult.Yes == MessageBox.Show(Path.GetFileName(Path.Combine(target.FullName, file.Name)) + " istnieje. Zastąpić?", "Plik istnieje", MessageBoxButtons.YesNo, MessageBoxIcon.Question))
                            file.CopyTo(Path.Combine(target.FullName, file.Name), true);
                    }
                    else
                        file.CopyTo(Path.Combine(target.FullName, file.Name), false);
                }

                foreach (var sourceSubDirectory in source.GetDirectories())
                {
                    var targetSubDirectory = target.CreateSubdirectory(sourceSubDirectory.Name);
                    CopyFiles(sourceSubDirectory, targetSubDirectory);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Błąd Kopiowania!");
            }
        }

        private void MoveFolders(string dirCopyZ, string dirCopyDo)
        {
            try
            {
                string[] plikiŹródła = Directory.GetFiles(dirCopyZ);                

                foreach (string file in plikiŹródła)
                {
                    string fileName = Path.GetFileName(file);
                    if (File.Exists(fileName))
                    {
                        if (DialogResult.Yes == MessageBox.Show(Path.GetFileName(fileName) + " exists. Replace?", "File Exists", MessageBoxButtons.YesNo, MessageBoxIcon.Question))
                            File.Copy(file, dirCopyDo + "\\" + fileName, true);
                    }
                    else
                        File.Copy(file, dirCopyDo + "\\" + fileName, false);
                    File.Delete(file);
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Błąd Przenoszenia!");
            }
        }

        private void wytnijToolStripButton_Click(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            But(sciezkaL1, sciezkaL2);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            But(sciezkaL2, sciezkaL1);
        }
    }
}
