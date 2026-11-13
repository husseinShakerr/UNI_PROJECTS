public class YatzyLoop {
    public static void main(String[] args) {
        int counter = 0;
        Yatzy Y1 = new Yatzy();
        System.out.println("Rolling the dices 10 000 000 times...  ");
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < 10000000; i++){
            Y1.rollDices();
            if(Y1.isYatzy())
                counter++;
        }
        double per = ((double)counter / 10000000)*100;
        long endTime = System.currentTimeMillis();
        System.out.println("Amount of yatzys: " + counter);
        System.out.printf("%.4f%% was yatzy%n", per);
        System.out.println("Time it took: " + (endTime - startTime) + "ms");
    }
}
