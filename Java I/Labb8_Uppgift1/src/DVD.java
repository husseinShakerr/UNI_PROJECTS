package java1.media;


public class DVD extends Media {
    private int ageLimit;

    public DVD(String Title, int Length, int ageLimit, Publisher publisher) {
        super(Title, Length, publisher);
        setAgeLimit(ageLimit);
    }
    public DVD(){}

    public void setAgeLimit(int ageLimit) {
        if(ageLimit < 0)
            this.ageLimit = 0;
        else
            this.ageLimit = ageLimit;
    }

    public int getAgeLimit() {
        return ageLimit;
    }
    public String getLengthAsString(){
        int hours = length / 3600;
        int minutes = (length % 3600) / 60;
        int seconds = (length % 60);
        if(hours < 0)
            return String.format("%02d:%02d:%02d", 0, 0, 0);
        if(minutes < 0)
            return String.format("%02d:%02d:%02d", 0, 0, 0);
        if(seconds < 0)
            return String.format("%02d:%02d:%02d", 0, 0, 0);
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }
    @Override
    public void print(){}
    @Override
    public String toString(){
        return "Title: " + title + "\n" + "Lenght: " + getLengthAsString() + "\n" + "Age Limit: " + ageLimit + "\n" + "Publisher: " + publisher.getName();
    }
}
