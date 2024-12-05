import java.util.*;

class p {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        HashMap<Integer, Integer> counts = new HashMap<>();
        int offset = 0;

        for (int i = 1; i <= m; i++) {
            int member = input.nextInt();
            if (counts.containsKey(member)) {
                offset += i - counts.get(member);
            }
            else {
                offset += i;
            }
            counts.put(member, i);
            long num = i * (long) n - offset;
            System.out.println(num); 
        }
    }

}