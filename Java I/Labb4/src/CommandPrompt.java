/**
 * Filnamn: CommandPrompt.java
 * @Author: Hussein Shaker
 * @Version: 1.0
 * Datum: 2024-02-20
 * Beskrivning: I denna fil har jag klass samt main.
 */

import java.util.Scanner;
import javax.swing.*;

public class CommandPrompt {
    public static void Command() {
        String userInput;
        Scanner input = new Scanner(System.in);
        System.out.print("input>");
        userInput = input.nextLine().toLowerCase();
        //Använder switch för val av command.
        switch (userInput) {
            case "help":
                System.out.println(STR."""
                        The following commands are valid:
                        
                        help ⟹ Show valid inputs.     
                        calculate or calc ⟹ Perform a simple mathematical calculation.
                        hello ⟹ Print greeting to screen.
                        odd ⟹ Check if a digit is odd or even.
                        repeat ⟹ Print a string as many times as wished.
                        quit or q ⟹ Quit program.
                        """);
                break;
            case "calc":
            case "calculate":
                int userInt1, userInt2;
                String AddSubMul;
                System.out.println("Enter +, -, /, or *");
                AddSubMul = input.nextLine();
                //Använder en till switch då det finns 4 val i "calc/calculator".
                switch (AddSubMul) {
                    case "+":
                        System.out.println("Enter the 1st integer: ");
                        userInt1 = input.nextInt();
                        System.out.println("Enter the 2nd integer: ");
                        userInt2 = input.nextInt();
                        System.out.println(userInt1 + " + " + userInt2 + " = " + (userInt1 + userInt2));
                        break;
                    case "-":
                        System.out.println("Enter the 1st integer: ");
                        userInt1 = input.nextInt();
                        System.out.println("Enter the 2nd integer: ");
                        userInt2 = input.nextInt();
                        System.out.println(userInt1 + " - " + userInt2 + " = " + (userInt1 - userInt2));
                        break;
                    case "/":
                        //Använder double för mina variabler.
                        double int1, int2;
                        System.out.println("Enter the 1st integer: ");
                        int1 = input.nextDouble();
                        System.out.println("Enter the 2nd integer: ");
                        int2 = input.nextDouble();
                        System.out.println(int1 + " / " + int2 + " = " + (int1 / int2));
                        break;
                    case "*":
                        System.out.println("Enter the 1st integer: ");
                        userInt1 = input.nextInt();
                        System.out.println("Enter the 2nd integer: ");
                        userInt2 = input.nextInt();
                        System.out.println(userInt1 + " * " + userInt2 + " = " + (userInt1 * userInt2));
                        break;
                    default:
                        System.out.println("Inavlid command, try again!");
                        break;
                }
                break;
            case "hello":
                System.out.println(STR."""
                        Hello World!
                        """);
                break;
            case "odd":
                System.out.println("Enter an integer to check if it is an odd or even integer: ");
                userInt1 = input.nextInt();
                if(userInt1 % 2 == 0)
                    System.out.println(userInt1 + " is even.");
                else
                    System.out.println(userInt1 + " is odd.");
                break;
            case "repeat":
                System.out.println("Type a small text.");
                userInput = input.nextLine();
                System.out.println("Enter a digit.");
                userInt1 = input.nextInt();
                //for-loop som skriver ut texten lika många gånger som användaren väljer.
                for(int i = 0; i < userInt1; i++){
                    System.out.println(userInput);
                }
                break;
            case "q":
            case "quit":
                System.out.println("Exiting terminal...");
                System.exit(1);
            default:
                System.out.println("Invalid command, try again!");
                break;
            }
        }

    public static void main(String[]args){
        boolean terminal = true;
        //While-loop som alltid är true tills man väljer case "q" eller "quit" i klassen command.
        while(terminal) {
            Command();
        }
    }
}
