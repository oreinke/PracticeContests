import java.util.*;

class i {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int x = input.nextInt();
        int y = input.nextInt();

        for (int i = 0; i < n; i++) {
            long num = input.nextLong();
            num *= y;
            num /= x;
            System.out.println(num);
        }

    }
}