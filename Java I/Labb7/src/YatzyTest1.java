public class YatzyTest1 {
    public static void main(String[]args){
        Yatzy y1 = new Yatzy();
        y1.rollDices();
        System.out.println("Rolling all the dices...");
        System.out.println(y1.toString());
        System.out.println("Rolling dices 4 and 5...");
        y1.rollDices(false, false, false, true, true);
        System.out.println(y1.toString());
        System.out.println("Sorting the dices...");
        y1.sort();
        System.out.println(y1.toString());
        System.out.println("Checking for yatzy...");
        if(y1.isYatzy())
            System.out.println("Congrats! Yatzy!!!");
        else
            System.out.println("Xx--Not yatzy--xX");
        System.out.println(y1.toString());

    }
}
