import java.util.*;

public class prob9 
{
    public static void main(String args[]) 
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numRows = input.nextInt();
            int numTrees = input.nextInt() + 1;
            double max = -1.0;

            for (int i = 0; i < numRows; i++)
            {
                double width = input.nextDouble();
                if (width > max)
                {
                    max = width;
                }
            }

            System.out.println("max : " + max + ", numT: " + numTrees);
            double spacing = max / numTrees;
            System.out.printf("%.3f\n", spacing);
            numCases--;
        }
    }
}
