import java.util.*;
public class c
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while(numCases > 0)
        {
            int curLength = input.nextInt();
            int targetLength = input.nextInt();

            int gen = 0;
            while (curLength < targetLength)
            {
                curLength = curLength * 2 + 1;
                gen++;
            }
            System.out.println(gen);
            numCases--;
        }
    }
}
