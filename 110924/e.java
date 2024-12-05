import java.util.*;

class e {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayDeque<Integer> heights = new ArrayDeque<>();

        long count = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            int num = input.nextInt();
            while (!heights.isEmpty() && heights.peekFirst() < num) {
                heights.removeFirst();
                c++;
            }
            if (heights.isEmpty()) {
                c--;
            }
            heights.addFirst(num);
            count += c + 1;
            
        }

        System.out.println(count);
    }
}