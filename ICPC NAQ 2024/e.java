import java.util.*;

public class e
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt() * 50;

        int[] tally = new int[51];

        for (int i = 0; i < numCases; i++)
        {
            tally[input.nextInt()]++;
        }

        int threshold = numCases / 25;

        String result = "";
        // System.out.println(threshold);
        for (int i = 1; i < 51; i++)
        {
            // System.out.println(tally[i]);
            if (tally[i] > threshold)
                result += " " + i;
        }
        if (result.equals(""))
        {
            result = "-1";
        }
        System.out.println(result.trim());

    }
}