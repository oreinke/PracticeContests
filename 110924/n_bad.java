import java.util.*;

class n_bad {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int[] nums = new int[n];
        ArrayList<HashSet<Integer>> sets = new ArrayList<>();

        nums[0] = input.nextInt();
        nums[1] = input.nextInt();
        for (int i = 2; i < n; i++) {
            nums[i] = input.nextInt();
            ArrayList<HashSet<Integer>> toAdd = new ArrayList<>();
            for (HashSet<Integer> s : sets) {
                if (triCheck(s, nums[i])) {
                    HashSet<Integer> tempSet = new HashSet<>(s);
                    tempSet.add(nums[i]);
                    toAdd.add(tempSet);
                }
            }

            for (int j = 0; j < i; j++) {
                for (int k = j + 1; k < i; k++) {
                    if (triCheck(nums[j], nums[k], nums[i])) {
                        HashSet<Integer> tempSet = new HashSet<>();
                        tempSet.add(nums[i]);
                        tempSet.add(nums[j]);
                        tempSet.add(nums[k]);
                        toAdd.add(tempSet);
                    }
                }
            }

            for (HashSet<Integer> s : toAdd) {
                sets.add(s);
            }
        }

        System.out.println(sets.size());


    }

    public static boolean triCheck (HashSet<Integer> cur, int offer) {
        for (int s1 : cur) {
            for (int s2 : cur) {
                if (s1 == s2) {
                    continue;
                }
                if (s1 + s2 <= offer) {
                    return false;
                }
                if (s1 + offer <= s2) {
                    return false;
                }
                if (offer + s2 <= s1) {
                    return false;
                }
            }
        }

        return true;
    }

    public static boolean triCheck (int s1, int s2, int offer) {
        if (s1 + s2 <= offer) {
            return false;
        }
        if (s1 + offer <= s2) {
            return false;
        }
        if (offer + s2 <= s1) {
            return false;
        }
        return true;
    }
}