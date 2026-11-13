/**
 * Filnamn: word_checker.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-28
 * Beskrivning: Main fil.
 */

import java.io.*;
import java.util.Scanner;

public class word_checker {
    public static void main(String[] args) {
        String FileName, word;
        FileName="wordlist1.txt";
        if(args.length == 1)
            FileName = args[0];
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the word you want to search for: ");
        word = input.nextLine();
        try{
            //Skapar File objekt med rätt parameter som användare har matat in filnamn i terminal.
            File fil = new File(FileName);
            //Skapar Scanner som skall läsa filen.
            Scanner reader = new Scanner(fil);
            int amount_words = 0, nOtimesFound = 0;
            //Hämtar tid precis när läsning av fil börjar.
            long startTime = System.currentTimeMillis();
            while(reader.hasNextLine()){
                String line = reader.nextLine();
                amount_words++;
                if(line.contains(word)){ //Om String "line" innehåller sökordet, ökas värdet av nOtimesFound.
                    nOtimesFound++;
                }
            }
            long endTime = System.currentTimeMillis(); //Hämtar tid vid när angivna filen är slut.
            reader.close();
            System.out.println(STR."Amount of words in this file: \{amount_words}");
            System.out.println(STR."Number of times your words was found in this file: \{nOtimesFound}");
            System.out.println(STR."The search took \{endTime - startTime} ms");
        }
        //Ifall filen inte hittas.
        catch (FileNotFoundException e){
            System.out.println(STR."File not found. \{e.getMessage()}");
        }
        input.close();
    }
}
