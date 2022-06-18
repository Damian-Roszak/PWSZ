package com.company;
import java.io.*;

public class Main {

    public static void main(String[] args) {
	// write your code here
    String s;
    System.out.print("Podaj ile ocen chcesz wprowadzić: ");

    double [] d;
    int rozmiar;
    double suma = 0;
        InputStreamReader StrumienWejsciowy = new InputStreamReader(System.in);
        BufferedReader BuforWejściowy = new BufferedReader(StrumienWejsciowy);

        //System.out.print();
        try
        {
            s = BuforWejściowy.readLine();
            rozmiar = Integer.parseInt(s);
            d = new double[rozmiar];
            //System.out.println();

            for(int i=0; i<rozmiar; i++)
            {
                System.out.print("Podaj element nr="+(i+1)+": ");
                s = BuforWejściowy.readLine();
                d[i] = Double.parseDouble(s);
                if (d[i]<1 || d[i]>6) i--;
                else suma += d[i];
            }
            suma /= d.length;
            System.out.println("Twoja średnia wynosi="+suma);
            if(suma>4.1) System.out.print("Twoja średnia daje ci prawo do ubiegania się o stypendium naukowe");
            else System.out.print("Za niska średnia na stypendium naukowe");
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
