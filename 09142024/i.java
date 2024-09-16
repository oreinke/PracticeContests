import java.util.*;

public class i
{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numTerritories = input.nextInt();
            int numToSelect = input.nextInt();
            int[] sizes = new int[numTerritories];

            for (int i = 0; i < numTerritories; i++)
            {
                sizes[i] = input.nextInt();
            }

            long result = Long.MIN_VALUE;
            for (int i = 0; i < sizes.length; i++)
            {
                long attempt = recursion(i, numToSelect - 1, sizes);
                if (attempt > result)
                    result = attempt;
            }

            System.out.println(result);

            numCases--;
        }
    }

    public static long recursion(int curIndex, int numLeft, int[] sizes)
    {
        if (numLeft != 0 && curIndex > sizes.length - 3)
        {
            return Long.MIN_VALUE;
        }

        if (numLeft == 0 || curIndex > sizes.length - 3)
        {
            return sizes[curIndex];
        }

        long max = Long.MIN_VALUE;

        for (int i = curIndex + 2; i < sizes.length; i++)
        {
            long attempt = recursion(i, numLeft - 1, sizes);
            if (attempt >  max)
                max = attempt;
        }
        
        return sizes[curIndex] + max;
    }
}
