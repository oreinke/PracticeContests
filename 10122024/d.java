import java.util.*;

class d
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numPerformances = input.nextInt();
        StringBuilder result = new StringBuilder();
        while (numPerformances > 0)
        {
            int[] froggies = new int[input.nextInt()];

            int numSwaps = input.nextInt();

            for (int i = 0; i < froggies.length; i++)
                froggies[i] = input.nextInt();

            while (numSwaps > 0)
            {
                int a = input.nextInt();
                int b = input.nextInt();

                int temp = froggies[a - 1];
                froggies[a - 1] = froggies[b - 1];
                froggies[b - 1] = temp;
                numSwaps--;
            }
            
            for (int frog : froggies)
            {
                result.append(frog).append(" ");
            }
            result.deleteCharAt(result.length() - 1);
            result.append("\n");

            numPerformances--;
        }
        System.out.println(result);
    }
}