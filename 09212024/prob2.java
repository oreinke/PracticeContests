import java.util.*;

public class prob2
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        for (int i = 0; i < numCases; i++)
        {
            int num = input.nextInt();
            System.out.println(num / 12 + " feet, " + num % 12 + " inches of snow is the equivalent of " + num / 10 + " inches of rain");
        }
    }
}