import java.util.*;

class m {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int k = input.nextInt();

        int total = 0;
        for (int i = 0; i < k; i++) {
            total += input.nextInt();
        }

        int totalMin = total + (-3 * (n - k));
        int totalMax = total + (3 * (n - k));
        System.out.print(totalMin / (float) n);
        System.out.println(" " + totalMax / (float) n);

    }

}