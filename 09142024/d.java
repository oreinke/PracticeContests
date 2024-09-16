import java.util.*;

public class d
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        input.nextLine();

        while (numCases > 0)
        {   
            String str = input.nextLine();
            if(!(str.charAt(0) == '0' && str.charAt(2) == '0' && str.charAt(3) == '0'))
                System.out.print("!");
            System.out.println("legend");

            numCases--;
        }
    }
}
