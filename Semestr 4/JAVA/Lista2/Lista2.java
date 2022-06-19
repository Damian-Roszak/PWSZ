package com.company;
import java.util.Random;
import java.io.*;
import javax.swing.*;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static String tekstRnd(){
        Random random = new Random();
        String tab = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
        String result = "";
        for (int i=0; i<5; i++){
            result += tab.charAt(random.nextInt(tab.length()));
        }
        return result;
    }

    public static int intRnd(){
        Random random = new Random();
        int result;
        int min = 200;
        int max = 400;
        result = random.nextInt(200)+200;
        return result;
    }
    public static int kostka(){
        Random random = new Random();
        int result;
        result = random.nextInt(5)+1;
        return result;
    }
    public static class Plansza{
        public int ilośćGraczy;
        public int iluBankrótów;
        public  boolean koniecGry;
        public  String[] ulice = {"Start","Głuchołazka","Nyska","Prudnicka","Wrocławska","Opolska","Krakowska","Poznańska","Warszawska","Kielecka",
                "Gdańska","Gdyńska","Sopocka", "Szczecińska","Kołobrzeska","Konińska","Elbląska","Suwalska","Zakopiańska","Katowicka"
                 ,"Tarnobrzeska","Brzeska","Zgorzelecka","Wałbrzyska","Zdrojowa","Ząbkowicka","Łódzka","Radomska","Tarnowska","Sudecka"};
        public  Ulica pola[];
        public  Bank bankier;
        public   Gracz gracz[];

        public Plansza(){
            int ilu;
            bankier = new Bank();
            String s = JOptionPane.showInputDialog(null, "Ilu graczy?: ");
            ilu = Integer.parseInt(s);
            this.ilośćGraczy = ilu;
            int iluBankrótów = 0;
            koniecGry = false;

            pola = new Ulica[30];
            for(int i=0; i<30; i++)
            {
                if(i==0){
                    Ulica obj = new Ulica(
                            ulice[i], 0,0,0,0,0
                            ,-1,false, 0, false
                    );
                    pola[i] = obj;
                }
                Ulica obj = new Ulica(
                    ulice[i], intRnd(),intRnd()+1000,0,0,intRnd()
                    ,-1,false,intRnd(),true
                );
                pola[i] = obj;

            }
            gracz = new Gracz[ilośćGraczy];
            for(int i=0; i<ilośćGraczy; i++)
            {
                Gracz obj = new Gracz(1500,true,false, 0);
                gracz[i]=obj;
            }
        }

    }
    public static class Bank
    {
       static final String nazwa = "Bank";
        void setOwner(Plansza pl , int indexPlanszy, int indexOwnera)//, Gracz gr
        {
               pl.pola[indexPlanszy].czyja = indexOwnera;
               pl.pola[indexPlanszy].możnaKupić = false;
               pl.gracz[indexOwnera].własnościGracza.add(indexPlanszy);
               pl.gracz[indexOwnera].stanKonta -= pl.pola[indexPlanszy].cena;

        }
        void selProperty(Plansza pl , int indexPlanszy, int indexOwnera)//, Gracz gr
        {
            pl.pola[indexPlanszy].czyja = -1;
            pl.pola[indexPlanszy].możnaKupić = true;
            pl.gracz[indexOwnera].własnościGracza.remove(indexPlanszy);
            pl.gracz[indexOwnera].stanKonta += pl.pola[indexPlanszy].cena;
        }

        void pobierzCzynsz(Plansza pl , int indexPlanszy, int indexOwnera, int indexPłatnika)//, Gracz gr
        {
            pl.gracz[indexPłatnika].stanKonta -= pl.pola[indexPlanszy].czynsz;
            pl.gracz[indexOwnera].stanKonta += pl.pola[indexPlanszy].czynsz;
        }
    }
    public static class  Gracz
    {
        int stanKonta;
        boolean aktyw;
        boolean bankrut;
        int pozNaPlanszy;
        Set<Integer> własnościGracza = new HashSet<Integer>();
        Gracz (int stan, boolean activ, boolean bancrupcy, int poz)
        {
            stanKonta=stan; aktyw=activ; bankrut=bancrupcy; pozNaPlanszy=poz; //własnościGracza;
        }
    }
    public static abstract class Pole
    {
        String nazwa;
        int cenaDomu;
        int cenaHotelu;
        int ileDomów;
        int ileHoteli;
        Pole(String nazw, int cenDom, int cenHot, int liczDomy, int liczHotele)
        {
            nazwa=nazw; cenaDomu=cenDom; cenaHotelu=cenHot; ileDomów=liczDomy; ileHoteli=liczHotele;
        }

        abstract String fun();
    }
    public static class Ulica extends Pole
    {
        int cena;
        int czyja;
        boolean hipoteka;
        int czynsz;
        boolean możnaKupić;
        Ulica(String nazw, int cenDom, int cenHot, int liczDomy, int liczHot , int c, int cz, boolean h, int czsz, boolean ok){
            super(nazw,cenDom,cenHot,liczDomy, liczHot);   cena=c; czyja=cz; hipoteka=h; czynsz=czsz; możnaKupić=ok;
        }
        String fun(){return "zwrot";};
    }
    public static void pokaWłości(Plansza p, int indexGracza)
    {
        String s = "";
        for (Integer i: p.gracz[indexGracza].własnościGracza) { s += ", "+p.pola[i].nazwa;}
        JOptionPane.showMessageDialog(null, "Jesteś właścicielm: "+s);
    }
//////////======================          MAIN =================================================================================================
    public static void main(String[] args) {
        int któryGracz = 0;
        int ileOczek = 0;
        int indexPlanszy = 0;
        String wybranaOpcja = ""; char ch = 'a';
        int czyGraczaStaćNaCzynsz;
        try{
            Plansza plansza = new Plansza();
            while(plansza.iluBankrótów != plansza.ilośćGraczy-1)//plansza.koniecGry == false
            {
                ileOczek=kostka();
                //JOptionPane.showMessageDialog(null,"Gracz nr: "+ któryGracz +" Rzuciłęś kostką, wypadło: "+ileOczek+" oczek" );
                if((plansza.gracz[któryGracz].pozNaPlanszy + ileOczek)>29)
                    plansza.gracz[któryGracz].pozNaPlanszy -= 30;

                plansza.gracz[któryGracz].pozNaPlanszy += ileOczek;
                indexPlanszy = plansza.gracz[któryGracz].pozNaPlanszy;

                JOptionPane.showMessageDialog(null, "1) Gracz nr: "+ któryGracz +"\n Rzuciłęś kostką, wypadło: "+ileOczek+" oczek" +"\n Stoisz na polu: "
                        + plansza.pola[indexPlanszy].nazwa+" \nmasz na koncie: "+ plansza.gracz[któryGracz].stanKonta +" PLN \n której cena wynosi: "+plansza.pola[indexPlanszy].cena+" PLN ");

                if(plansza.pola[indexPlanszy].możnaKupić == true && plansza.gracz[któryGracz].stanKonta>=plansza.pola[indexPlanszy].cena)
                {
                    wybranaOpcja = JOptionPane.showInputDialog(null, "2) Gracz nr: "+ któryGracz +"\n Stoisz na polu: "
                        + plansza.pola[indexPlanszy].nazwa + "\n które można kupić za:"+plansza.pola[indexPlanszy].cena +" PLN \nmasz na koncie: "+ plansza.gracz[któryGracz].stanKonta +" PLN "
                        +"\nco chcesz zrobić?:"
                        + "\n1. Kup ulice."
                        + "\n2. Pokaż moje nieruchomości."
                        + "\n3. Nic nie rób."
                    );

                    ch = '3';
                    if (Pattern.compile("^[1-2]").matcher(wybranaOpcja).find()) {

                        ch = wybranaOpcja.charAt(0);
                    }
                    switch (ch)
                    {
                        case '1':
                            plansza.bankier.setOwner(plansza, indexPlanszy, któryGracz);
                        break;
                        case '2':
                            pokaWłości(plansza, któryGracz);
                        break;
                    }
                    //return;
                }else if(indexPlanszy == 0)
                {
                    JOptionPane.showMessageDialog(null, "3) Gracz nr: "+ któryGracz +"\n Stoisz na polu start, następny zawodnik :D," +
                           "\n masz na koncie: "+ plansza.gracz[któryGracz].stanKonta +" PLN "  );
                }else if( plansza.gracz[któryGracz].własnościGracza.contains(plansza.pola[indexPlanszy].czyja)){
                       JOptionPane.showMessageDialog(null, "4) Gracz nr: "+ któryGracz +"\n Stoisz na "+ plansza.pola[indexPlanszy].nazwa
                       + "\n której jesteś właścicielem, masz na koncie: "+ plansza.gracz[któryGracz].stanKonta +" PLN ");
                }
                else if(indexPlanszy != 0 && plansza.pola[indexPlanszy].możnaKupić == false && !plansza.gracz[któryGracz].własnościGracza.contains(indexPlanszy))
                {
                    if( plansza.gracz[któryGracz].stanKonta >= plansza.pola[indexPlanszy].czynsz)
                    {
                       czyGraczaStaćNaCzynsz = 1;
                       JOptionPane.showMessageDialog(null, "5) Gracz nr: "+ któryGracz +"\n Stoisz na polu: "
                                + plansza.pola[indexPlanszy].nazwa + "\n które należy do "+ plansza.pola[indexPlanszy].czyja
                                +"\n musisz zapłacić czynsz, wynoszący " + plansza.pola[indexPlanszy].czynsz+ "\n masz na koncie: "+ plansza.gracz[któryGracz].stanKonta +"PLN "
                                + "\n1. Zapłać Czynsz." );
                         plansza.bankier.pobierzCzynsz(plansza, indexPlanszy, plansza.pola[indexPlanszy].czyja, któryGracz);
                    }else if(plansza.gracz[któryGracz].własnościGracza.size() != 0 && !plansza.gracz[któryGracz].własnościGracza.contains(indexPlanszy)){
                        czyGraczaStaćNaCzynsz = 0;
                        JOptionPane.showMessageDialog(null, "6) Gracz nr: "+ któryGracz +"\n Stoisz na polu: "
                                + plansza.pola[indexPlanszy].nazwa + "\n które należy do "+ plansza.pola[indexPlanszy].czyja
                                +"\n musisz zapłacić czynsz, wynoszący " + plansza.pola[indexPlanszy].czynsz + "\n nie masz wystarczająco dużo gotówki, masz na koncie: "+ plansza.gracz[któryGracz].stanKonta +"PLN "
                                + "\n1. Sprzedaj nieruchomość by zapłacić czynsz." );
                         plansza.bankier.selProperty(plansza, indexPlanszy, któryGracz);
                    }else if(plansza.gracz[któryGracz].własnościGracza.size() == 0){
                        czyGraczaStaćNaCzynsz = 0;
                        JOptionPane.showMessageDialog(null, "7) Gracz nr: "+ któryGracz +"\n Stoisz na polu: "
                                + plansza.pola[indexPlanszy].nazwa + "\n które należy do "+ plansza.pola[indexPlanszy].czyja
                                +"\n musisz zapłacić czynsz, wynoszący " + plansza.pola[indexPlanszy].czynsz + "\n nie masz wystarczająco dużo gotówki  masz na koncie: "+ plansza.gracz[któryGracz].stanKonta +"PLN "
                                + "\nAni nie posiadasz nieruchomości na sprzedarz by zapłacić czynsz. BANKRUTUJESZ!!!!!!" );
                        plansza.iluBankrótów++;
                        plansza.gracz[któryGracz].aktyw = false;
                        plansza.gracz[któryGracz].bankrut = true;
                        return;
                    }

                }

                któryGracz++;
                if(któryGracz >= plansza.ilośćGraczy) któryGracz=0;
            }

            int graczWygrany = -1;
            for (int i=0; i<plansza.ilośćGraczy; i++)
                if(plansza.gracz[i].aktyw) graczWygrany=i;
            JOptionPane.showMessageDialog(null, "Koniec gry"
                + " wygrał gracz: " + graczWygrany
            );
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}


