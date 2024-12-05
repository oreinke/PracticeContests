import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class e {
    static boolean[][][] dp = new boolean[501][501][2];

    public static void main(String[] args) throws Exception {
        // Initialize dp array
        // dp[B][D][player] = false by default (since default boolean is false)

        // Fill dp table
        for (int B = 1; B <= 500; B++) {
            for (int D = 1; D <= 500; D++) {
                for (int player = 0; player <= 1; player++) {
                    if (player == 0) { // Harry's turn
                        if (D == 1) {
                            dp[B][D][player] = false; // No moves available
                        } else {
                            dp[B][D][player] = false; // Assume losing position
                            // Try all possible horizontal cuts
                            for (int k = 1; k <= D - 1; k++) {
                                int D1 = k;
                                int D2 = D - k;
                                // If any move leads to a losing position for Vicky
                                if (!dp[B][D1][1] || !dp[B][D2][1]) {
                                    dp[B][D][player] = true; // Winning position
                                    break;
                                }
                            }
                        }
                    } else { // Vicky's turn
                        if (B == 1) {
                            dp[B][D][player] = false; // No moves available
                        } else {
                            dp[B][D][player] = false; // Assume losing position
                            // Try all possible vertical cuts
                            for (int k = 1; k <= B - 1; k++) {
                                int B1 = k;
                                int B2 = B - k;
                                // If any move leads to a losing position for Harry
                                if (!dp[B1][D][0] || !dp[B2][D][0]) {
                                    dp[B][D][player] = true; // Winning position
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        for (int t = 0; t < N; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int B = Integer.parseInt(st.nextToken());
            int D = Integer.parseInt(st.nextToken());
            String S = st.nextToken();
            boolean isHarry = S.equals("Harry");
            int player = isHarry ? 0 : 1;

            boolean canWin = dp[B][D][player];

            System.out.println(S + (canWin ? " can win" : " cannot win"));
        }
    }
}
