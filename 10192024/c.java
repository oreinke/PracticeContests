import java.util.*;

class c {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int diff = input.nextInt();

        HashSet<Integer> pitches = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int num = input.nextInt();
            pitches.add(num);
        }

        int[] nums = new int[pitches.size()];
        int index = 0;
        for (int pitch : pitches) {
            nums[index] = pitch;
            index++;
        }
        Arrays.sort(nums);

        int runningDiff = 0;
        int numSets = 1;
        for (int i = 1; i < nums.length; i++) {
            if (runningDiff + (nums[i] - nums[i - 1]) > diff) {
                runningDiff = 0;
                numSets++;
            }
            else {
                runningDiff += nums[i] - nums[i - 1];
            }
        }

        System.out.println(numSets);           
    }
}