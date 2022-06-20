package com.company;
//import com.sun.source.tree.SynchronizedTree;
//import com.sun.source.tree.*;
import java.util.Random;
import java.io.*;
import javax.swing.*;
import java.util.*;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.regex.*;


class FindFile
{
    public boolean findFile(String name,File file)
    {
        File[] list = file.listFiles();
        if(list!=null)
            for (File fil : list)
            {
                if (fil.isDirectory())
                {
                    findFile(name,fil);
                }
                else if (name.equalsIgnoreCase(fil.getName()))
                {
                    System.out.println(fil.getParentFile());
                    JOptionPane.showInputDialog(null, "Znaleziono: ");
                    return true;
                }
            }
        return false;
    }
}
class Wynik {
    int nrPytania;
    String kto, prawidłowaODP, udzielonaODP;
    ArrayList<Integer> ustalonaKolejność = new ArrayList<Integer>();
    int indexAktualnegoPytania;

    public Wynik(){
        nrPytania = -1; prawidłowaODP = ""; udzielonaODP = ""; kto = "";
        indexAktualnegoPytania = -1;
    }
    public Wynik(int nr, String pODP, String uODP, String who, int index)
    {
        nrPytania = nr; prawidłowaODP = pODP; udzielonaODP = uODP; kto = who;
        indexAktualnegoPytania = index;
    }
    public void zapiszDoStrumienia(DataOutputStream strumien)
            throws IOException {
        strumien.writeUTF(kto);
        strumien.writeInt(nrPytania);
        strumien.writeUTF(prawidłowaODP);
        strumien.writeUTF(udzielonaODP);
        strumien.writeInt(indexAktualnegoPytania);
        for (int i=0; i< ustalonaKolejność.size(); i++) strumien.writeInt(ustalonaKolejność.get(i));
    }
    public Wynik odczytajZStrumienia(DataInputStream strumien)
            throws IOException {
        kto = strumien.readUTF();
        nrPytania = strumien.readInt();
        prawidłowaODP = strumien.readUTF();
        udzielonaODP = strumien.readUTF();
        indexAktualnegoPytania = strumien.readInt();
        //for (int i=0; i< ustalonaKolejność.size(); i++) ustalonaKolejność.add(strumien.readInt());
        while( ustalonaKolejność.add(strumien.readInt())) System.out.println(ustalonaKolejność);
        return this;
    }
}
class  Admin {
    Wynik wynik = new Wynik();;
    ArrayList<Wynik> TWyniki = new ArrayList<Wynik>();

    Admin() {
        //DataInputStream strumienWejsciowy = new DataInputStream(new FileInputStream("dane.dat"));
        //Wynik wynik = new Wynik();
    } ;
    void wyswietl(){
        JOptionPane.showMessageDialog(null, "student: " + wynik.kto
                + "\nnr pytania: " + wynik.nrPytania
                + "\nprawidłowa odp: " + wynik.prawidłowaODP
                + "\nudzielona odp: " + wynik.udzielonaODP
                + "\nnr pyt. na którym skończył: " + wynik.indexAktualnegoPytania
                + "\nwylosowana kolejność: " + wynik.ustalonaKolejność
        );
    }
void pokazWynikiStudenta(String student){
    try {
       // JOptionPane.showMessageDialog(null, "pokazWynikiStudenta: " + student);
        DataInputStream strumieńIn = new DataInputStream(new FileInputStream("C:\\DamianR\\JAVA\\Lista4\\baza\\"+ student));
        if (strumieńIn == null) JOptionPane.showMessageDialog(null, "strumień null: ");
        wynik.odczytajZStrumienia(strumieńIn);
        strumieńIn.close();
        wyswietl();

    } catch (IOException exce) {
        exce.printStackTrace();
        System.exit(1);
    }
}
    void start() {
        // pokaż wyniki studentów
        //  try {
        ArrayList <String> listaStudentów = new ArrayList<String>();
        //File file =
        //FileReader file = new FileReader("baza/");
        File file = new File("baza/");
        // BufferedReader buforOdczytu = new BufferedReader(obslugaOdczytu);
        String pojedynczyWiersz = null;
        // while ((pojedynczyWiersz = buforOdczytu.readLine()) != null) {
        File[] list = file.listFiles();
        int licznik=0;
        if (list != null)
        {
            for (File fil : list) {
                //if (name.equalsIgnoreCase(fil.getName())) {
                //System.out.println(fil.getName());
                listaStudentów.add("\n" + licznik + ") " + fil.getName());
                licznik++;
                //  return true;
                //}
            }
            String s="";
            if(!listaStudentów.isEmpty())
               s= JOptionPane.showInputDialog(null, "Znaleziono: "+ listaStudentów);
            if(s!=null){
                int indeksStudenta = Integer.parseInt(s);
                String inSt = listaStudentów.get(indeksStudenta);
                String[] stud = inSt.split("\\s{1,}");
                //JOptionPane.showMessageDialog(null,stud[2]);
                pokazWynikiStudenta(stud[2]);
            }
        }
        else
            JOptionPane.showMessageDialog(null, "Brak Wyników do wyświetlenia: ");
        //return false;
        /* } catch (IOException exce) {
             exce.printStackTrace();
             System.exit(1);
         }*/
    }
}

class TPytania{
    int numerPytania;
    String treśćPytania, odp1, odp2, odp3, odp4, nrCorrectOdp;
    String[] tabOdp = new String[4];
    TPytania(){}
}
class Test{
    int ilePytań=0, tmpRND;
    ArrayList<Integer> ustalonaKolej = new ArrayList<Integer>();
    int indexKolei=0;
    Random rnd = new Random();

    String[] arrOfStr;
    String odp, student;
    Wynik wynik;
    // KOLEKCJA PYAŃ

    ArrayList<TPytania> HSPytania = new ArrayList<TPytania>();
    Test(){
        wynik = new Wynik();
    }
    void start()
    {
        pokażPytanie();
    }
    void wznow()
    {
        wynik.kto = student;
        try{
            FileReader obslugaOdczytu = new FileReader("pytania.txt");
            BufferedReader buforOdczytu = new BufferedReader(obslugaOdczytu);
            String pojedynczyWiersz = null;
            while ((pojedynczyWiersz = buforOdczytu.readLine()) != null) {
                //wstaw do kolekcji pytań
                ++ilePytań;
                TPytania pytanie = new TPytania();
//System.out.println(pojedynczyWiersz);
                arrOfStr  = pojedynczyWiersz.split(";\\s{1,}");
                pytanie.numerPytania = Integer.parseInt(arrOfStr[0]);
                pytanie.treśćPytania = arrOfStr[1];
                pytanie.tabOdp[0] = arrOfStr[2];
                pytanie.tabOdp[1] = arrOfStr[3];
                pytanie.tabOdp[2] = arrOfStr[4];
                pytanie.tabOdp[3] = arrOfStr[5];
                pytanie.nrCorrectOdp = arrOfStr[6];

                //System.out.println(pytanie.numerPytania + " " + pytanie.treśćPytania + " " + pytanie.tabOdp[0] + " " + pytanie.tabOdp[1] + " " + pytanie.tabOdp[2] + " " + pytanie.tabOdp[3] + " correct= " + pytanie.nrCorrectOdp);
                HSPytania.add(pytanie);
            }
            // for (TPytania p : HSPytania)
            //  System.out.println(p.numerPytania + " " + p.treśćPytania + " " + p.tabOdp[0] + " " + p.tabOdp[1] + " " + p.tabOdp[2] + " " + p.tabOdp[3] + " correct= " + p.nrCorrectOdp);

            // for (int i = 0; i<HSPytania.size();i++)
            //  System.out.println(HSPytania.get(i).numerPytania + " " + HSPytania.get(i).treśćPytania + " " + HSPytania.get(i).tabOdp[0] + " " + HSPytania.get(i).tabOdp[1] + " " + HSPytania.get(i).tabOdp[2] + " " + HSPytania.get(i).tabOdp[3] + " correct= " + HSPytania.get(i).nrCorrectOdp);

            buforOdczytu.close();
            for(int i=0; i<ilePytań; i++)
            {
                //wylosuj kolejność  pytań
                tmpRND = rnd.nextInt(ilePytań);
                if (!ustalonaKolej.contains(tmpRND))
                {
                    ustalonaKolej.add(tmpRND);
                    // System.out.println(ustalonaKolej);
                    continue;
                }
                i--;
            }
            //zapisz kolekcje kolejności pytań do studenta
            wynik.ustalonaKolejność= ustalonaKolej;
            indexKolei=0;
            pokażPytanie();
        }
        catch(IOException exc){
            exc.printStackTrace();
            System.exit(1);
        }
    }
    void  rozpocznij()
    {
        wynik.kto = student;
        try{
            FileReader obslugaOdczytu = new FileReader("pytania.txt");
            BufferedReader buforOdczytu = new BufferedReader(obslugaOdczytu);
            String pojedynczyWiersz = null;
            while ((pojedynczyWiersz = buforOdczytu.readLine()) != null) {
                //wstaw do kolekcji pytań
                ++ilePytań;
                TPytania pytanie = new TPytania();
//System.out.println(pojedynczyWiersz);
                arrOfStr  = pojedynczyWiersz.split(";\\s{1,}");
                pytanie.numerPytania = Integer.parseInt(arrOfStr[0]);
                pytanie.treśćPytania = arrOfStr[1];
                pytanie.tabOdp[0] = arrOfStr[2];
                pytanie.tabOdp[1] = arrOfStr[3];
                pytanie.tabOdp[2] = arrOfStr[4];
                pytanie.tabOdp[3] = arrOfStr[5];
                pytanie.nrCorrectOdp = arrOfStr[6];

                //System.out.println(pytanie.numerPytania + " " + pytanie.treśćPytania + " " + pytanie.tabOdp[0] + " " + pytanie.tabOdp[1] + " " + pytanie.tabOdp[2] + " " + pytanie.tabOdp[3] + " correct= " + pytanie.nrCorrectOdp);
                HSPytania.add(pytanie);
            }
            // for (TPytania p : HSPytania)
            //  System.out.println(p.numerPytania + " " + p.treśćPytania + " " + p.tabOdp[0] + " " + p.tabOdp[1] + " " + p.tabOdp[2] + " " + p.tabOdp[3] + " correct= " + p.nrCorrectOdp);

            // for (int i = 0; i<HSPytania.size();i++)
            //  System.out.println(HSPytania.get(i).numerPytania + " " + HSPytania.get(i).treśćPytania + " " + HSPytania.get(i).tabOdp[0] + " " + HSPytania.get(i).tabOdp[1] + " " + HSPytania.get(i).tabOdp[2] + " " + HSPytania.get(i).tabOdp[3] + " correct= " + HSPytania.get(i).nrCorrectOdp);

            buforOdczytu.close();
            for(int i=0; i<ilePytań; i++)
            {
                //wylosuj kolejność  pytań
                tmpRND = rnd.nextInt(ilePytań);
                if (!ustalonaKolej.contains(tmpRND))
                {
                    ustalonaKolej.add(tmpRND);
                    // System.out.println(ustalonaKolej);
                    continue;
                }
                i--;
            }
            //zapisz kolekcje kolejności pytań do studenta
            wynik.ustalonaKolejność= ustalonaKolej;
            indexKolei=0;
            pokażPytanie();
        }
        catch(IOException exc){
            exc.printStackTrace();
            System.exit(1);
        }
    }
    void pokażPytanie(){

        try{
            int i;
            // for(int i=0; i<ilePytań;i++) //zadaj pytanie
            for(int j=indexKolei; j<ustalonaKolej.size();j++)
            {
                //System.out.println("j=" + j);
                // System.out.println("ustalonaKolej.get(j)=" + ustalonaKolej.get(j));
                //   System.out.println("ustalonaKolej=" + ustalonaKolej);
                i = ustalonaKolej.get(j);
                DataOutputStream strumienWyjsciowy = new DataOutputStream(new FileOutputStream("baza/"+ student + ".dat", true));
                //wybież z kolekcji kolejności wartość i wstaw ją do kolekcji pytań
                //HSPytania.get(i).
                // pobież pytanie i je zadaj
                odp = JOptionPane.showInputDialog(null,
                        HSPytania.get(i).treśćPytania
                                + "\n1)" + HSPytania.get(i).tabOdp[0]
                                + "\n2)" + HSPytania.get(i).tabOdp[1]
                                + "\n3)" + HSPytania.get(i).tabOdp[2]
                                + "\n4)" + HSPytania.get(i).tabOdp[3]
                );
                // System.out.println("odp= " + odp);
                if (odp==null)
                {
                    wynik.nrPytania = HSPytania.get(i).numerPytania;
                    wynik.indexAktualnegoPytania = j;
                    wynik.prawidłowaODP = HSPytania.get(i).nrCorrectOdp;
                    wynik.udzielonaODP = "";
                    wynik.zapiszDoStrumienia(strumienWyjsciowy);
                    strumienWyjsciowy.close();
                    return;
                }
                else {
                    wynik.nrPytania = HSPytania.get(i).numerPytania;
                    wynik.indexAktualnegoPytania = j;
                    wynik.prawidłowaODP = HSPytania.get(i).nrCorrectOdp;
                    wynik.udzielonaODP = odp;
                    wynik.zapiszDoStrumienia(strumienWyjsciowy);

                    strumienWyjsciowy.close();
                }



                // JOptionPane.showMessageDialog(null, "HSPytania.get(i).nrCorrectOdp=" + HSPytania.get(i).nrCorrectOdp + "\nodp=" + odp);

                // if (odp.equals(HSPytania.get(i).nrCorrectOdp)) JOptionPane.showMessageDialog(null, "true");
                // else JOptionPane.showMessageDialog(null, "false: ");
            }


           /*
                arrOfStr  = pojedynczyWiersz.split(";\s{1,}");
                odp = JOptionPane.showInputDialog(null,
                        arrOfStr[1]
                                + "\n1)" + arrOfStr[2]
                                + "\n2)" + arrOfStr[3]
                                + "\n3)" + arrOfStr[4]
                                + "\n4)" + arrOfStr[5]
                );

                if (odp.equals(arrOfStr[6])) JOptionPane.showMessageDialog(null, "true");
                else JOptionPane.showMessageDialog(null, "false: ");


            }*/
        }
        catch(IOException exc){
            exc.printStackTrace();
            System.exit(1);
        }
    }

}

public class Main {

    public static void main(String[] args) {

        FindFile ff = new FindFile();

        Admin adm = new Admin();
        Test test = new Test();
        String s;
        s = JOptionPane.showInputDialog(null, "Login: ");
        if (s.equals("Admin")) adm.start();
        else
        {
            if( ff.findFile(s+".dat",new File("baza")))
            {
                test.student = s;
                test.wznow();
            }
            else
            {
                test.student = s;
                test.rozpocznij();
            }
        }
    }
}

