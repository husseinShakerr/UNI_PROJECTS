import java.io.*;
import java.util.*;


public class Main {
    public static int totalMen;
    public static int totalWomen;
    public static int total;
    public static int counter = -1;


    public static void main(String[] args) {
        String temp;
        try {
            Scanner reader = new Scanner(new File("befolkning2050.txt"));
            System.out.printf("%-5s%-12s%n", "Age" ,"Quantity");
            System.out.println("------------------");
            while (reader.hasNextLine()){
                String line = reader.nextLine();
                if(line.length() <= 3) {
                    counter++;
                    continue;
                }
                temp = line.trim();
                String [] parts = temp.split("\\s+", -1);
                int menTemp = Integer.parseInt(parts[1]);
                temp = reader.nextLine().trim();
                String [] parts1 = temp.split("\\s+", -1);
                int tempWomen = Integer.parseInt(parts1[1]);
                total = tempWomen + menTemp;
                System.out.println(counter + "     " + total);
            }
        }
        catch (IOException e){
            System.out.println(e.getMessage());
        }
    }

    public String toString(){
        return String.format("%-4ss%-12s%n", counter, totalMen+totalWomen);
    }
}