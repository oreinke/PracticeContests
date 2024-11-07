import java.util.*;

class  l {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
       
        int n = input.nextInt();
        int s = input.nextInt();

        for (int i = 0; i < n; i++) {
            int lower = input.nextInt();
            int higher = input.nextInt();

            if (s >= lower && s <= higher) {
                s++;
            }
        }
        System.out.println(s);
    }
}