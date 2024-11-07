import java.util.*;

class f {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int q = input.nextInt();
        int map[] = new int[n];
        for (int i = 1; i <= n; i++) {
            int company = input.nextInt();
            map[i - 1] = company;
        }

        StringBuilder str = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int c = input.nextInt();
            int first = input.nextInt();
            int second = input.nextInt();

            if (c == 1) {
                map[first - 1] = second;
            }
            else {
                str.append(Math.abs(map[first - 1] - map[second - 1])).append("\n");
            }
        }
        System.out.print(str);

    }
}