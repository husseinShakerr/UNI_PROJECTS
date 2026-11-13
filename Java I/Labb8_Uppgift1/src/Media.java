package java1.media;

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
        return "Title: " + title + "\n" + "Length: " + length + "\n" + publisher.getName() + "\n\n";
    }
}