import java.util.*;

class g
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int count = 0;
            int numPidgeons = input.nextInt();
            for(int i = 0; i < numPidgeons; i++)
            {
                lonh x = input.nextLong();
                long y = input.nextLong();
                long t = input.nextLong();
                
                
                if (x*x +y*y <= t*t)
                {
                    count++;
                }
            }
            if (count != 0)
            {
                int gcd = gcd(numPidgeons, count);
                numPidgeons /= gcd;
                count /= gcd;
            }
            else
            {
                numPidgeons = 1;
            }
            System.out.println(count + "/" + numPidgeons);

            numCases--;
        }
    }

    public static int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
}