import java.util.*;

class k {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int d = input.nextInt();
        int min = input.nextInt();
        int max = input.nextInt();
        boolean minB = false; 
        boolean maxB = false;
        if (max == min) {
            System.out.println(min);
        }
        else {
            for (int i = 0; i < d - 1; i++) {
                int num = input.nextInt();
                if (num == min) {
                    minB = true;
                }
                else if (num == max) {
                    maxB = true;
                }
            }

            if (minB && maxB) {
                for (int i = min; i <= max; i++) {
                    System.out.println(i);
                }
            }
            else if (!minB && !maxB) {
                System.out.println(-1);
            }
            else if (!minB) {
                System.out.println(min);
            }
            else {
                System.out.println(max);
            }
        }
    }
}