/**
 * Filnamn: CD.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-20
 * Beskrivning: CD klass fil. Klassen innehåller artist, titel och längd
 */

public class CD {
    private String Artist, Title;
    private int length;
    private Publisher CDpublisher;
    //Dessa är getters och setters  som hämtar och sätter nytt värde utanför klassen.
    public String getArtist(){
        return Artist;
    }
    public void setArtist(String artist){
        this.Artist = artist;
    }
    public String getTitle(){
        return Title;
    }
    public void setTitle(String title){
        this.Title = title;
    }
    public void setCDPublisher(Publisher CDpub){
        this.CDpublisher = CDpub;
    }
    public void setCDPublisher(String publisherName, String publisherPhonenr){
        Publisher PB = new Publisher();
        PB.setName(publisherName);
        PB.setPhoneNumber(publisherPhonenr);
        this.CDpublisher = PB;
    }

    public Publisher getCDpublisher() {
        return CDpublisher;
    }
    public void setLength(int length){
        this.length = length;
    }
    public int getLength(){
        return length;
    }
    //Denna parametricerad konstruktor används för att dela instansen till sig själv.
    public CD(String title, String artist, int length, Publisher CDpublisher){
        this.Title = title;
        this.Artist = artist;
        this.length = length;
        this.CDpublisher = CDpublisher;
    }
    public CD(String title, String artist, int length,String publisherName, String publisherPhonenr){
        this.Title = title;
        this.Artist = artist;
        this.length = length;
        setCDPublisher(publisherName, publisherPhonenr);
    }

    @Override
    public String toString() {
        return "----------------------------\n"+ "Title: "+Title + "\nArtist: " +Artist + "\nLength(Sec): " + length + "\nPublisher: " + CDpublisher.getName();
    }
}
