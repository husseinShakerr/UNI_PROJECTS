import java.text.DecimalFormat;

public class Person {

    private String FirstName, Surname, Signature;
    private int Height;
    private Adress Adress;

    public Person(String firstName, String surname, String signature, int height, Adress adress){
        this.FirstName = firstName;
        this.Surname = surname;
        this.Signature = signature;
        this.Height = height;
        this.Adress = adress;
    }
    public Person(){}
    public void setFirstName(String firstName){
        this.FirstName = firstName;
    }
    public String getFirstName(){
        return FirstName;
    }
    public void setSurname(String surname){
        this.Surname = surname;
    }
    public String getSurname(){
        return Surname;
    }
    public void setHeight(int length){
        this.Height = length;
    }
    public int getHeight(){
        return Height;
    }
    public void setSignature(String Sign){
        this.Signature = Sign;
    }
    public String getSignature(){
        return Signature;
    }
    public void setAdress(Adress adress){
        this.Adress = adress;
    }
    public Adress getAdress(){
        return Adress;
    }
    public String personInfo(){
        String height = new DecimalFormat("#.00").format((float)Height/100);
        if(Height < 100){
             height = new DecimalFormat("#0.00").format((float)Height/100);
        }
        return String.format("%-12s%-30s%-4s", Signature, (FirstName+ ' ' +Surname), height);
    }
    @Override
    public String toString(){
        return FirstName + "|" + Surname + "|" + Signature + "|" + Height + "|" + Adress.getStreet() + "|" + Adress.getPostalCode() + "|" + Adress.getCity();
    }
}
