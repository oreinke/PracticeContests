import java.util.*;

public class i {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases> 0) {
            int numParts = input.nextInt();
            int[][] parts = new int[numParts][3];

            for (int i = 0; i < numParts; i++) {
                parts[i][0] = input.nextInt();
                parts[i][1] = input.nextInt();
                parts[i][2] = input.nextInt();
            }

            int dp[] = new int[numParts];

            int absMax = 0;
            for (int i = numParts - 1; i > -1; i--) {
                int max = 0;
                for (int j = i + 1; j < numParts; j++) {
                    if ((parts[i][0] >= parts[j][0] && parts[i][1] >= parts[j][1]) || (parts[i][0] >= parts[j][1] && parts[i][1] >= parts[j][0])) {
                        max = Math.max(max, dp[j]);
                    }
                }

                dp[i] += max + parts[i][2];
                absMax = Math.max(absMax, dp[i]);
            }
            System.out.println(absMax);

            numCases--;
        }
    }

}