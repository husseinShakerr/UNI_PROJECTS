/**
 * Filnamn: PublisherTest2.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-20
 * Beskrivning: Main fil för test 2.
 */

import javax.swing.*;
import java.util.concurrent.Flow;


public class PublisherTest2 {
    public static void main(String[] args) {
        String choice, name, phoneNumber;
        /*Do-while loop som ber användare att lägga till publisher info.
        Hoppar av loopen när användare matar in "n" eller "N".
        */
        do {
            String userInput = JOptionPane.showInputDialog("""
                    Press "Y" if you want to create a new publisher.
                    Press "N" if you want to cancel.
                    """);
            choice = userInput.toUpperCase();
            if ("Y".equals(choice)) {
                Publisher publisher = new Publisher();
                name = JOptionPane.showInputDialog("""
                        Enter publisher name:
                        """);
                publisher.setName(name);
                phoneNumber = JOptionPane.showInputDialog("""
                        Enter phone number: 
                        """);
                publisher.setPhoneNumber(phoneNumber);
                publisher.PublisherInfo();
                Publisher.pubAmount();
            } else if ("N".equals(choice)) {
                break;
            } else {
                //Loop för om man matar in något annat än Y eller N.
                while (!"Y".equals(choice) && !"N".equals(choice)) {
                    userInput = JOptionPane.showInputDialog("""
                            Invalid input, Please try again!
                            Press "Y" if you want to create a new publisher.
                            Press "N" if you want to cancel.
                            """).toUpperCase();
                    choice = userInput.toUpperCase();
                }
            }
        }while("Y".equals(choice));
    }
}
