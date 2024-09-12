import java.util.*;
public class swan
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        
        while (numCases > 0)
        {
            int numLocs = input.nextInt();
            int newDegree = input.nextInt();
            int speed = input.nextInt();
            int newDistance = 1000;
            double[][] positions = new double[numLocs][2];
            double[] startPosition = new double[2];

            if (newDegree <= 90)
                {
                    startPosition[0] = Math.cos(Math.toRadians(newDegree)) * newDistance;
                    startPosition[1] = Math.sin(Math.toRadians(newDegree)) * newDistance;
                }
                else if (newDegree <= 180)
                {
                    newDegree = 180 - newDegree;

                    startPosition[0] = Math.cos(Math.toRadians(newDegree)) * newDistance * -1;
                    startPosition[1] = Math.sin(Math.toRadians(newDegree)) * newDistance;
                }
                else if (newDegree <= 270)
                {
                    newDegree = newDegree - 180;

                    startPosition[0] = Math.cos(Math.toRadians(newDegree)) * newDistance * -1;
                    startPosition[1] = Math.sin(Math.toRadians(newDegree)) * newDistance * -1;
                }
                else
                {
                    newDegree = 360 - newDegree;

                    startPosition[0] = Math.cos(Math.toRadians(newDegree)) * newDistance;
                    startPosition[1] = Math.sin(Math.toRadians(newDegree)) * newDistance * -1;
                }

            for (int i = 0; i < numLocs; i++)
            {
                newDistance = input.nextInt();
                newDegree = input.nextInt();
                
                if (newDegree <= 90)
                {
                    positions[i][0] = Math.cos(Math.toRadians(newDegree)) * newDistance;
                    positions[i][1] = Math.sin(Math.toRadians(newDegree)) * newDistance;
                }
                else if (newDegree <= 180)
                {
                    newDegree = 180 - newDegree;

                    positions[i][0] = Math.cos(Math.toRadians(newDegree)) * newDistance * -1;
                    positions[i][1] = Math.sin(Math.toRadians(newDegree)) * newDistance;
                }
                else if (newDegree <= 270)
                {
                    newDegree = newDegree - 180;

                    positions[i][0] = Math.cos(Math.toRadians(newDegree)) * newDistance * -1;
                    positions[i][1] = Math.sin(Math.toRadians(newDegree)) * newDistance * -1;
                }
                else
                {
                    newDegree = 360 - newDegree;

                    positions[i][0] = Math.cos(Math.toRadians(newDegree)) * newDistance;
                    positions[i][1] = Math.sin(Math.toRadians(newDegree)) * newDistance * -1;
                }
            }
            boolean[] used = new boolean[numLocs];

            double distance = recursion(0, startPosition, startPosition, positions, numLocs, used);
            System.out.printf("%.2f\n", distance / speed);

            numCases--;
        }

    }

    public static double recursion(int numAssigned, double[] lastPosition, double[] startPosition, double[][] positions, int numLocs, boolean[] used)
    {
        if ( numAssigned == numLocs)
        {
            return findDistance(lastPosition, startPosition);
        }

        double curDistance = Double.MAX_VALUE;
        for (int i = 0; i < numLocs; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                curDistance = Math.min(recursion(numAssigned + 1, positions[i], startPosition, positions, numLocs, used) + findDistance(lastPosition, positions[i]), curDistance);
                used[i] = false;
            }
        }

        return curDistance;
    }

    public static double findDistance (double[] p1, double[] p2)
    {
        double x = p1[0] - p2[0];
        double y = p1[1] - p2[1];

        return Math.sqrt((x * x) + (y * y));
    }


}
