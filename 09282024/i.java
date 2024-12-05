import java.util.*;

public class i 
{
    public static void main (String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        input.nextLine();

        while (numCases > 0)
        {
            String str = input.nextLine();
            if (str.length() > 11 && str.substring(0, 10).equals("Simon says"))
            {
                System.out.println(str.substring(10, str.length()));
            }

            numCases--;
        }
    }
}
