/**
 * Filnamn: MediaTest.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-23
 * Beskrivning: Main fil.
 */

public class MediaTest {
    public static void main(String[]args){
        Publisher p1 = new Publisher();
        p1.setName("HASSES AB");
        Publisher p2 = new Publisher();
        p2.setName("meharis");
        DVD D1 = new DVD("Fight club", 5440, 18, p1);
        Book B1 = new Book("Hamza K", "Hala", -800, p1);
        CD CD1 = new CD("Don't", "Ed Sheeran", -520, p2);
        System.out.println(D1.toString());
        System.out.println(B1.toString());
        System.out.println(CD1.toString());

        DVD D2 = new DVD();
        D2.setTitle("Rush Hour");
        D2.setLength(5415);
        D2.setAgeLimit(15);
        D2.setPublisher("New Line Cinema", "0769511654");

        Book B2 = new Book();
        B2.setTitle("A song of ice and fire");
        B2.setAuthor("George R.R Martin");
        B2.setLength(-892);
        B2.setPublisher("Harper Collins", "0732996569");

        CD CD2 = new CD();
        CD2.setArtist("Dave, Burna boy");
        CD2.setTitle("Location");
        CD2.setLength(-230);
        CD2.setPublisher("Neighbourhood Recordings", "00000");

        System.out.println(D2.toString());
        System.out.println(B2.toString());
        System.out.println(CD2.toString());


        Media M1 = new Media();
        M1.setLength(-234);
        M1.setTitle("KERf");
        M1.setPublisher("oejf", "087652");
        Media M2 = new Media("LAKK", -234, p2);
        System.out.println(M1.toString());
        System.out.println(M2.toString());
    }
}
