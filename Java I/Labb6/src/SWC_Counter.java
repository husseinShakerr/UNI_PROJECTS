/**
 * Filnamn: SWC_Counter.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-28
 * Beskrivning: Main fil.
 */

import java.util.Scanner;
import java.util.StringTokenizer;
import static java.lang.StringTemplate.STR;


public class SWC_Counter {
    public static void main(String[] args) {
        boolean X = true;
        Scanner userInput = new Scanner(System.in);
        while (X){
            System.out.print(STR."""
                    Enter text:
                    Press "enter" to quit.
                    """);
            String text = userInput.nextLine().toLowerCase();
            //Om inmatningen inte är tom...
            if(!text.equals("")){
                //Tilldelar Tokenizer objektet alla substrings som når mellanslag i inmatningen.
                StringTokenizer words = new StringTokenizer(text);
                //Tilldelar Tokenizer objektet alla substrings som når angivna tecken i satsen nedan.
                StringTokenizer sentences = new StringTokenizer(text, "?!.\n");
                //Skapar int variabler och tilldelar dem antal ord och meningar.
                int amount_words = words.countTokens();
                int amount_sentences = sentences.countTokens();
                //Antal tecken är bara längden av användarens sträng.
                int characters = text.length();
                System.out.println("Words: " + amount_words);
                System.out.println("Sentences: " + amount_sentences);
                System.out.println("Characters: " + characters);
                System.out.println("--------------------------------");
            }
            //Om inmatningen är tom, while-satsen ovan blir false. 
            if(text.equals("")){
                X = false;
                System.out.println("Exiting program...");
            }
        }
        userInput.close();
    }
}