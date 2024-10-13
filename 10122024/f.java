import java.util.*;

class f
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
       

        while (numCases > 0)
        {
            int length = input.nextInt();
            HashSet<Integer> shifts = new HashSet<>();
            long[] differences = new long[length];
            long sum = 0;
            for (int i = 0; i < length; i++)
            {
                sum += i + 1;
                int num = input.nextInt() - 1;

                if (i >= num)
                {
                    differences[i - num] += num + 1;
                }
                else
                {
                    differences[i + (length - num)] += num + 1;
                }

                // System.out.print(differences[i] + " ");
            }
            // System.out.println();
            // for (int i : differences)
            //     System.out.print(i + " ");
            // System.out.println();
            long min = Long.MAX_VALUE;
            for (int i = 0; i < length; i++)
            {
                // System.out.println(i);
                if (min == 0)
                {
                    break;
                }
                
                if (sum - differences[i] < min)
                {
                    // System.out.println("New sum on i: " + i);
                    min = sum - differences[i];
                }
            }
            System.out.println(min);


            numCases--;
        }
    }
}