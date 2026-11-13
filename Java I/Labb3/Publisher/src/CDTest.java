/**
 * Filnamn: CDTest.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-20
 * Beskrivning: Main fil. I denna fil skapar jag nya objekt av klassen CD. Tredje objektet
 * ber jag användare att skriva in CD info samt publisher namn med hjälp av
 * JOptionPane. Infon skrivs ut med hjälp av toString() som ligger
 * i filen CD.java.
 */

import javax.swing.*;
import javax.swing.text.html.parser.Parser;
import java.util.Scanner;

public class CDTest {
    public static void main(String[]args){
        String Title, Artist;
        int length;
        CD CD1 = new CD("Young & Heartless", "Yasin", 145, "BynBlocket", "BRKN Records");
        CD CD2 = new CD("Malaika", "Antwan", 189, "WBM", "063-343 34 23");
        System.out.println(CD1.toString());
        System.out.println(CD2.toString());


        Publisher cdpub = new Publisher();
        cdpub.setName(JOptionPane.showInputDialog("""
                Enter publisher name:
                """));
        cdpub.setPhoneNumber(JOptionPane.showInputDialog("""
                Enter publisher phone number: 
                """));
        Artist = JOptionPane.showInputDialog("""
                Enter artist name: 
                """);
        Title = JOptionPane.showInputDialog("""
                Enter CD title: """);
        length = Integer.parseInt(JOptionPane.showInputDialog("""
                Enter CD length(Sec): 
                """));

        CD CD3 = new CD(Title, Artist, length, cdpub);
        System.out.println(CD3);
        Publisher.pubAmount();
    }
}
