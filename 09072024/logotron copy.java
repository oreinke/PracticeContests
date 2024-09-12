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

            set groups = new set(numBots);
            int[][] transitionFunction = new int[numBots][numBots];

            for (int i = 0; i < numEdges; i++)
            {
                int bot1 = input.nextInt() - 1;
                int bot2 = input.nextInt() - 1;
                int edge = 2;
                if (input.next().equals("T")) 
                    edge = 1;

                transitionFunction[bot1][bot2] = edge;
                groups.union(bot1, bot2);
            }

            HashSet<Integer> distinctGraphs = new HashSet<Integer>();
            for (int i = 0; i < numBots; i++)
            {
                groups.find(i);
            }

            for (int i = 0; i < numBots; i++)
            {
                if (!distinctGraphs.contains(groups.roots[i]))
                {
                    distinctGraphs.add(groups.roots[i]);
                }
            }

            ArrayList<Integer> combosPerGraph = new ArrayList<Integer>();
            for (int root : distinctGraphs)
            {
                // color 1 = T, 2 = C                
                combosPerGraph.add(dfs(root, 0, 0, new int[numBots], new boolean[numBots], transitionFunction, numBots));
            }
        }
    }

    public static int dfs (int curBot, int previousColor, int edge, int[] color, boolean[] checked, int[][] transitionFunction, int numBots)
    {
        ArrayList<Integer> next = new ArrayList<Integer>();
        int sum = 0;
        boolean nextNodeUncolored = false;
        if (color[curBot] == 0)
        {
            
            if (previousColor == 0)
            {
            }

            else
            {
                color[curBot] = (previousColor == 1) ? edge : (edge + 1) % 2;
                for (int i = 0; i < numBots; i++)
                {
                    if (transitionFunction[curBot][i] == 1)
                    {
                        if (color[i] == 2)
                            return 0;
                        next.add(i);
                    }
                    else if (transitionFunction[curBot][i] == 2)
                    {

                    }
                }
            
            }
        
        return sum;
    }


    
}

class set
{
    public int[] roots;

    public set (int n)
    {
        roots = new int[n];
        
        for (int i = 0; i < n; i++)
            roots[i] = i;
    }

    public int find(int num)
    {
        if (roots[num] == num)
            return num;
        else
            roots[num] = find(roots[num]);
        return roots[num];
    }

    public void union (int n1, int n2)
    {
        int x1 = find(n1);
        int x2 = find(n2);

        if (x1 == x2)

        roots[n2] = roots[n1];

    }
}