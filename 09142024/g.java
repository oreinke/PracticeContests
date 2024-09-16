import java.util.*;

public class g
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int num = input.nextInt();
            System.out.println((num % 2 == 0) ? num - 1 : num + 1);
            numCases--;
        }
    }
}
