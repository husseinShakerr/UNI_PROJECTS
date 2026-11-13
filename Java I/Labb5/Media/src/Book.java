/**
 * Filnamn: Book.java
 * @Author: Hussein Shaker
 * @Version 1.0
 * Datum: 2024-02-22
 * Beskrivning: Subklass för Media. Denna klass innehåller getters och setters
 * som används för en default konstruktor samt en konstruktor med parametrar.
 * Klassen innehåller även en överskuggad toString metod som returnerar
 * de ärvda titel och publisher name. Den returnerar även length som en string
 * där jag omvandlar datatyp på "length" och till sist författare som är en
 * instansvariabel i själva klassen.
 */

public class Book extends Media {
    private String author;

    //Konstruktor med parametrar.
    public Book(String Author, String Title, int Length, Publisher Publisher){
        super(Title, Length, Publisher);
        this.author = Author;
        setLength(Length);
    }
    //Default konsturkor.
    public Book(){}
    public void setAuthor(String author){
        this.author = author;
    }
    public String getAuthor(){
        return author;
    }
    public String getLengthAsString(){
        return String.valueOf(length) + " pages";
    }
    @Override
    public void print(){}
    @Override
    public String toString(){
        return STR."""
                Title: \{title}
                Author: \{author}
                Length: \{getLengthAsString()}
                Pulisher: \{publisher.getName()}
                """;
    }
}
