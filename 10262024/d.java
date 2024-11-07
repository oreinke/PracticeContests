import java.util.*;

public class d {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        
        while (numCases > 0) {
            int n = input.nextInt();
            int m = input.nextInt();

            HashSet<Long> rules = new HashSet<>();

            while (m > 0) {
                int a = input.nextInt() - 1;
                int b = input.nextInt() - 1;
                int c = input.nextInt() - 1;

                long val = (1 << a | 1 << b | 1 << c);
                rules.add(val);
                m--;
            }
        
            ArrayList<HashSet<Integer>> memberShip = new ArrayList<>();
            ArrayList<Integer> count = new ArrayList<>();
            TreeMap<Integer, Integer> counts = new TreeMap<>(Collections.reverseOrder());
            memberShip.add(new HashSet<>());
            count.add(0);
            counts.put(0, 1);

            int max = 0;
            int combos = 0;
            for (long i = 0; i < 1 << n; i++) {
                boolean error = false;
                for (long rule : rules) {
                    if ((i & rule) == rule) { // restricted comination found
                        error = true;
                        break;
                    }
                }

                if (!error) {
                    if (Long.bitCount(i) == max) {
                        combos++;
                    }
                    else if (Long.bitCount(i) > max) {
                        max = Long.bitCount(i);
                        combos = 1;
                    }
                }
            }  
        System.out.println(max + " " + combos);
        numCases--;
        }
    }

}