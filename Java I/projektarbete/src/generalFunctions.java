import java.io.*;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class generalFunctions {

    public static boolean ifArrIsEmpty(ArrayList<Person> AL){
        if(AL.isEmpty()){
            System.out.println("The list is empty");
            System.out.println("--------------------");
            return true;
        }
        else
            return false;
    }
    public static boolean height_check(String _height){
        try {
            int height = Integer.parseInt(_height);
            if(height<=0){
                System.out.println("Height can't be zero or less!");
                return false;
            }
            return true;
        }
        catch (Exception e){
            System.out.println("Height can't contain special characters or letters!");
            return false;
        }
    }
    public static void saveToFile(ArrayList<Person> AL){
        Scanner userInput = new Scanner(System.in);
        System.out.println("Enter file name: ");
        String fileName = userInput.nextLine();
        try {
            FileWriter writer = new FileWriter(fileName, false);
            for (Person person : AL){
                writer.write(person.toString() + "\n");
            }
            writer.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
        }
    }
    public static ArrayList<Person> loadFromFile(){
        ArrayList<Person> PL = new ArrayList<Person>();
        Scanner userinp = new Scanner(System.in);
        System.out.println("Enter file name: ");
        String fileName = userinp.nextLine();
        try {
            Scanner reader = new Scanner(new File(fileName));
            while(reader.hasNextLine()){
                String line = reader.nextLine();
                String [] parts = line.split("\\|");
                Adress tempAdress = new Adress(parts[4],parts[5],parts[6]);
                Person tempPerson = new Person(parts[0],parts[1],parts[2], Integer.parseInt(parts[3]),tempAdress);
                PL.add(tempPerson);
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
        }
        return PL;
    }
    public static void main_menu(){
        System.out.println(STR."""
                Press '1' to add a person to the list.
                Press '2' to print list.
                Press '3' to search a person in the list.
                Press '4' to delete a person from the list.
                Press '5' to sort by name.
                Press '6' to sort by signature.
                Press '7' to sort by height.
                Press '8' to sort randomly.
                Press '9' to save to a file.
                Press '10' to read from a file.
                Press '11' to exit program.
                """);
    }
    public static String generateUserNames(String fName, String sName, ArrayList<Person> AL){
        if(fName.length() == 2)
            fName = fName + "x";
        if(fName.length() == 1)
            fName = fName + "xx";
        if(sName.length() == 2)
            sName = sName + "y";
        if (sName.length() == 1)
            sName = sName + "yy";
        String firstPart = fName.substring(0,Math.min(3, fName.length())).replace(' ','x');
        String secondPart = sName.substring(0,Math.min(3, sName.length())).replace(' ', 'y');
        String sign = firstPart+secondPart;
        int count=1;
        for(Person p : AL){
            if(p.getSignature().contains(sign))
                count++;
        }
        DecimalFormat f = new DecimalFormat("00");
        return sign.toLowerCase() + f.format(count);
    }
}