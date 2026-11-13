import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;

public class menu {
    public static void addPerson(ArrayList<Person> AL) {
        String fName, sName, signature, streetAdress, psCode, city, entered_height, choice;
        int height;
        String empty_field = "This field can not be empty!";
        boolean addingCon = true;
        boolean entered_field;
        Scanner userInput = new Scanner(System.in);

        while (addingCon) {
            entered_field = false;
            do {
                if (entered_field)
                    System.out.println(empty_field);
                System.out.println("Enter firstname: ");
                fName = userInput.nextLine().toLowerCase();
                entered_field = true;
            } while (fName.isEmpty());

            entered_field = false;
            do {
                if (entered_field)
                    System.out.println(empty_field);
                System.out.println("Enter surname: ");
                sName = userInput.nextLine().toLowerCase();
                entered_field = true;
            } while (sName.isEmpty());

            while (true){
                System.out.println("Enter height (cm): ");
                entered_height = userInput.nextLine();
                if(entered_height.isEmpty()){
                    System.out.println(empty_field);
                    continue;
                }
                if(!generalFunctions.height_check(entered_height)){
                    continue;
                }
                height = Integer.parseInt(entered_height);
                break;
            }

            entered_field = false;
            do {
                if (entered_field)
                    System.out.println(empty_field);
                System.out.println("Enter street adress: ");
                streetAdress = userInput.nextLine();
                entered_field = true;
            } while (streetAdress.isEmpty());

            entered_field = false;
            do {
                if (entered_field)
                    System.out.println(empty_field);
                System.out.println("Enter postal code: ");
                psCode = userInput.nextLine();
                entered_field = true;
            } while (psCode.isEmpty());

            entered_field = false;
            do {
                if (entered_field)
                    System.out.println(empty_field);
                System.out.println("Enter city: ");
                city = userInput.nextLine();
                entered_field = true;
            } while (city.isEmpty());
            signature = generalFunctions.generateUserNames(fName, sName, AL);
            Adress Adress1 = new Adress(streetAdress, psCode, city);
            Person person = new Person(fName, sName, signature, height, Adress1);
            AL.add(person);
            entered_field = false;
            do {
                System.out.println(STR."""
                        Enter 'y' if you want to add another person to the list. \n
                        Enter 'q' to quit.
                        """);
                choice = userInput.nextLine().toLowerCase();
                if (choice.equals("y"))
                    addingCon = true;
                else if (choice.equals("q"))
                    addingCon = false;
                else {
                    System.out.println("Invalid input, enter 'y' or 'q'.");
                    entered_field = true;
                }
            }while (entered_field);
        }
    }
    public static void printPersons(ArrayList<Person> AL){
        int num = 0;
        Scanner userInp = new Scanner(System.in);
        if(generalFunctions.ifArrIsEmpty(AL)){
            generalFunctions.main_menu();
        }
        int nr = 1;
        do {
            System.out.printf("%-4s%-12s%-30s%-4s%n", "Nr" ,"Signature", "Name", "Height[m]");

            for (int i = num; i < AL.size() && i < (num + 20); i++) {
                System.out.println((i + 1)+ "\t" + AL.get(i).personInfo());
                nr++;
            }
            num += 20;
            System.out.println("Press 'enter' to show 20 more persons.");
            System.out.println("Press 'q' to quit.");

        }while (userInp.nextLine().equals(""));
    }
    public static void searchPerson(ArrayList<Person> AL){
        if(generalFunctions.ifArrIsEmpty(AL)) {
            return;
        }
        Scanner userInp = new Scanner(System.in);
        System.out.println("Enter person signature: ");
        String search_string = userInp.nextLine();
        ArrayList<Person> found_persons = new ArrayList<>();
        for (Person person : AL){
            if (person.getSignature().toLowerCase().contains(search_string)){
                found_persons.add(person);
            }
        }
        if(found_persons.isEmpty()){
            System.out.println("Could not find [" + search_string + "] in the list.");
        }
        int nr = 1;
        for (Person p : found_persons){
            System.out.println(nr + "\t" + p.personInfo());
            nr++;
        }
    }
    public static ArrayList<Person> deletePerson(ArrayList<Person> AL) {
        boolean found = false;
        boolean startSearch = true;
        Scanner userInp = new Scanner(System.in);
        if (generalFunctions.ifArrIsEmpty(AL)){
            return AL;
        }
        do {
            System.out.println("Enter person signature: ");
            System.out.println("Enter 'q' to exit to main menu.");
            String search_string = userInp.nextLine().toLowerCase();
            if (search_string.equals("q")) {
                startSearch = false;
                found = true;
            }
            else{
                Iterator<Person> it = AL.iterator();
                while (it.hasNext()) {
                    Person person = it.next();
                    if (person.getSignature().equals(search_string)) {
                        it.remove();
                        found = true;
                        System.out.println("Deleted [" + person + "] from the list.");
                        break;
                    }
                }
            }
            if(!found){
                System.out.println("Could not find [" + search_string + "] ");
                System.out.println("--------------------------");
            }
        } while (startSearch);
        return AL;
    }
    public static ArrayList<Person> sortByName(ArrayList<Person> AL){
        AL.sort(new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                if (o1.getSurname().compareTo(o2.getSurname()) == 0)
                    return o1.getFirstName().compareTo(o2.getFirstName());
                return o1.getSurname().compareTo(o2.getSurname());
            }
        });
        return AL;
    }
    public static ArrayList<Person> sortBySignature(ArrayList<Person> AL){
        AL.sort(new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                return o1.getSignature().compareTo(o2.getSignature());
            }
        });
        return AL;
    }
    public static ArrayList<Person> sortByHeight(ArrayList<Person> AL){
        AL.sort(new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                if (o1.getHeight() < o2.getHeight())
                    return 1;
                if (o1.getHeight() == o2.getHeight())
                    return 0;
                return -1;
            }
        });

        return AL;
    }
}
