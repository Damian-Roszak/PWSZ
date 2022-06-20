package com.company;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.io.*;

class Kolorki extends JFrame {

    public Kolorki(int [] priorytet, int pauza, boolean tlo) {
        super("A miał być Fraktal :D");
        setSize(800,350);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container kontener = getContentPane();
        kontener.setLayout(new GridLayout(2,5));
        for (int i = 0; i < 10; i++) {
            kontener.add(new Main(priorytet[i], pauza, tlo));
        }
        setVisible(true);
    }
}

public class Main extends JPanel implements Runnable {
    private Thread watek;
    private int pauza;
    private boolean tlo;
    private static Random rnd = new Random();
    private static Color[] tablica_kolorowa = {Color.BLACK, Color.BLUE, Color.CYAN, Color.DARK_GRAY, Color.MAGENTA, Color.ORANGE, Color.RED, Color.GREEN,Color.YELLOW, Color.WHITE};
    private static Random sierotka = new Random();
    private static  Color nowyKolor(){return tablica_kolorowa[sierotka.nextInt(tablica_kolorowa.length)];}

    int licznik = 0;

    public void paintComponent(Graphics g) {
        licznik++;
        var x = rnd.nextInt(20);
        super.paintComponent(g);
        if(tlo) {
            //g.setFont();
            g.setColor(Color.BLACK);
            g.drawString(Integer.toString(licznik), 40, 40);
            setBackground(nowyKolor());
            g.setColor(nowyKolor());
            g.drawRect(x + 70, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 80, x + 80, 50, 50);
            g.setColor(nowyKolor());
            g.drawRect(x + 70, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 70, x + 80, 50, 50);
            g.setColor(nowyKolor());
            g.drawArc(x + 70, x + 80, 50, 50, 60, 34);
            g.setColor(nowyKolor());
            g.drawOval(x + 80, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 20, x + 20, 20, 20);
            g.setColor(nowyKolor());
            g.drawLine(x, x + x, x * x, x / 2);
        }
        else{
            g.setColor(Color.BLACK);
            g.drawString(Integer.toString(licznik), 40, 40);
            g.setColor(nowyKolor());
            g.drawRect(x + 70, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 80, x + 80, 50, 50);
            g.setColor(nowyKolor());
            g.drawRect(x + 70, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 70, x + 80, 50, 50);
            g.setColor(nowyKolor());
            g.drawArc(x + 70, x + 80, 50, 50, 60, 34);
            g.setColor(nowyKolor());
            g.drawOval(x + 80, x + 70, 50, 50);
            g.setColor(nowyKolor());
            g.drawOval(x + 20, x + 20, 20, 20);
            g.setColor(nowyKolor());
            g.drawLine(x, x + x, x * x, x / 2);
        }
    }


    public Main(int priorytet, int pauza, boolean tlo) {
        this.pauza = pauza;
        this.tlo = tlo;
        watek = new Thread(this);
        watek.setPriority(priorytet);
        watek.start();
    }
    @Override
    public void run() {
        while (true) {
            repaint();
            try {
                watek.sleep(pauza);
            }
            catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {

        String z = "nie";
        String s;
        InputStreamReader StrumienWejsciowy = new InputStreamReader(System.in);
        BufferedReader BuforWejściowy = new BufferedReader(StrumienWejsciowy);
        int tPriority[] = new int[10];
        int paus;


        while (z !="z") {
            System.out.println("Wybierz opcje:");
            System.out.println("1. z tłem priorytet ustalany ręcznie:");
            System.out.println("2. bez tła priorytet ustalany ręcznie:");
            System.out.println("3. z tłem i z automatycznie przydzielanym priorytetem:");
            System.out.println("4. bez tła i z automatycznie przydzielanym priorytetem:");
            System.out.println("5. Zakończ:");
            System.out.print("Jaki wybór:");
            //System.out.print();
            try
            {
                z = BuforWejściowy.readLine();
                switch (z.charAt(0)) {
                    case '1':
                        System.out.print("Jaka pauza:");
                        s = BuforWejściowy.readLine();
                        paus = Integer.parseInt(s);
                        for (int i = 0; i < 10; i++){
                            System.out.print("Jaki priorytet dla wątku nr "+ i + " :");
                            s = BuforWejściowy.readLine();
                            tPriority[i] = Integer.parseInt(s);
                        }
                        Kolorki kolory = new Kolorki(tPriority, paus, true );
                        break;

                    case '2':
                        System.out.print("Jaka pauza:");
                        s = BuforWejściowy.readLine();
                        paus = Integer.parseInt(s);
                        for (int i = 0; i < 10; i++){
                            System.out.print("Jaki priorytet dla wątku nr "+ i + " :");
                            s = BuforWejściowy.readLine();
                            tPriority[i] = Integer.parseInt(s);
                        }
                        Kolorki koloryBezTła = new Kolorki(tPriority, paus, false );
                        break;

                    case '3':
                        System.out.print("Jaka pauza:");
                        s = BuforWejściowy.readLine();
                        paus = Integer.parseInt(s);
                        for (int i = 0; i < 10; i++){
                            tPriority[i] =  i+1;
                        }
                        Kolorki koloryTłoAuto = new Kolorki(tPriority, paus, true );
                        break;

                    case '4':
                        System.out.print("Jaka pauza: ");
                        s = BuforWejściowy.readLine();
                        paus = Integer.parseInt(s);
                        for (int i = 0; i < 10; i++){
                            tPriority[i] = i+1;
                        }
                        Kolorki koloryBezTłaAuto = new Kolorki(tPriority, paus, false );
                        break;
                    case '5':
                        z="z";
                        return;
                }
            }
            catch(IOException e)
            {
                e.printStackTrace();
                return;
            }
            catch(NumberFormatException e)
            {
                e.printStackTrace();
                return;
            }

        }
    }
}
