import java.util.*;

public class l {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0) {
            int count = 0;
            int n = input.nextInt();
            input.nextLine();
            int grid[][] = new int[n][n];

            for (int i = 0; i < n; i++) {
                String str = input.nextLine();
                for (int j = 0; j < n; j++) {
                    grid[i][j] = (str.charAt(j) == 'B') ? 0 : 1;
                }
            }


            input.nextLine();
            for (int i = 0; i < n; i++) {
                String str = input.nextLine();
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] != ((str.charAt(j) == 'B') ? 0 : 1))
                        count++;
                }
            }
            System.out.print("grid problems ");
            if (count % 2 == 0) {
                System.out.println("<3");
            }
            else {
                System.out.println(":(");
            }

            numCases--;
        }
    }

}