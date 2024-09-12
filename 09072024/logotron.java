import java.util.*;

public class logotron
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();

        for (int caseNum = 1; caseNum <= numCases; caseNum++)
        {
            int numBots = input.nextInt();
            int numEdges = input.nextInt();

            List<int[]> edgeList = new ArrayList<>();

            for (int i = 0; i < numEdges; i++)
            {
                int bot1 = input.nextInt() - 1;
                int bot2 = input.nextInt() - 1;
                int edge = 2;
                if (input.next().equals("T")) 
                    edge = 1;

                edgeList.add(new int[]{bot1, bot2, edge});
            }

            int sum = 0;
            for (int i = 0; i < Math.pow(2, numBots); i++)
            {
                int[] colors = new int[numBots];
                
                // find next combo of bots
                for (int j = 0; j < numBots; j++)
                {
                    colors[j] = 1 + ((i & (1 << j)) >> j);
                }
                
                // check if the combo is valid
                boolean invalid = false;
                for (int[] edge : edgeList)
                {
                    if ((colors[edge[0]] == 1 && edge[2] != colors[edge[1]]) || colors[edge[0]] == 2 && edge[2] == colors[edge[1]])
                    {
                       invalid = true;
                       break;
                    }
                }

                if (!invalid)
                {
                    sum++;
                    // System.out.print("Valid combo: ");
                    // for (int num : colors)
                    //     System.out.print(num);
                    // System.out.println();
                }
        
            }

            System.out.println("Case #" + caseNum + ": " + sum);
        }
    }
}