import java.util.*;

class centroid
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int numCase = 0;

        while (n > -1)
        {
            numCase++;
            int xSum = 0;
            int ySum = 0;
            int aMult = 0;
            for (int i = 0; i < n; i++)
            {
                int x = input.nextInt();
                int y = input.nextInt();
                int m = input.nextInt();

                xSum += x * m;
                ySum += y * m;
                aMult += m;             
            }
            float xVal = ((float) xSum) / aMult;
            float yVal = ((float) ySum) / aMult;
            
            System.out.printf("Case %d: %.2f %.2f\n", numCase, xVal, yVal); 


            n = input.nextInt();
        }


    }
}
