import java.util.*;

public class towers 
{
        public static void main(String[] args)
        {
            Scanner input = new Scanner(System.in);

            long k = input.nextLong();
            int n = input.nextInt();
            int caseNum = 1;

            while (k != 0 && n != 0)
            {
                System.out.print("Case " + caseNum + ": ");
                findMove(k, n, 'A', 'C', 'B');

                caseNum++;
                k = input.nextLong();
                n = input.nextInt();
            }
        }

        public static void findMove(long k, int n, char source, char destination, char free)
        {
            long numMoves = (long) Math.pow(2, n - 1);
            if (n == 1)
            {
                System.out.println(n + " " + source + " " + destination);
            }
            else if (k < numMoves)
            {
                findMove(k, n - 1, source, free, destination);
            }
            else if (k == numMoves)
            {
                System.out.println(n + " " + source + " " + destination);
            }
            else
            {
                findMove(k - numMoves, n -1, free, destination, source);
            }
        }
}
