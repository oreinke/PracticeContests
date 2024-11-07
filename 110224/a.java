import java.util.*;

class a {
    public static void main(String args[]) {
        
    
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int c = input.nextInt();
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        HashMap<Integer, Integer> leftMap = new HashMap<>();
        HashMap<Integer, Integer> rightMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int distance = input.nextInt();
            int num = input.nextInt();

            if (distance < 0) {
                if (!leftMap.containsKey(distance))
                {
                    left.add(distance * -1);
                    leftMap.put(distance * -1, 0);
                }
                leftMap.put(distance * -1, leftMap.get(distance * -1) + num);
            }
            else {
                if (!rightMap.containsKey(distance))
                {
                    right.add(distance);
                    rightMap.put(distance, 0);
                }
                rightMap.put(distance, rightMap.get(distance) + num);
            }
        }
        left.sort(Collections.reverseOrder());
        long distance = 0;
        while (!left.isEmpty()) {
            if (leftMap.get(left.get(0)) >= c) {
                distance += left.get(0) * 2 * (leftMap.get(left.get(0)) / c);
                if (leftMap.get(left.get(0)) % c != 0) {
                    leftMap.put(left.get(0), leftMap.get(left.get(0)) % c) ;
                }
                else {
                    leftMap.remove(left.get(0));
                    left.remove(0);
                }
            }
            else {
                distance += left.get(0) * 2;
                int carry = c - leftMap.get(left.get(0));
                leftMap.remove(left.get(0));
                left.remove(0);
                while (carry > 0 && !left.isEmpty()) {
                    if (leftMap.get(left.get(0)) > carry) {
                        leftMap.put(left.get(0), leftMap.get(left.get(0) ) - carry);
                        carry = 0;
                    }
                    else {
                        carry -= leftMap.get(left.get(0));
                        leftMap.remove(left.get(0));
                        left.remove(0);
                    }
                }
            }
        }


        right.sort(Collections.reverseOrder());
        while (!right.isEmpty()) {
            if (rightMap.get(right.get(0)) >= c) {
                distance += right.get(0) * 2 * (rightMap.get(right.get(0)) / c);
                if (rightMap.get(right.get(0)) % c != 0) {
                    rightMap.put(right.get(0), rightMap.get(right.get(0)) % c) ;
                }
                else {
                    rightMap.remove(right.get(0));
                    right.remove(0);
                }
            }
            else {
                distance += right.get(0) * 2;
                int carry = c - rightMap.get(right.get(0));
                rightMap.remove(right.get(0));
                right.remove(0);
                while (carry > 0 && !right.isEmpty()) {
                    if (rightMap.get(right.get(0)) > carry) {
                        rightMap.put(right.get(0), rightMap.get(right.get(0) ) - carry);
                        carry = 0;
                    }
                    else {
                        carry -= rightMap.get(right.get(0));
                        rightMap.remove(right.get(0));
                        right.remove(0);
                    }
                }
            }
        }
        System.out.println(distance);
    }

}