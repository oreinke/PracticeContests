import java.util.*;

public class prob6
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        
        int numCases = input.nextInt();
        input.nextLine();

        while (numCases > 0)
        {

            String str = input.nextLine();
            String[] strSplit = str.split(" ");
            int[] sequence = new int[strSplit.length];

            int index = 0;
            for (String num : strSplit)
            {
                sequence[index] = Integer.parseInt(num);
                index++;
            }

            boolean[] caught =new boolean[sequence.length];
            boolean[] spareCatch =new boolean[sequence.length];

            boolean impossible = false;

            for (int i = 0; i < sequence.length; i++)
            {
                if (impossible)
                {
                    break;
                }
                if (sequence[i] == 0)
                {
                    continue;
                }

                if (sequence[(sequence[i] + i) % (sequence.length)] == 0)
                {
                    impossible = true;
                }
                else
                {
                    if (!caught[(sequence[i] + i) % (sequence.length)])
                    {
                        caught[(sequence[i] + i) % (sequence.length)] = true;
                    }
                    else
                    {
                        impossible = true;
                    }
                }
            }

            // for (boolean val : caught)
            // {
            //     System.out.print(val + " ");
            // }
            // System.out.println("\n "+ impossible);

            if (impossible)
            {
                System.out.println(str + " - cannot be juggled");
            }
            else
            {
                System.out.println(str + " - can be juggled");
            }
            
            numCases--;
        }
    }
}
