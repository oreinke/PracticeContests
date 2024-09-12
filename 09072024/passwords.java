import java.util.*;

public class passwords
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int length = input.nextInt();
            String[] letterChoices = new String[length];

            input.nextLine();
            for (int i = 0; i < length; i++)
            {
                letterChoices[i] = input.nextLine();
            }
            
            int targetRank = input.nextInt();

            int[] bigNums = new int[length];

            bigNums[length - 1] = letterChoices[length - 1].length();
            for (int i = length - 2; i >= 0; i--)
            {
                bigNums[i] = bigNums[i + 1] * letterChoices[i].length();
            }

            String result = "";
            int index = 0;
            int numLetter = 0;

            while (targetRank != 0)
            {
                if (index == length - 1)
                {
                    result += letterChoices[index].charAt(targetRank - 1);
                    targetRank = 0;
                }
                else
                {
                    if (targetRank - bigNums[index + 1] > 0)
                    {
                        targetRank -= bigNums[index + 1];
                        numLetter++;
                    }
                    else
                    {
                        result += letterChoices[index].charAt(numLetter);
                        index++;
                        numLetter = 0;
                    }
                }
            }
            System.out.println(result);
            numCases--;
        }

    }
}
