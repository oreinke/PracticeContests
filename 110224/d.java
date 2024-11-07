import java.util.*;

class d {
    static final int[] kMovesX = {-2, -2, -1, 1, -1, 1, 2, 2};
    static final int[] kMovesY = {-1, 1, 2, 2, -2, -2, -1, 1};

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int r = input.nextInt();
        int c = input.nextInt();
        input.nextLine();

        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) {
            String str = input.nextLine();
            for (int j = 0; j < str.length(); j++) {
                grid[i][j] = str.charAt(j);
            }
        }


    }
    public static boolean safe(char[][] grid, int square) {
        int x = square;

        return true;
    }
}