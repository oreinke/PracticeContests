import java.util.*;

public class g {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0) {
            int n = input.nextInt();
            int m = input.nextInt();
            int q = input.nextInt();

            int reel[] = new int[n];
            HashMap<Integer, Integer> values = new HashMap<>();

            for (int i = 0; i < n; i++) {
                reel[i] = input.nextInt() - 1;
                values.put(reel[i], values.getOrDefault(reel[i], 0) + 1);
            }

            int offset = 0;
            while (q > 0) {
                int action = input.nextInt();

                if (1 == action) {
                    int i = input.nextInt() - 1;
                    int x = input.nextInt();

                    if (values.get(reel[i]) == 1) {
                        values.remove(reel[i]);
                    }
                    else {
                        values.put(reel[i], values.get(reel[i]) - 1);
                    }
                    reel[i] = (reel[i] + x) % m;
                    values.put(reel[i], values.getOrDefault(reel[i], 0) + 1);
                }
                else if (2 == action) {
                    int x = input.nextInt();
                    offset = (offset + x) % m;
                }
                else {
                    int a = input.nextInt() - 1;
                    int b = input.nextInt() - 1;
                    int count = 0;

                
                    for (int k : values.keySet()) {
                        int val = (k + offset) % m;
                        if (a <= val && b >= val)
                            count+= values.get(k);
                    }

                    System.out.println(count);
                }

                q--;
            }

            numCases--;
        }
    }

}