package java1.media;

public class CD extends  Media{
    private String Artist;
    private Publisher CDpublisher;

    public String getArtist(){
        return Artist;
    }
    public void setArtist(String artist){
        this.Artist = artist;
    }

    public String getLengthAsString(){

        if(length < 0)
            return "0";
        int hours = length / 3600;
        int minutes = (length % 3600) / 60;
        int seconds = (length % 60);
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
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

    public CD(String title, String artist, int length, Publisher CDpublisher){
        super(title, length, CDpublisher);
        this.title = title;
        this.Artist = artist;
        this.length = length;
        this.CDpublisher = publisher;

    }
    public CD(){}

    @Override
    public String toString(){
        return  "Artist: " + Artist + "\n" + "Title: " + title + "\n" + "Length: " + getLengthAsString() + "\n" + "Publisher: " + publisher.getName();
    }
}
