import java.util.ArrayList;

public class Usernames {
    public static ArrayList<String> create(String[] names){
        ArrayList<String> usernames = new ArrayList<String>();
        for (String name : names){
            String[] parts = name.split(" ");
            String firstName = parts[0];
            String surname = parts[1];
            String username =  generateUsername(firstName, surname);
            usernames.add(username);
        }
        return usernames;
    }
    public static String generateUsername(String firstName, String surname){
        String firstPart = firstName.substring(0, Math.min(3, firstName.length())).toLowerCase();
        String secondPart = surname.substring(0, Math.min(3, surname.length())).toLowerCase();
        return firstPart + secondPart;
    }
    public static void list(String[] names, ArrayList<String> usernames){
        for (int i = 0; i < names.length; i++){
            System.out.println(STR."NAME: \{names[i]}");
            System.out.println(STR."USERNAME: \{usernames.get(i)}");
            System.out.println(STR."---------------------");
        }
    }
}
