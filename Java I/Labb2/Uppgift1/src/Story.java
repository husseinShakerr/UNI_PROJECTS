import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Story {
    public static void main(String[] args) {
        Scanner indata = new Scanner(System.in);
        System.out.println("Vad heter myran?");
        String namn = indata.nextLine();
        System.out.println("Vem bor myran med?");
        String boende_med = indata.nextLine();
        System.out.println("Hur många syskon har myran?");
        String syskon = indata.nextLine();
        System.out.println("Vid vad finns myrstacken i skogen?");
        String myrstack = indata.nextLine();
        System.out.println("Vad bär myran in till myrstacken?");
        String vad0 = indata.nextLine();
        System.out.println("Vad mer bär myran in till myrstacken?");
        String vad1 = indata.nextLine();
        System.out.println("Vad är det för speciell dag som gör att myran är ledig?");
        String ledig_dag = indata.nextLine();
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.print("Den lilla myran " + namn + ".\n\n");
        System.out.print("Det var en gång en liten, liten myra som bodde med " +boende_med+
        " och sina " +syskon+ " syskon i en myrstack, vid en stor " +myrstack+ " i skogen." +
        " Den lilla \nmyran hette " +namn+ ". För det mesta brukade " +namn+
        " och hans syskon bära in " +vad0+ " och " +vad1+ " \ntill stacken, men idag var det "
        +ledig_dag+ ", så därför är de ledig. ");
    }
}