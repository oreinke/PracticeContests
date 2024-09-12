import java.util.*;

class change
{
    public static void main (String args[])
    {
        Scanner input = new Scanner(System.in);
        
        int numCases = input.nextInt();

        for (int i = 0; i < numCases; i++)
        {
            int curNum = input.nextInt();
            int numQuarters = 0;
            int numDimes = 0;
            int numNickels = 0;
            int numPennies = 0;

            while (curNum >= 25)
            {
                curNum -= 25;
                numQuarters++;
            }

            while (curNum >= 10)
            {
                curNum -= 10;
                numDimes++;
            }

            while (curNum >= 5)
            {
                curNum -= 5;
                numNickels++;
            }

            numPennies = curNum;

            System.out.println((i + 1) + " " + numQuarters + " QUARTER(S), " + numDimes + " DIME(S), " + numNickels + " NICKEL(S), " + numPennies + " PENNY(S)" );
        }
    }
}