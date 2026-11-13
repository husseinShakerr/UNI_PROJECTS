/**
 * Filnamn: Publisher.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-20
 * Beskrivning: Publisher klass som innehåller privata variabler, namn telefonnummer
 * och en public räknare för hur många förlag som skapas.
 */


import javax.swing.*;
public class Publisher {
    //Klass variabler.
    private String name, phoneNumber;
    private static int counter;
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public String getPhoneNumber(){
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber){
        this.phoneNumber = phoneNumber;
    }

    //Print metod som skriver ut info om förlag.
    public void PublisherInfo(){
        System.out.println("Publisher name: " + name);
        System.out.println("Publisher phonenumber: " + phoneNumber);
        System.out.println("--------------------------------------");
    }
    //Räknare för hur många förlag som skapas.
    public Publisher(){
        counter++;
    }
    public static void pubAmount(){
        System.out.println("Publishers amount: " + counter);
    }
}
