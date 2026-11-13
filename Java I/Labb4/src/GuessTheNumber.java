/**
 * Filnamn: GuessTheNumber.java
 * @Author: Hussein Shaker
 * @Version: 1.0
 * Datum: 2024-02-20
 * Beskrivning: Main fil där jag har skapat spelet Guess the number.
 */

import javax.swing.*;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

import static java.lang.StringTemplate.STR;

public class GuessTheNumber {
    public static void main(String[] args) {
        boolean play = true;
        int randomNumber, userInt1, userInt2;
        int counter = 0, userGuess = 0;
        Scanner input = new Scanner(System.in);
        String userInput;
        System.out.println(STR."""
                ►►►Welcome to Guess the number!◄◄◄
                """);
        //Denna while-loop är alltid true tills man matar in "n" och avslutar programmet.
        while(play){
        System.out.print(STR."""           
                ↓ Enter "Y" or "N" to play or exit ↓
                """);
        userInput = input.next().toUpperCase();
        if(userInput.equals("N")) {
            System.out.println("Exiting program...");
            System.exit(1);
        }
        //Om userInput inte är "Y" så fortsätter loopen.
        else if(!userInput.equals("Y")){
            System.out.println(STR."""
                    ××× Invalid input, try again! ×××
                    """);
            continue;
        }
        //Annars så fortsätter spelet.
            System.out.print(STR."""
                    • Choose an interval of integers to guess a number between the
                    lower and the higher integer.
                    """);
            System.out.println("↓ Enter any integer of your interval:  ↓");
            userInt1 = input.nextInt();
            System.out.println("↓ Enter another integer of your interval: ↓");
            userInt2 = input.nextInt();
            do {
                //Swap funktion.
                if (userInt1 > userInt2) {
                    int X = userInt1;
                    userInt1 = userInt2;
                    userInt2 = X;
                }
                //Skapar slumpmässigt tal.
                randomNumber = ThreadLocalRandom.current().nextInt(userInt1, userInt2);
                System.out.println(STR."""
                        ↓ Enter your guess ↓
                        """);
                userInput = input.next();
                //Om användare vill avsluta programmet. Tar in userGuess som string.
                if (userInput.toLowerCase().equals("exit")) {
                    System.out.println("Exiting program...");
                    System.exit(1);
                }
                //Omvandlar till integer om inmatningen är ett tal.
                try {
                    userGuess = Integer.parseInt(userInput);
                    //Om inmatningen är varken ett tal eller "exit".
                } catch (Exception e) {
                    System.out.println(STR."""
                            ××× Invalid input, try again! ×××
                            """);
                    continue;
                }
                if (userGuess < randomNumber)
                    System.out.println("××× Too low! Try again! ×××");
                if (userGuess > randomNumber)
                    System.out.println("××× Too high! Try again! ×××");
                counter++;
                //Om gissning inte är samma som slumpmässiga talet, fortsätt do-while loopen.
            } while (randomNumber != userGuess);
            //Annars är gissningen korrekt.
            System.out.println(STR."""
                    »»»You guessed right!«««
                    """);
            //Printar antal försök.
            System.out.println("Total attempts: " + counter);
            counter = 0;
        }
    }
}