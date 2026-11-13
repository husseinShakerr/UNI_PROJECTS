/**
 * Filnamn: Publisher.java
 * @Author: Hussein Shaker
 * @Version 1.0
 * Datum: 2024-02-22
 * Beskrivning: Publisher klass. Hämtad från laboration 3. Två instansvariabler,
 * name och phoneNumber.
 */

import javax.swing.*;


public class Publisher {
    private String name, phoneNumber;

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

}
