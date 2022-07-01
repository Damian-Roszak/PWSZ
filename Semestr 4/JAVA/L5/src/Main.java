//package com.company;
import javax.swing.*;
import java.awt.*;
import java.lang.*;
import java.awt.event.*;
import java.util.HashSet;
import javax.swing.JFileChooser;
import java.io.File;
import java.io.*;

class Texty {
    String tekst1, tekst2, tekst3;
    Texty(){tekst1=tekst2=tekst3=null;}
}

class KartkaPapieru extends JComponent {
    int szer = 350;    int wys = 400; int skok = 40;
    int x = 150;    int y =  50;
    boolean slad = false;
    //obiekt pamięci
    class TPam {
        int x, y;
        public String toString(){
            return Integer.toString(x) +";"+Integer.toString(y);
        }
    }
    //kolekcja obiektów pamięci
    HashSet<TPam> pam = new HashSet<TPam>();
    public KartkaPapieru( ) {
        setPreferredSize(new Dimension( szer, wys));
        setBackground(Color.PINK);
    }
    public void reset(){
        pam.clear();
    }
    public void zap(){
        TPam p = new TPam();
        p.x = x+10;
        p.y = y+10;
        pam.add(p);
    }

    public void paintComponent(Graphics rysowanyObszar) {
        super.paintComponent(rysowanyObszar);
        rysowanyObszar.setColor(Color.RED);
        rysowanyObszar.fillRect(x, y, 40, 40);
        if(pam.size()!=0) rysujSlad(rysowanyObszar);
    }
    public void wczytajSlad(){
        int Itmp;
        String Stmp;
        String[] arrOfStr;
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setCurrentDirectory(new File(System.getProperty("user.home")));
        int result = fileChooser.showOpenDialog(this);//new JDialog()
        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
        try{
            FileReader obslugaOdczytu = new FileReader(selectedFile);
            BufferedReader buforOdczytu = new BufferedReader(obslugaOdczytu);
            String pojedynczyWiersz = null;
            pam.clear();
            while ((pojedynczyWiersz = buforOdczytu.readLine()) != null) {
                System.out.println(pojedynczyWiersz);
                arrOfStr  = pojedynczyWiersz.split(";");
                TPam p = new TPam();
                p.x = Integer.parseInt(arrOfStr[0]);
                p.y = Integer.parseInt(arrOfStr[1]);
                pam.add(p);
            }
            buforOdczytu.close();
            if(pam.size()!=0) rysujPam();
        }
        catch(IOException exc){
                exc.printStackTrace();
                System.exit(1);
            }
        }
    }
    public void rysujPam(){
        repaint();
    }
    public void zapiszSlad(){
        JFrame parentFrame = new JFrame();
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setDialogTitle("Określ plik do zapisu...");
        int userSelection = fileChooser.showSaveDialog(parentFrame);
        if (userSelection == JFileChooser.APPROVE_OPTION) {
            File fileToSave = fileChooser.getSelectedFile();
            try{
                FileWriter obslugaZapisu = new FileWriter(fileToSave);
                BufferedWriter buforZapisu = new BufferedWriter(obslugaZapisu);
                String pojedynczyWiersz = null;

                    for (TPam i : pam){
                        pojedynczyWiersz = i.toString()+"\n";
                        buforZapisu.append(pojedynczyWiersz);
                        System.out.println(pojedynczyWiersz);
                    }

                buforZapisu.close();
            }
            catch(IOException exc){
                exc.printStackTrace();
                System.exit(1);
            }
            System.out.println("Zapis jako plik: " + fileToSave.getAbsolutePath());
        }
    }
    public void rysujSlad(Graphics rysowanyObszar){
        for (TPam i : pam){
            rysowanyObszar.setColor(Color.YELLOW);
            rysowanyObszar.fillRect(i.x, i.y, 20, 20);
        }
    }
    public void lewo(){
        if( (x - 5) > 0) {
            if(slad) zap();
            x = x - skok;
            repaint();
        }
    }
    public void prawo(){
        if( (x + 45) < szer-2){
            if(slad) zap();
            x = x + skok;
            repaint();
        }

    }
    public void gora(){
       if(( y - 15) > 0)
       {
           if(slad) zap();
           y = y - skok;
           repaint();
       }
    }
    public void dol(){
        if((y+42)<wys){
            if(slad) zap();
            y = y + skok;
            repaint();
        }
    }
    public void sl(boolean stan){
        slad = stan;
    }
}
public class Main extends JFrame implements ActionListener{
    JButton przycisk1 = new JButton("Lewo");
    JButton przycisk2 = new JButton("Góra");
    JButton przycisk3 = new JButton("Dół");
    JButton przycisk4 = new JButton("Prawo");
    JCheckBox slad = new JCheckBox("Zostaw ślad");
    JButton reset = new JButton("Reset");
    JButton zapisz = new JButton("Zapisz");
    JButton wczytaj = new JButton("Wczytaj");

    KartkaPapieru rys = new KartkaPapieru();
    public Main()
    {
        super("Zdarzenia_1");
        setSize(500,500);
        //JPanel panel = new JPanel();
        Container panel = getContentPane();
        JPanel panel_gora = new JPanel();
        //panel_gora.setSize(500,500);
        panel_gora.setBackground(Color.GREEN);

        JPanel panel_dol = new JPanel();
        //panel_dol.setBackground(Color.YELLOW);

        panel.add(BorderLayout.WEST, panel_gora);
        //panel.add(BorderLayout.EAST, panel_dol);
        panel.add( panel_dol);
        panel_dol.setLayout(new BoxLayout(panel_dol,BoxLayout.Y_AXIS)) ;
        panel_gora.setLayout(new BoxLayout(panel_gora,BoxLayout.Y_AXIS)) ;

        przycisk1.addActionListener(this);
        przycisk2.addActionListener(this);
        przycisk3.addActionListener(this);
        przycisk4.addActionListener(this);
        slad.addActionListener(this);
        reset.addActionListener(this);
        zapisz.addActionListener(this);
        wczytaj.addActionListener(this);
        panel_gora.add(przycisk1);
        panel_gora.add(przycisk2);
        panel_gora.add(przycisk3);
        panel_gora.add(przycisk4);
        panel_gora.add(slad);
        panel_gora.add(reset);
        panel_gora.add(zapisz);
        panel_gora.add(wczytaj);
//panel_dol +++++++++++++++++++++++++++++++++++++++++++++
        panel_dol.add(rys);


//koniec panel_dol +++++++++++++++++++++++++++++++++++++++++++++
        setContentPane(panel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    public void actionPerformed(ActionEvent evt){
        Object zrodlo = evt.getSource();
        if(zrodlo==przycisk1)
            rys.lewo();
        else if(zrodlo==przycisk2)
            rys.gora();
        else if (zrodlo==przycisk3)
            rys.dol();
        else if (zrodlo==przycisk4)
            rys.prawo();
        else if (zrodlo==slad)
            rys.sl(slad.isSelected());
        else if (zrodlo==reset)
            rys.reset();
        else if (zrodlo==zapisz)
            rys.zapiszSlad();
        else if (zrodlo==wczytaj)
            rys.wczytajSlad();

        repaint();
    }
    public void lewo(){

        repaint();
    }
    public void prawo(){}
    public void gora(){}
    public void dol(){}
    public static void main(String[] args){
        Main programik = new Main();
        programik.setVisible(true);
    }
}
