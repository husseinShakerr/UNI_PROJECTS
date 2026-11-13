import java.util.ArrayList;

public class Usernames_test {
    public static void main(String[]args){
        String[] AddingObject  = new String[10];
        AddingObject[0] = "Bo Ek";
        AddingObject[1] = "My Haglund";
        AddingObject[2] = "Mehari Paolos";
        AddingObject[3] = "Fabian Olsson";
        AddingObject[4] = "My Ek";
        AddingObject[5] = "Karl Hansson";
        AddingObject[6] = "Sven Svensson";
        AddingObject[7] = "Isak Adem";
        AddingObject[8] = "Peter Karlsson";
        AddingObject[9] = "Håkan Hellström";
        ArrayList<String> usernames = Usernames.create(AddingObject);
        Usernames.list(AddingObject, usernames);
    }
}
