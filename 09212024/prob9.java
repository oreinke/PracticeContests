import java.util.*;
import javax.swing.text.TabableView;

public class prob9 
{
    public static void main(String args[]) 
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numRows = input.nextInt();
            int numTrees = input.nextInt();

            double[] rows = new double[numRows];

            double max = -1.0;            

            for (int i = 0; i < numRows; i++)
            {
                rows[i] = input.nextDouble();
                if (rows[i] > max)
                {
                    max = rows[i];
                }
            }
                
            double low = 0.0;
            double high = max;

            while (Math.abs(high - low) > .0001)
            {
                double midPoint = (high + low) / 2;
                boolean valid = isSpacingValid(numTrees, 0, midPoint, rows);

                if (valid)
                {
                    low = midPoint;
                }
                else
                {
                    high = midPoint;
                }
            }

            System.out.printf("%.3f\n", high);
            numCases--;
        }
    }

    public static boolean isSpacingValid(int numTrees, int step, double spacing, double[] rows)
    {
        if (numTrees <= 0)
        {
            // System.out.printf("Spacing %f deemed valid on step %d", spacing, step - 1);
            return true;
        }
        
        if (step >= rows.length)
        {
            // System.out.printf("Spacing %f deemed invalid on step %d", spacing, step - 1);
            return false;
        }

        int numTreesConsumed = (int) ((rows[step] - spacing) / spacing);
        // System.out.printf("%d trees can be planted in row %d of size %f with spacing %f\n", numTreesConsumed, step, rows[step], spacing);

        return isSpacingValid(numTrees - numTreesConsumed, step + 1, spacing, rows);
    }
}
