import java.util.*;


class n {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = input.nextInt();
        }

        Arrays.sort(nums);

        long count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long sum = (long) nums[i] + nums[j];
                long c = 0;
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] < sum) {
                        c++;
                    }
                    else {
                        break;
                    }
                }
                count += (1 << c) - 1;
            }
        }
        System.out.println(count);
    
    }
}