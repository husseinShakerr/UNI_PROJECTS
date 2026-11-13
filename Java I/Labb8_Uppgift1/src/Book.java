package java1.media;


public class Book extends Media {
    private String author;

    public Book(String Author, String Title, int Length, Publisher Publisher){
        super(Title, Length, Publisher);
        this.author = Author;
        setLength(Length);
    }
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
        return "Title: " + title + "\n" + "Author: " + author + "\n" + "Length: " + getLengthAsString() + "\n" + "Publisher: " + publisher.getName();
    }
}
