public class Variables {
    public static void main(String[] args) {
        int x, y, z, summa;
        x = 10;
        y = 10;
        z = 5;
        summa = x * y / z;
        System.out.println(summa);
        String mat = "Kebabrulle med vitlöksås";
        double dubbel = 3.704, dubbel1 = 3.99887;
        boolean bool = true;
        char T = 'A';
        while(bool) {
            System.out.println(mat);
            double dubbel2 = dubbel + dubbel1;
            System.out.println(dubbel2);
            System.out.println(T);
            bool = false;
        }

    }
}