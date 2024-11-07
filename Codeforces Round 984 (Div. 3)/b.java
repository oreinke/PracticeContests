import java.util.*;

public class b {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t > 0) {
            int s = input.nextInt();
            int b = input.nextInt();

            HashMap<Integer, Integer> bottles = new HashMap<Integer, Integer>();

            int newB;
            int c;
            while (b > 0) {
                newB = input.nextInt();
                c = input.nextInt();
                bottles.put(newB, bottles.getOrDefault(newB, 0) + c);
                
                b--;
            }
            ArrayList<Integer> vals = new ArrayList<>(bottles.values());
            Collections.sort(vals, Collections.reverseOrder());

            long max = 0;
            int i = 0;
            while (s > 0 && i < vals.size()) {
                max += vals.get(i);
                i++;
                s--;
            }

            System.out.println(max);
            t--;
        }
    }
}
