public class Adress {
    private String Street, PostalCode, City;

    public Adress(String street, String postalCode, String city){
        this.Street = street;
        this.PostalCode = postalCode;
        this.City = city;
    }

    public String getCity() {
        return City;
    }

    public void setCity(String city) {
        this.City = city;
    }
    public String getStreet(){
        return Street;
    }
    public void setStreet(String street){
        this.Street = street;
    }
    public String getPostalCode(){
        return PostalCode;
    }
    public void setPostalCode(String postalCode){
        this.PostalCode = postalCode;
    }

}
