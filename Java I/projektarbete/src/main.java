import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class main {
    public static void main(String[] args){
        ArrayList <Person> AL = new ArrayList<>();
        Scanner userInput = new Scanner(System.in);
        String choice;
        boolean running = true;
        System.out.println("☻☻☻Welcome to person list☻☻☻");

        while (running) {
            generalFunctions.main_menu();
            choice  = userInput.nextLine();
            switch (choice) {
                case "1":
                    menu.addPerson(AL);
                    break;
                case "2":
                    menu.printPersons(AL);
                    break;
                case "3":
                    menu.searchPerson(AL);
                    break;
                case "4":
                    menu.deletePerson(AL);
                    break;
                case "5":
                    menu.sortByName(AL);
                    menu.printPersons(AL);
                    break;
                case "6":
                    menu.sortBySignature(AL);
                    menu.printPersons(AL);
                    break;
                case "7":
                    menu.sortByHeight(AL);
                    menu.printPersons(AL);
                    break;
                case "8":
                    Collections.shuffle(AL);
                    menu.printPersons(AL);
                    break;
                case "9":
                    generalFunctions.saveToFile(AL);
                    continue;
                case "10":
                    AL = generalFunctions.loadFromFile();
                    continue;
                case "11":
                    System.out.println("Exiting program...");
                    System.exit(1);
                    break;
                default:
                    System.out.println("Invalid input, try again!");
                    System.out.println("------------------------");

            }
        }
        generalFunctions.main_menu();
    }
}