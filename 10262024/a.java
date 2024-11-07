import java.util.*;

public class a {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0) {
            int numRanges = input.nextInt();
            TreeMap<Integer, Integer> ranges = new TreeMap<>();

            while (numRanges > 0) {
                int s = input.nextInt();
                int e = input.nextInt();
                ranges.put(s, e);
                numRanges--;
            }

            int numDays = input.nextInt();
            while (numDays > 0) {
                int day = input.nextInt();
                if (ranges.floorKey(day) == null) {
                    System.out.println("yes");
                }
                else {
                       if (ranges.floorKey(day) == day || day <= ranges.get(ranges.floorKey(day) )) {
                        System.out.println("no");
                    }
                    else {
                        System.out.println("yes");
                    }
                }

                numDays--;
            }

            numCases--;
        }
    }
    
}