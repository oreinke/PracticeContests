import java.util.*;

public class b {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        int[] factorials = new int[11];
        factorials[0] = 1;
        factorials[1] = 1;
        
        for (int i = 2; i < 11; i++)
        {
            factorials[i] = i * factorials[i - 1];
        }

        while (numCases > 0)
        {
            int numer = input.nextInt();
            int denom = input.nextInt();
            double p = (denom - numer + 1.0) / denom;
            int target = input.nextInt();
            int runs = input.nextInt();

            double probSum = 0;
            for (int i = target; i <= runs; i++)
            {
                int choose = factorials[runs] / (factorials[runs - i] * factorials[i]);
                probSum += choose * Math.pow(p, i) * Math.pow(1 - p, runs - i);
            }

            if (probSum * input.nextInt() > 1)
            {
                System.out.println("yes");
            }
            else
            {
                System.out.println("no");
            }

            numCases--;
        }
    }
}
