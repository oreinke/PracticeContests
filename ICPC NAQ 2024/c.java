import java.util.*;

public class c
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        int count = 0;
        while (n > 0)
        {
            if (input.nextInt() % 2 == 1)
                count++;

            n--;
        }

        System.out.println(count);

    }
}