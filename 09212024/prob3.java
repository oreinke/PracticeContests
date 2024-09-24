import java.util.*;

public class prob3
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int low = input.nextInt();
        int high = input.nextInt();
        int count = 1;

        while (low < high)
        {
            System.out.println("Case " + count + ": ");
            for (int i = low; i <= high; i++)
            {
                String str = "";
                if (i % 3 == 0)
                {
                    str += "Mercer";
                }
                if (i % 4 == 0)
                {
                    str += "Bears";
                }
                if (i % 18 == 0)
                {
                    str += "Grrrr";
                }
                if (i % 33 == 0)
                {
                    str += "Bite";
                }
                if (str.equals(""))
                {
                    str += i;
                }

                System.out.println(str);
            }

            System.out.println();
            low = input.nextInt();
            high = input.nextInt();
            count++;
        }
    }
}
