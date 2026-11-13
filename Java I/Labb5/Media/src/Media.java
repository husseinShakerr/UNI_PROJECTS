/**
 * Filnamn: Media.java
 * @Author: Hussein Shaker
 * @Version 2.0
 * Datum: 2024-02-23
 * Beskrivning: Superklass med 3 variabler, title, length och publisher.
 * Konstruktor med parametrar samt en default som sätter alla instanser till "default".
 * Setters och getters som sätter värden på instanser om man önskar använda default
 * konstruktorn samt en toString som överskuggats i subklasserna.
 */

public class Media {
    protected String title;
    protected int length;
    protected Publisher publisher;

    public Media(String Title, int Length, Publisher publisher){
        this.title = Title;
        this.length = (Length < 0) ? 0 : Length;
        this.publisher = publisher;
    }
    public Media(){
        this.title = "Untitled";
        this.length = 0;
        this.publisher = new Publisher();
    }

    public String getTitle(){
        return title;
    }
    public void setTitle(String title){
        this.title = title;
    }
    public int getLength(){
        return length;
    }
    public void setLength(int length){
        if(length < 0)
            this.length = 0;
        else
            this.length = length;
    }
    public Publisher getPublisher(){
        return publisher;
    }
    public void setPublisher(Publisher publisher){
        this.publisher = publisher;
    }
    public void setPublisher(String name, String phone){
        this.publisher.setName(name);
        this.publisher.setPhoneNumber(phone);
    }
    public void print(){}
    public String toString(){
        return STR."""
                Title: \{title}
                Length: \{length}
                Publisher: \{publisher.getName()}
                """;
    }
}