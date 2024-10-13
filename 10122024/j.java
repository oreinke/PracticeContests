import java.util.*;

class j
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        

        while (numCases > 0)
        {
            input.nextLine();
            String str = input.nextLine();
            // System.out.println(str);
            int[][] sets = new int[str.length() + 1][26];
            int[] counts = new int[26];
            
            for (int i = 0; i < str.length(); i++)
            {
                counts[str.charAt(i) - 'a']++;
                for (int j = 0; j < 26; j++)
                {
                    sets[i + 1][j] = counts[j];
                }
            }
            
            int numQ = input.nextInt();

            while (numQ > 0)
            {   
                int sum = 0;
                int s = input.nextInt();
                int e = input.nextInt();

                // for (int i = 0; i < 26; i ++)
                //         System.out.print(sets[e][i]);
                // System.out.println();

                // for (int i = 0; i < 26; i ++)
                //         System.out.print(sets[s - 1][i]);
                // System.out.println();
                for (int i = 0; i < 26; i++)
                {
                    
                    if (sets[e][i] > sets[s - 1][i])
                    {
                        sum++;
                    }
                }

                System.out.println(sum);

                numQ--;
            }

            numCases--;
        }
    }
}