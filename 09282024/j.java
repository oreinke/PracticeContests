import java.util.*;

public class j
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numStations = input.nextInt();
        input.nextLine();

        HashMap<String, HashSet<String>> mappings = new HashMap<>();


        for (int i = 0; i < numStations; i++)
        {
            String[] stationDesc = input.nextLine().split(" ");

            if (!mappings.containsKey(stationDesc[0]))
            {
                mappings.put(stationDesc[0], new HashSet<String>());
            }

            for (int j = 1; j < stationDesc.length; j++)
            {
                if (!mappings.containsKey(stationDesc[j]))
                {
                    mappings.put(stationDesc[j], new HashSet<>());
                }

                mappings.get(stationDesc[0]).add(stationDesc[j]);
                mappings.get(stationDesc[j]).add(stationDesc[0]);
            }
        }

        String[] targets = input.nextLine().split(" ");

        HashMap<String, String> visited = new HashMap<>();
        visited.put(targets[0], targets[0]);
        String finalStop = targets[1];

        if (mappings.containsKey(targets[0]) && mappings.containsKey(targets[1]))
        {
            dfs(targets[0], visited, mappings);
        }
        
        if (visited.containsKey(finalStop))
        {
            String result = "";
            String curNode = finalStop;
            while (!visited.get(curNode).equals(curNode))
            {
                result = curNode + " " + result;
                curNode = visited.get(curNode);
            }
            result = curNode + " " + result;

            System.out.println(result.trim());
        }
        else
        {
            System.out.println("no route found");
        }
    }

    public static void dfs(String curNode, HashMap<String, String> visited, HashMap<String, HashSet<String>> mappings)
    {
        HashSet<String> next = mappings.get(curNode);

        for (String node : next)
        {
            if (!visited.containsKey(node))
            {
                visited.put(node, curNode);
                dfs(node, visited, mappings);
            }
        }

    }
}
