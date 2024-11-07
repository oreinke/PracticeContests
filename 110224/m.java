import java.util.*;

class m {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int e = input.nextInt();
        int n = 1;
        for (int i = 0; i < e; i++) {
            n *= 2;
        }
        int[][] grid = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                grid[i][j] = input.nextInt();
                visited[i][j] = false;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         System.out.print(grid[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        HashSet<Integer> used = new HashSet<>();
        
        boolean failed = false;
        for (int i = 0; i < n; i++) {
            if (failed) {
                break;
            }
            for (int j = 0; j < n; j++){
                if (visited[i][j]) {
                    continue;
                }
                if (used.contains(grid[i][j])) {
                    failed = true;
                    break;
                }
                if (grid[i][j] == 0) {
                    used.add(0);
                    visited[i][j] = true;
                    continue;
                }

                // . .
                //   .
                if (i + 1 < n && j + 1 < n && grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i][j + 1]) {
                    used.add(grid[i][j]);
                    visited[i][j] = true;
                    visited[i][j + 1] = true;
                    visited[i + 1][j + 1] = true;
                }
                // . .
                // .
                else if (i + 1 < n && j + 1 < n && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j]) {
                    used.add(grid[i][j]);
                    visited[i][j] = true;
                    visited[i + 1][j] = true;
                    visited[i][j + 1] = true;                    
                }
                // .
                // . .
                else if (i + 1 < n && j + 1 < n && grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 1][j]) {
                    used.add(grid[i][j]);
                    visited[i][j] = true;
                    visited[i + 1][j + 1] = true;
                    visited[i + 1][j] = true;                    
                }
                //   .
                // . .
                else if (j - 1 >= 0 && i + 1 < n && grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 1][j]) {
                    used.add(grid[i][j]);
                    visited[i][j] = true;
                    visited[i + 1][j] = true;
                    visited[i + 1][j - 1] = true;                    
                }
                else {
                    failed = true;
                }
            }
        }
        if (failed || !used.contains(0)) {
            System.out.println(0);
        }
        else {
            System.out.println(1);
        }



    }
}