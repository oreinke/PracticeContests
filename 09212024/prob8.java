import java.util.*;

public class prob8 {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        for (int i = 1; i <= numCases; i++)
        {
            int numRows = input.nextInt();
            int numCols = input.nextInt();
            int length = input.nextInt();
            input.nextLine();

            int[][] grid = new int[numRows][numCols];
            int[] startSnake = new int[length];

            for (int j = 0; j < numRows; j++)
            {

                String row = input.nextLine();
                
                for (int k = 0; k < numCols; k++)
                {
                    char cell = row.charAt(k);
                    if (cell == '#')
                    {
                        grid[j][k] = -1;
                    }
                    else if (cell == 'x')
                    {
                        grid[j][k] = 1;
                    }

                    for (int l = 0; l < length; l++)
                    {
                        if (cell == '0' + l)
                        {
                            startSnake[l] = j * numCols + k;
                            break;
                        }
                    }
                }
            }

            ArrayDeque<Integer> snake = new ArrayDeque<>();

            for (int j = length - 1; j >= 0; j--)
            {
                snake.add(startSnake[j]);
            }

            int[] dX = new int[]{-1, 0, 0, 1};
            int[] dY = new int[]{0, -1, 1, 0};
            ArrayDeque<ArrayDeque<Integer>> frontier = new ArrayDeque<>();
            frontier.add(snake);
            int step = -1;
            int count = 0;

            if (length > 3)
            {
                while (!frontier.isEmpty())
                {
                    if (step != -1)
                    {
                        break;
                    }
                    count++;
                    ArrayDeque<ArrayDeque<Integer>> next = new ArrayDeque<>();
                    HashSet<Integer> visited = new HashSet<Integer>();

                    while (!frontier.isEmpty())
                    {
                        ArrayDeque<Integer> curSnake = frontier.poll();

                        curSnake.poll();
                        int head = curSnake.getLast();

                        for (int j = 0; j < 4; j++)
                        {
                            if (!(visited.contains(head + dX[j] + (dY[j] * numCols)) || head % numCols + dX[j] < 0 || head % numCols + dX[j] >= numCols || head / numCols + dY[j] < 0 || head / numCols + dY[j] >= numRows))
                            {
                                if (!curSnake.contains(head + dX[j] + (dY[j] * numCols)) && grid[head / numCols + dY[j]][head % numCols + dX[j]] != -1)
                                {
                                    if (grid[head / numCols + dY[j]][head % numCols + dX[j]] == 1)
                                    {
                                        step = count;
                                        break;
                                    }
                                    else
                                    {
                                        ArrayDeque<Integer> newSnake = new ArrayDeque<>(curSnake);
                                        newSnake.add(head + dX[j] + (dY[j] * numCols));
                                        next.add(newSnake);
                                        visited.add(head + dX[j] + (dY[j] * numCols));
                                    }
                                }
                            }
                        }
                        
                    }
                    frontier = next;
                }
                System.out.println("Game #" + i + ": " + step);
            }
            else
            {
                while (!frontier.isEmpty())
                {
                    if (step != -1)
                    {
                        break;
                    }
                    count++;
                    ArrayDeque<ArrayDeque<Integer>> next = new ArrayDeque<>();
                    HashSet<Integer> visited = new HashSet<Integer>();

                    while (!frontier.isEmpty())
                    {
                        ArrayDeque<Integer> curSnake = frontier.poll();

                        int head = curSnake.getLast();

                        for (int j = 0; j < 4; j++)
                        {
                            if (!(visited.contains(head + dX[j] + (dY[j] * numCols)) || head % numCols + dX[j] < 0 || head % numCols + dX[j] >= numCols || head / numCols + dY[j] < 0 || head / numCols + dY[j] >= numRows))
                            {
                                if (!curSnake.contains(head + dX[j] + (dY[j] * numCols)) && grid[head / numCols + dY[j]][head % numCols + dX[j]] != -1)
                                {
                                    if (grid[head / numCols + dY[j]][head % numCols + dX[j]] == 1)
                                    {
                                        step = count;
                                        break;
                                    }
                                    else
                                    {
                                        ArrayDeque<Integer> newSnake = new ArrayDeque<>(curSnake);
                                        newSnake.add(head + dX[j] + (dY[j] * numCols));
                                        newSnake.poll();
                                        next.add(newSnake);
                                        visited.add(head + dX[j] + (dY[j] * numCols));
                                    }
                                }
                            }
                        }
                        
                    }
                    frontier = next;
                }
                System.out.println("Game #" + i + ": " + step);
            }
        }
    }
}
