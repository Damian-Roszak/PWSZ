package com.company;
import java.util.Random;
import java.io.*;
import javax.lang.model.element.ElementKind;
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
        public  String[] ulice = {"Start","Głuchołazka","Nyska","Prudnicka", "Kolej Północna","Wrocławska","Opolska","Krakowska","Poznańska","Warszawska","Kielecka",
                "Gdańska", "Kolej Zachodnia","Gdyńska","Sopocka", "Szczecińska","Kołobrzeska", "Elektrownia","Konińska","Elbląska","Suwalska", "Kolej Południowa","Zakopiańska","Katowicka"
                 ,"Tarnobrzeska","Ubezpieczalnia","Brzeska","Zgorzelecka","Wałbrzyska","Zdrojowa", "Kolej Wschodnia","Ząbkowicka","Łódzka","Radomska","Tarnowska","Sudecka"};
        public  Pole pola[];
        public  Bank bankier;
        public   Gracz gracz[];
        public int rozmiarTabUlice = ulice.length;

        public Plansza(){
            int ilu;
            bankier = new Bank();
            String s = JOptionPane.showInputDialog(null, "Ilu graczy?: ");
            ilu = Integer.parseInt(s);
            this.ilośćGraczy = ilu;
            int iluBankrótów = 0;
            koniecGry = false;

            pola = new Pole[rozmiarTabUlice];
            Ulica obj = new Ulica(ulice[0], false, 0, -1, false, 0, 0, 0, 0, 0);
            pola[0] = obj;
            for(int i=1; i<rozmiarTabUlice; i++)
            {
                if(ulice[i] == "Elektrownia")
                {
                    //obj = new Ulica(ulice[i], true, intRnd(), -1, false, intRnd(), -1, -1, -1, -1);
                    Elektrownia prunt = new Elektrownia(ulice[i], true, intRnd(), -1, false, intRnd());
                    //pola[i] = obj;
                    pola[i] = prunt;
                    continue;
                }
                if(ulice[i] == "Ubezpieczalnia")
                {
                    //obj = new Ulica(ulice[i], false, -1, -1, false, -1, -1, -1, -1, -1);
                    Ubezpieczalnia pzu = new Ubezpieczalnia(ulice[i], false);
                    //pola[i] = obj;
                    pola[i] = pzu;
                    continue;
                }
                obj = new Ulica(ulice[i], true, intRnd(), -1, false, intRnd(), intRnd(), intRnd(), 0, 0);
                pola[i] = obj;

            }
            gracz = new Gracz[ilośćGraczy];
            for(int i=0; i<ilośćGraczy; i++)
            {
                Gracz player = new Gracz(1500,true,false, 0, i);
                gracz[i] = player;
            }
        }

    }
    public static class Bank
    {
       static final String nazwa = "Bank";
       String setHipoteka(Plansza p, int indexPola, Gracz g)
       {
           return  "Hipoteka ustanowiona na nieruchomość:" + p.pola[indexPola] + " Kredyt przyznany w kwocie: " ;//+ p.pola[indexPola].cena;
       }
        void setOwner(Plansza pl , int indexPlanszy, int indexOwnera)//, Gracz gr
        {
      /*         pl.pola[indexPlanszy].czyja = indexOwnera;
               pl.pola[indexPlanszy].możnaKupić = false;
               pl.gracz[indexOwnera].własnościGracza.add(indexPlanszy);
               pl.gracz[indexOwnera].stanKonta -= pl.pola[indexPlanszy].cena;
*/
        }
        void selProperty(Plansza pl , int indexPlanszy, int indexOwnera)//, Gracz gr
        {
          /*  pl.pola[indexPlanszy].czyja = -1;
            pl.pola[indexPlanszy].możnaKupić = true;
            pl.gracz[indexOwnera].własnościGracza.remove(indexPlanszy);
            pl.gracz[indexOwnera].stanKonta += pl.pola[indexPlanszy].cena;

           */
        }

        void pobierzCzynsz(Plansza pl , int indexPlanszy, int indexOwnera, int indexPłatnika)//, Gracz gr
        {
          /*  pl.gracz[indexPłatnika].stanKonta -= pl.pola[indexPlanszy].czynsz;
            pl.gracz[indexOwnera].stanKonta += pl.pola[indexPlanszy].czynsz;

           */
        }
    }
    public static class  Gracz
    {
        int stanKonta;
        boolean aktyw;
        boolean bankrut;
        int pozNaPlanszy;
        int indeksGracza ;
        Set<Integer> własnościGracza = new HashSet<Integer>();
        Gracz (int stan, boolean activ, boolean bancrupcy, int poz, int playerIndex)
        {
            stanKonta=stan; aktyw=activ; bankrut=bancrupcy; pozNaPlanszy=poz; indeksGracza=playerIndex;//własnościGracza;
        }
        void sprzedajNieruchomość(Plansza p, Gracz g){
            stanKonta += p.pola[g.pozNaPlanszy].f();
            własnościGracza.remove(p.pola[g.pozNaPlanszy]);
           // p.pola[g.pozNaPlanszy].czyja = -1;
            p.pola[g.pozNaPlanszy].czyja1(-1) ;
        }

        public String pokaWłości(Plansza p)
        {
            String s = "";
            for (Integer i : własnościGracza)
            {
                s += ", "+ p.pola[i].nazwa;
            }
            JOptionPane.showMessageDialog(null, "Jesteś właścicielm: "+s);

            return s;
        }
    }
    public static abstract class Pole
    {
        String nazwa;
        boolean możnaKupić;
        Pole(String nazw, boolean kupOK )
        {
            nazwa=nazw; możnaKupić=kupOK;
        }
        abstract int f();
        abstract void czyja1(int i);
        abstract int f1();
        abstract String fun();
        abstract String fun(Plansza p, Gracz gracz);
    }
    public static class Elektrownia extends Pole
    {
        int cena;
        int czyja;
        boolean hipoteka;
        int czynsz;
        String wybranaOpcja = "-1";

        Elektrownia(String nazw, boolean ZakupOK , int price, int whose, boolean hipotek, int Czynsz)
        {
            super(nazw,  ZakupOK);
            cena=price; czyja=whose; hipoteka=hipotek; czynsz=Czynsz;
        }
        void czyja1(int i){}
        int f(){return 3;}
        int f1(){return 3;}
        String fun()
        {
            return "Jestem funkcją fun z klasy Elektrownia i nic nie robię!!!!!!!!!!!!!!1";
        };

        String fun(Plansza p, Gracz gracz){
            String stringWyjściowy = "Następny Gracz.";
            if(czyja!=-1 && !gracz.własnościGracza.contains(gracz.pozNaPlanszy))
            {
                if (gracz.stanKonta < czynsz)
                {
                    if (gracz.własnościGracza.size() == 0)
                    {
                        JOptionPane.showMessageDialog(null, "7) Graczu stoisz na polu: "+ nazwa
                                + "\n które należy do "+ czyja
                                +"\n musisz zapłacić czynsz, wynoszący " + czynsz
                                + "\n nie masz wystarczająco dużo gotówki na koncie: "+ gracz.stanKonta +"PLN "
                                + "\nAni nie posiadasz nieruchomości na sprzedarz by zapłacić czynsz.\n BANKRUTUJESZ i ODPADASZ Z GRY!!!!!!" );
                        p.iluBankrótów++;
                        gracz.aktyw = false;
                        gracz.bankrut = true;
                        return "Gra toczy się nadal.";
                    }
                    while(true)
                    {
                        if(gracz.stanKonta < czynsz)
                        {
                            JOptionPane.showMessageDialog(null, "6) Graczu stoisz na polu: " + nazwa
                                    + "\n które należy do " + czyja
                                    + "\n musisz zapłacić czynsz, wynoszący " + czynsz
                                    + "\n nie masz wystarczająco dużo gotówki, masz na koncie: " + gracz.stanKonta + "PLN "
                                    + "\n1. Sprzedaj nieruchomość by zapłacić czynsz.");
                            gracz.sprzedajNieruchomość(p, gracz);
                        }
                        break;
                    }
                }
                JOptionPane.showMessageDialog(null, "5) Graczu stoisz na polu: " + nazwa
                        + "\n które należy do "+ czyja
                        +"\n musisz zapłacić czynsz, wynoszący " + czynsz
                        + "\n masz na koncie: "+ gracz.stanKonta +"PLN "
                         );
                gracz.stanKonta -= czynsz;
                p.gracz[czyja].stanKonta += czynsz;
                return "Zapłaciłeś czynsz.";
            }
            if(gracz.własnościGracza.contains(gracz.pozNaPlanszy))
            {

                wybranaOpcja = JOptionPane.showInputDialog(null, "4) Graczu stoisz na "+ nazwa
                        + "\n której jesteś właścicielem, masz na koncie: "+ gracz.stanKonta +"PLN "
                        + "Czy chcesz zaciągnąć hipoteke;"
                        + "\n1. Tak."
                        + "\n2. Nie.");

                switch (wybranaOpcja.charAt(0))
                {
                    case '1':
                        p.bankier.setHipoteka(p, czyja, gracz);
                        break;
                    case '2':
                        return "Następny zawodnik.";
                }
            }
            if(czyja==-1)
            {
                if (gracz.stanKonta >= cena) wybranaOpcja = "1";
                else wybranaOpcja = "0";

                switch (wybranaOpcja.charAt(0))
                {
                    case '1':
                        wybranaOpcja = JOptionPane.showInputDialog(null, "2) Graczu stoisz na polu: " + nazwa
                                + "\n które można kupić za:" + cena +" PLN "
                                + "\n masz na koncie: "+ gracz.stanKonta +" PLN "
                                + "\nco chcesz zrobić?:"
                                + "\n1. Kup ulice."
                                + "\n2. Pokaż moje nieruchomości."
                                + "\n3. Nic nie rób.");
                        switch (wybranaOpcja.charAt(0))
                        {
                            case '1':
                                gracz.stanKonta -= cena;
                                gracz.własnościGracza.add(gracz.pozNaPlanszy);
                                this.czyja = gracz.indeksGracza;
                                return "Kupiłeś Pole "+ this.nazwa;
                            case '2':
                                gracz.pokaWłości(p);
                                break;
                            case '3':
                                return stringWyjściowy;
                        }
                        break;
                    case '0':
                        wybranaOpcja = JOptionPane.showInputDialog(null, "2) Graczu stoisz na polu: " + nazwa
                                + "\n którego nie możesz kupić za:" + cena +" PLN "
                                + "\n masz na koncie: "+ gracz.stanKonta +" PLN "
                                + "\nco chcesz zrobić?:"
                                + "\n1. Pokaż moje nieruchomości."
                                + "\n2. Nic nie rób.");
                        switch (wybranaOpcja.charAt(0))
                        {
                            case '1':
                                gracz.pokaWłości(p);
                                break;
                            case '2':
                                return stringWyjściowy;
                        }
                        break;
                }

            }
            return stringWyjściowy;
        };
    }
    public static class Ulica extends Elektrownia
    {
        int cenaDomu;
        int cenaHotelu;
        int ileDomów;
        int ileHoteli;
        Ulica(String nazw, boolean buyOK, int ileZaNieruchomość, int Czyje, boolean hipo, int ileKomuZaPobyt, int cenDom, int cenHot, int liczDomy, int liczHot )
        {
            super(nazw,  buyOK, ileZaNieruchomość, Czyje, hipo, ileKomuZaPobyt );
            cenaDomu=cenDom; cenaHotelu=cenHot; ileDomów=liczDomy; ileHoteli=liczHot;
        }
        int f(){return cena;}
        int f1(){return czyja;}
        String fun(){return String.valueOf(cena);}
        String fun(Plansza p, Gracz gracz)
        {
            int które;
            String stringWyjściowy = "Następny Gracz.";

            if(nazwa == "Start")
            {
                JOptionPane.showMessageDialog(null, "3) Gracz nr: stoisz na polu start," +
                        "\n masz na koncie: "+ gracz.stanKonta +" PLN "
                        + ", powodzenia w grze");
                return stringWyjściowy;
            }

            if(czyja!=-1 && !gracz.własnościGracza.contains(gracz.pozNaPlanszy))
            {
                if (gracz.stanKonta < czynsz)
                {
                    if (gracz.własnościGracza.size() == 0)
                    {
                        JOptionPane.showMessageDialog(null, "7) Graczu stoisz na polu: "+ nazwa
                                + "\n które należy do "+ czyja
                                +"\n musisz zapłacić czynsz, wynoszący " + czynsz
                                + "\n nie masz wystarczająco dużo gotówki na koncie: "+ gracz.stanKonta +"PLN "
                                + "\nAni nie posiadasz nieruchomości na sprzedarz by zapłacić czynsz.\n BANKRUTUJESZ i ODPADASZ Z GRY!!!!!!" );
                        p.iluBankrótów++;
                        gracz.aktyw = false;
                        gracz.bankrut = true;
                        return "Gra toczy się nadal.";
                    }
                    while(true)
                    {
                        if(gracz.stanKonta < czynsz)
                        {
                            JOptionPane.showMessageDialog(null, "6) Graczu stoisz na polu: " + nazwa
                                    + "\n które należy do " + czyja
                                    + "\n musisz zapłacić czynsz, wynoszący " + czynsz
                                    + "\n nie masz wystarczająco dużo gotówki, masz na koncie: " + gracz.stanKonta + "PLN "
                                    + "\n1. Sprzedaj nieruchomość by zapłacić czynsz.");
                            gracz.sprzedajNieruchomość(p, gracz);
                        }
                        break;
                    }
                }
                JOptionPane.showMessageDialog(null, "5) Graczu stoisz na polu: " + nazwa
                        + "\n które należy do "+ czyja
                        +"\n musisz zapłacić czynsz, wynoszący " + czynsz
                        + "\n masz na koncie: "+ gracz.stanKonta +"PLN "
                );
                gracz.stanKonta -= czynsz;
                p.gracz[gracz.indeksGracza].stanKonta += czynsz;
                return "Zapłaciłeś czynsz.";
            }
            if(gracz.własnościGracza.contains(gracz.pozNaPlanszy))
            {
                if(ileDomów < 4)
                {
                    wybranaOpcja = JOptionPane.showInputDialog(null, "4) Graczu stoisz na "+ nazwa
                            + "\n której jesteś właścicielem, masz na koncie: "+ gracz.stanKonta +"PLN "
                            + "\n masz następujące możliwości;"
                            + "\n1. kupić domek."
                            + "\n2. sprzedać ulicę."
                            + "\n3. zaciągnąć hipoteke."
                            + "\n4. Nic nie rób.");

                    switch (wybranaOpcja.charAt(0))
                    {
                        case '1':
                            gracz.stanKonta -= cenaDomu;
                            gracz.własnościGracza.add(gracz.pozNaPlanszy);
                            ileDomów++;
                            return "Kupełeś dom";
                        case '2':
                            gracz.stanKonta += cena;
                            gracz.własnościGracza.remove(gracz.pozNaPlanszy);
                            czyja = -1;
                            ileDomów = 0;
                            ileHoteli = 0;
                            return "Sprzedałeś nieruchomość.";
                        case '3':
                           gracz.stanKonta += cena;
                           hipoteka = true;
                           return "Zaciągnąłeś kredyt pod hipotekę.";
                        case '4':
                            return stringWyjściowy;
                    }
                }
                if(ileDomów == 4 && ileHoteli == 0)
                {
                    if(gracz.stanKonta >= cenaHotelu)
                    {
                        wybranaOpcja = JOptionPane.showInputDialog(null, "4) Graczu stoisz na " + nazwa
                                + "\n której jesteś właścicielem, masz na koncie: " + gracz.stanKonta + "PLN "
                                + "\n masz 4 domy, możesz kupić hotel,"
                                + "\n masz następujące możliwości;"
                                + "\n1. kup hotel"
                                + "\n2. sprzedać ulicę."
                                + "\n3. zaciągnąć hipoteke."
                                + "\n4. Nic nie rób.");

                        switch (wybranaOpcja.charAt(0)) {
                            case '1':
                                gracz.stanKonta -= cenaHotelu;
                                ileDomów = 0;
                                ileHoteli++;
                                return stringWyjściowy;
                            case '2':
                                gracz.stanKonta += cena;
                                gracz.własnościGracza.remove(gracz.pozNaPlanszy);
                                czyja = -1;
                                ileDomów = 0;
                                ileHoteli = 0;
                                return "Sprzedałeś nieruchomość.";
                            case '3':
                                gracz.stanKonta += cena;
                                hipoteka = true;
                                return "Zaciągnąłeś kredyt pod hipotekę.";
                            case '4':
                                return stringWyjściowy;
                        }
                    }
                    else {
                        wybranaOpcja = JOptionPane.showInputDialog(null, "4) Graczu stoisz na " + nazwa
                                + "\n której jesteś właścicielem, masz na koncie: " + gracz.stanKonta + "PLN "
                                + "\n masz 4 domy, masz prawo kupić hotel, ale nie masz środków,"
                                + "\n masz następujące możliwości;"
                                + "\n1. sprzedać ulicę."
                                + "\n2. zaciągnąć hipoteke."
                                + "\n4. Nic nie rób.");

                        switch (wybranaOpcja.charAt(0)) {
                            case '1':
                                gracz.stanKonta += cena;
                                gracz.własnościGracza.remove(gracz.pozNaPlanszy);
                                czyja = -1;
                                ileDomów = 0;
                                ileHoteli = 0;
                                return "Sprzedałeś nieruchomość.";
                            case '3':
                                gracz.stanKonta += cena;
                                hipoteka = true;
                                return "Zaciągnąłeś kredyt pod hipotekę.";
                            case '4':
                                return stringWyjściowy;
                        }
                    }
                }
                if(ileDomów == 0 && ileHoteli == 1)
                {
                    wybranaOpcja = JOptionPane.showInputDialog(null, "4) Graczu stoisz na "+ nazwa
                            + "\n której jesteś właścicielem, masz na koncie: "+ gracz.stanKonta +"PLN "
                            + "\n masz hotel, więcej nieruchomości kupić nie możęssz,"
                            + "\n masz następujące możliwości;"
                            + "\n1. sprzedać ulicę."
                            + "\n2. zaciągnąć hipoteke."
                            + "\n4. Nic nie rób.");

                    switch (wybranaOpcja.charAt(0))
                    {
                        case '1':
                            gracz.stanKonta += cena;
                            gracz.własnościGracza.remove(gracz.pozNaPlanszy);
                            czyja = -1;
                            ileDomów = 0;
                            ileHoteli = 0;
                            return "Sprzedałeś nieruchomość.";
                        case '2':
                            gracz.stanKonta += cena;
                            hipoteka = true;
                            return "Zaciągnąłeś kredyt pod hipotekę.";
                        case '3':
                            return stringWyjściowy;
                    }
                }
            }
            if(czyja==-1)
            {
                if (gracz.stanKonta >= cena) wybranaOpcja = "1";
                else wybranaOpcja = "0";

                switch (wybranaOpcja.charAt(0))
                {
                    case '1':
                        wybranaOpcja = JOptionPane.showInputDialog(null, "2) Graczu stoisz na polu: " + nazwa
                                + "\n które można kupić za:" + cena +" PLN "
                                + "\n masz na koncie: "+ gracz.stanKonta +" PLN "
                                + "\nco chcesz zrobić?:"
                                + "\n1. Kup ulice."
                                + "\n2. Pokaż moje nieruchomości."
                                + "\n3. Nic nie rób.");
                        switch (wybranaOpcja.charAt(0))
                        {
                            case '1':
                                gracz.stanKonta -= cena;
                                gracz.własnościGracza.add(gracz.pozNaPlanszy);
                                czyja = gracz.indeksGracza;
                                return "Kupiłeś Pole "+ this.nazwa;
                            case '2':
                                gracz.pokaWłości(p);
                                break;
                            case '3':
                                return stringWyjściowy;
                        }
                        break;
                    case '0':
                        wybranaOpcja = JOptionPane.showInputDialog(null, "2) Graczu stoisz na polu: " + nazwa
                                + "\n którego nie możesz kupić za:" + cena +" PLN "
                                + "\n masz na koncie: "+ gracz.stanKonta +" PLN "
                                + "\nco chcesz zrobić?:"
                                + "\n1. Pokaż moje nieruchomości."
                                + "\n2. Nic nie rób.");
                        switch (wybranaOpcja.charAt(0))
                        {
                            case '1':
                                gracz.pokaWłości(p);
                                break;
                            case '2':
                                return stringWyjściowy;
                        }
                        break;
                }

            }
            return stringWyjściowy;

        };
    }

    public  static  class Ubezpieczalnia extends Pole{
        public Ubezpieczalnia(String nazw, boolean ZakupOK )
        {
            super(nazw,  ZakupOK);
        }
        String fun()
        {
            return "Jestem funkcją fun z klasy Ubezpieczalnia i nic nie robię!!!!!!!!!!!!!!1";
        };

         int f(){return  2;}
         void czyja1(int i){}
         int f1(){return  2;}
        String fun(Plansza p, Gracz gracz)
        {
            int intedżer = 0;
            String str = "";
            int baza = 0;
            for (Integer i : gracz.własnościGracza)
            {
                intedżer += p.pola[i].f();
                str += ", "+ p.pola[i].nazwa;
            }
            baza = intedżer;
            intedżer = (int)(Math.round(intedżer*0.01));
            JOptionPane.showMessageDialog(null, "Jesteś właścicielem: "+str+ "\n warte: "+baza);

            return "Pobrano ubezpieczenie w kwocie."+intedżer;
        }
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
                if((plansza.gracz[któryGracz].pozNaPlanszy + ileOczek)>plansza.pola.length-1)
                {
                    plansza.gracz[któryGracz].pozNaPlanszy -= plansza.pola.length;
                    JOptionPane.showMessageDialog(null, "Przekroczyłeś pole START otrzymujesz 200PLN, masz na koncie: "+ plansza.gracz[któryGracz].stanKonta );
                }

                plansza.gracz[któryGracz].pozNaPlanszy += ileOczek;
                indexPlanszy = plansza.gracz[któryGracz].pozNaPlanszy;

                JOptionPane.showMessageDialog(null, "1) Gracz nr: "+ któryGracz +"\n Rzuciłęś kostką, wypadło: "+ileOczek+" oczek" );

                //plansza.pola[indexPlanszy].fun(plansza, plansza.gracz[któryGracz]);

                JOptionPane.showMessageDialog(null, plansza.pola[indexPlanszy].fun(plansza, plansza.gracz[któryGracz]) );















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


