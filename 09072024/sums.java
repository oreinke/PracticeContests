import java.util.*;

class sums
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        int[] numPoints = new int[301];
        int[] weightedSum = new int[300];

        numPoints[0] = 1;
        for (int i = 1; i < 301; i++)
        {
            numPoints[i] = numPoints[i - 1] + (i + 1);
        }

        weightedSum[0] = 3;
        for (int i = 1; i < 300; i++)
        {
            weightedSum[i] = weightedSum[i - 1] + (i + 1) * numPoints[i + 1];
        }

        for (int i = 0; i < numCases; i++)
        {
            int k = input.nextInt() - 1;
            System.out.println((i + 1) + " " + (k + 1) + " " + weightedSum[k]);
        }
    }
}
