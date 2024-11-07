import java.util.*;

class d {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        
        int numProbs = input.nextInt();

        int[] probs = new int[numProbs];

        int count = 0;
        
        for (int i = 0; i < numProbs; i++) {
            probs[i] = input.nextInt();
        }

        for (int k = 2; k <= numProbs; k++) {
            if (0 != numProbs % k) {
                continue;
            }

            boolean flag = true;
            for (int i = 1; i < k; i++) {
                if (max(probs, (i - 1) * (numProbs / k), (i) * (numProbs / k) - 1 ) >= min(probs, (i) * (numProbs / k), (i + 1) * (numProbs / k) - 1 )) {
                    flag = false;
                    break;
                }
            }    
            
            if (flag) {
                count++;
                System.out.println(k);
            }
        }

        if (count == 0) {
            System.out.println("-1");
        }
        
    }

    public static int min (int[] probs, int start, int end) {
        int min = Integer.MAX_VALUE;

        for (int i = start; i <= end; i++) {
            if (probs[i] < min) {
                min = probs[i];
            }
        }

        return min;
    }

    public static int max (int[] probs, int start, int end) {
        int max = -1;

        for (int i = start; i <= end; i++) {
            if (probs[i] > max) {
                max = probs[i];
            }
        }

        return max;
    }
}