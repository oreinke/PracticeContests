import java.util.*;

public class k {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0) {
            int numRegions = input.nextInt();
            int turts[] = new int[numRegions];
            for (int i = 0; i < numRegions; i++) {
                turts[i] = input.nextInt();
            }

            long min = Long.MAX_VALUE;

            for (int i = 0; i < numRegions; i++) {
                long speed = input.nextLong();
                min = Math.min(min, turts[i] * speed);
            }
            System.out.println(min);


            numCases--;
        }
    }

}