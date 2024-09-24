import java.util.*;

public class prob7
{
    final static int[] dX = new int[]{1, 0, 0, -1};
    final static int[] dY = new int[]{0, 1, -1, 0};
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0)
        {
            int numRows = input.nextInt();
            int numCols = input.nextInt();

            int[][] graph = new int[numRows][numCols];
            int[][] counts = new int[numRows][numCols];

            counts[counts.length - 1][counts[0].length - 1] = 1;

            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j < numCols; j++)
                {
                    graph[i][j] = input.nextInt();
                    counts[i][j] = -1;
                }
            }

            counts[counts.length - 1][counts[0].length - 1] = 1;

            System.out.println(dfs(0, 0, graph, counts));
            

            numCases--;
        }
    }

    public static int dfs (int row, int col, int[][] graph, int[][] counts)
    {
        if (counts[row][col] != -1)
        {
            return counts[row][col];
        }
        
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            if (!(row + dX[i] < 0 || row + dX[i] >= graph.length || col + dY[i] < 0 || col + dY[i] >= graph[0].length))
            {
                if (graph[row][col] > graph[row + dX[i]][col + dY[i]])
                {
                    sum += dfs(row + dX[i], col + dY[i], graph, counts);
                }
            }
        }
        counts[row][col] = sum % 1000;

        

        return sum % 1000;
    }
}
