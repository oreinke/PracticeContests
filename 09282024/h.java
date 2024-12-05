import java.util.*;

public class h {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        input.nextLine();

        while (numCases > 0)
        {
            String str = input.nextLine();
           
            int sqr = 1;
            while (sqr * sqr < str.length())
            {
                sqr++;
            }

            char[][] message = new char[sqr][sqr];

            String pad = "";
            for (int i = 0; i < sqr * sqr - str.length(); i++)
            {
                pad += "*";
            }
            str += pad;
            for (int i = 0; i < message.length; i++)
            {
                for (int j = 0; j < message[0].length; j++)
                {
                    message[i][j] = str.charAt((i * message.length) + j);
                }
            }

            for (int i = 0; i < message.length; i++)
            {
                for (int j = sqr - 1; j >= 0; j--)
                {
                    if (message[j][i] != '*')
                    {
                        System.out.print(message[j][i]);
                    }
                   
                }
            }
            System.out.println();
            
            numCases--;
        }
    }
}
