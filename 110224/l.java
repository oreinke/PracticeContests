import java.util.*;

class l {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int cap = input.nextInt();
        int col = input.nextInt();
        int[] colMax = new int[col];
        int[] colCur = new int[col];

        for (int i = 0; i < col; i++) {
            colMax[i] = input.nextInt();
            colCur[i] = 0;
        }

        boolean assigned = true;
        while (cap > 0 && assigned) {
            assigned = false;
            for (int i = 0; i < col && cap > 0; i++) {
                if (colCur[i] < colMax[i]) {
                    assigned = true;
                    colCur[i]++;
                    cap--;
                }
            }
        }

        for (int i = 0; i < col; i++) {
            System.out.println(colCur[i]);
        }
    }
}