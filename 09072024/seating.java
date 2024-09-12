import java.util.*;

class seating
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();

        for (int i = 0; i < numCases; i++)
        {
            int c = input.nextInt();
            if (c == 1)
            {
                System.out.println("0");
            }
            else
            {
                boolean[] used = new boolean[c * 2];
                used[0] = true;
              System.out.println(recursion(0, -1, 2, c, used));
            }
        }
    }

    public static int recursion(int previousNum, int previousStart, int step, int c, boolean[] used)
    {
        int sum = 0;
        if (step == c * 2 + 1)
        {
            // System.out.println("Last num: " + previousNum);
            return 1;
        }
        
        if (step % 2 == 0)
        {
            for (int i = previousNum + 2; i < c * 2; i++)
            {
                if (!(used[i]))
                {
                    used[i] = true;
                    sum += recursion(i, previousStart, step + 1, c, used);
                    used[i] = false;
                }
            }
        }
        else
        {
            for (int i = previousStart + 1; i < c * 2; i++)
            {
                if (!used[i])
                {
                    used[i] = true;
                    sum += recursion(i, i, step + 1, c, used);
                    used[i] = false;
                }
            }
        }
        

        return sum;
    }
}
