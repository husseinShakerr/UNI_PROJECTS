import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

public class Yatzy {
    private int[] dices = new int[5];

    public Yatzy(){
        rollDices();
    }
    public void rollDices(){
        Random rand = new Random();
        for(int i = 0; i < dices.length; i++){
            dices[i] = rand.nextInt(6)+1;
        }
    }
    public void rollDices(boolean d0, boolean d1, boolean d2, boolean d3, boolean d4){
        Random rand = new Random();
        if (d0)
            dices[0] = rand.nextInt(6)+1;
        if(d1)
            dices[1] = rand.nextInt(6)+1;
        if(d2)
            dices[2] = rand.nextInt(6)+1;
        if(d3)
            dices[3] = rand.nextInt(6)+1;
        if (d4)
            dices[4] = rand.nextInt(6)+1;
    }
    public boolean isYatzy(){
        sort();
        for (int i = 0; i < dices.length; i++){
            if (dices[0] != dices[i]) {
                return false;
            }
        }
        //
        return true;
    }
    public void sort(){
        Arrays.sort(dices);
        int left = 0;
        int right = dices.length - 1;
        while (left < right){
            int temp = dices[left];
            dices[left] = dices[right];
            dices[right] = temp;
            left++;
            right--;
        }
    }
    public String toString(){
        return dices[0] + " " + dices[1] + " " + dices[2] + " " + dices[3] + " " + dices[4];
    }
}
