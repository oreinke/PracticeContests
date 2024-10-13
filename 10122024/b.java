import java.util.*;

class b
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0)
        {
            int numNodes = input.nextInt();
            int numEdges = input.nextInt();
            int numSensors = input.nextInt();

            int[] sensors = new int[numSensors];

            for (int i = 0; i < numSensors; i++)
            {
                sensors[i] = input.nextInt() - 1;
            }

            int[][] graph = new int[numNodes][numNodes];

            for (int i = 0; i < numNodes; i++)
            {
                for (int j = 0; j < numNodes; j++)
                    graph[i][j] = Integer.MAX_VALUE;
            }

            for (int i = 0; i < numNodes; i++)
                graph[i][i] = 0;

            for (int i = 0 ; i < numEdges; i++)
            {
                graph[input.nextInt() - 1][input.nextInt() - 1] = input.nextInt();
            }

            for (int k = 0; k < numNodes; k++)
            {
                for (int i = 0; i < numNodes; i++)
                {
                    for (int j = 0; j < numNodes; j++)
                    {
                        int path2;
                        if (graph[i][k] == Integer.MAX_VALUE || graph[k][j] == Integer.MAX_VALUE)
                        {
                            path2 = Integer.MAX_VALUE;
                        }
                        else
                        {
                            path2 = graph[i][k] + graph[k][j];
                        }
                        graph[i][j] = Math.min(graph[i][j], path2);
                    }
                }
            }

            // for (int i = 0; i < numSensors; i++)
            // {
            //     for (int j = 0; j < numSensors; j++)
            //     {
            //         System.out.print(graph[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            int sum = 0;
            for (int i = 0; i < sensors.length; i++)
            {
                sum += graph[sensors[i]][0];
            }
            System.out.println(sum);
            numCases--;
        }
    }
}