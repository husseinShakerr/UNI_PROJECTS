/**
 * Filnamn: PublisherTest1.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-20
 * Beskrivning: Main fil för test 1. Skapar 3 objekt utav klassen Publisher och sätter info för dem
 * och sedan skriver ut dem.
 *
 */

import org.w3c.dom.css.Counter;


public class PublisherTest1{
    public static void main(String[]args){

        Publisher P1 = new Publisher();
        P1.setName("Hasses AB");
        P1.setPhoneNumber("0783984321");

        Publisher P2 = new Publisher();
        P2.setName("Meharis AB");
        P2.setPhoneNumber("0783921647");

        Publisher P3 = new Publisher();
        P3.setName("FreeBooks");
        P3.setPhoneNumber("1234567890");


        P1.PublisherInfo();
        P2.PublisherInfo();
        P3.PublisherInfo();
        Publisher.pubAmount();

    }
}