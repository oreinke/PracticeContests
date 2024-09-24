import java.util.*;

public class prob1
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numLocs = input.nextInt();

        int[] locs = new int[numLocs + 1];

        for (int i = 1; i <= numLocs; i++)
            locs[i] = input.nextInt();
        
        int numTours = input.nextInt();

        for (int i = 0; i < numTours; i++)
        {
            int sum = 0;
            int start = input.nextInt();
            int end = input.nextInt();

            for (int j = start; j <= end; j++)
            {
                sum += locs[j];
            }

            System.out.println(sum);
        }

    }    
}
