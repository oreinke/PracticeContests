import java.util.*;

public class i
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int dimensions = input.nextInt();
        input.nextLine();

        int[][] grid = new int[dimensions][dimensions];

        for (int i =0; i < dimensions; i++)
        {
            String row = input.nextLine();
            for (int j = 0; j < dimensions; j++)
            {
                grid[i][j] = row.charAt(j);
            }
        }

        boolean valid = true;
        for (int i = 0; i < dimensions; i++)
        {
            if (!valid)
            {
                break;
            }
            for (int j = 0; j < dimensions; j++)
            {
                if (!valid)
                {
                    break;
                }
                if (grid[i][j] == '.')
                {

                    int x = i;
                    int y = j;
                    int countTotal = 0;
                    int count = 0;
                    while (x > -1 && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            count++;
                            countTotal++;
                        }
                        x--;
                    }
                    x = i;
                    while (x < dimensions && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        // System.out.println(x);
                        if (grid[x][y] == '?')
                        {
                            count++;
                            countTotal++;
                        }
                        x++;
                    }
                    if (count > 1)
                    {
                        // System.out.println("Broke on check for i: " + i + ", j: " + j);
                        valid = false;
                        break;
                    }

                    x = i;
                    y = j;
                    count = 0;
                    while (y > -1 && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            count++;
                            countTotal++;
                        }
                        y--;
                    }
                    y = j;
                    while ( y < dimensions && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            count++;
                            countTotal++;
                        }
                        y++;
                    }
                    if (count > 1)
                    {
                        // System.out.println("Broke on check for i: " + i + ", j: " + j);
                        valid = false;
                        break;
                    }

                    if (countTotal == 0)
                    {
                        // System.out.println("HERE!");
                        // System.out.println("Broke on check for i: " + i + ", j: " + j);
                        valid = false;
                        break;
                    }
                }
                else if (grid[i][j] == '?')
                {
                    int x = i;
                    int y = j;
                    int countTotal = 0;
                    while (x > -1 && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            countTotal++;
                        }
                        x--;
                    }
                    x = i;
                    while (x < dimensions && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            countTotal++;
                        }
                        x++;
                    }

                    x = i;
                    y = j;
                    while (y > -1 && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            countTotal++;
                        }
                        y--;
                    }
                    y = j;
                    while ( y < dimensions && (grid[x][y] == '.' || grid[x][y] == '?'))
                    {
                        if (grid[x][y] == '?')
                        {
                            countTotal++;
                        }
                        y++;
                    }
                    if (countTotal > 4)
                    {
                        //System.out.println("Broke on check for i: " + i + ", j: " + j);
                        valid = false;
                        break;
                    }
                }
                else if (grid[i][j] - '0' > -1 && grid[i][j] - '0' < 5)
                {
                    int count = grid[i][j] - '0';
                    // System.out.println(grid[i][j] + ", " + count);
                    if (i - 1 > -1 && grid[i - 1][j] == '?')
                    {
                        count--;
                    }
                    if (i + 1 < dimensions && grid[i + 1][j] == '?')
                    {
                        count--;
                    }
                    if (j - 1 > -1 && grid[i][j - 1] == '?')
                    {
                        count--;
                    }
                    if (j + 1 < dimensions && grid[i][j + 1] == '?')
                    {
                        count--;
                    }

                    if (count != 0)
                    {
                        // System.out.println("Broke on check for i: " + i + ", j: " + j);
                        valid = false;
                    }
                }
            }
            
        }

        if (valid)
        {
            System.out.println(1);
        }
        else
        {
            System.out.println(0);
        }
    }
}