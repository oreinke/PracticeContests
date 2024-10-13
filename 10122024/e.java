import java.util.*;

class e
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0 )
        {
            int a = input.nextInt();
            int b = input.nextInt();
            long aL = a;
            long bL = b;
            if ((a + b) == (aL + bL))
            {
                System.out.println("safe addition");
            }
            else
            {
                System.out.println("overflow");
            }

            numCases--;
        }
    }
}