import java.util.*;

public class c
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        input.nextLine();
        int count = 0;
        int original;

        ArrayList<Person> persons = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            String[] info = input.nextLine().split(" ");
            HashSet<String> under = new HashSet<>();
             for (int j = 1; j < info.length; j++)
            {
               under.add(info[j]);
            }

            persons.add(new Person(info[1], i, under));
        }
        original = persons.size();

        ArrayList<ArrayList<Integer>> adjacency = new ArrayList<>();
        for (int i = 0; i < persons.size(); i++)
        {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j < persons.size(); j++)
            {
                if (persons.get(j).understands.contains(persons.get(i).speaks) && i != j)
                {
                    temp.add(j);
                }
            }
            adjacency.add(temp);
        }

        int largestGroup = 0;
        for (int i = 0; i < persons.size(); i++)
        {
            HashSet<Integer> visited = new HashSet<>();
            HashSet<Integer> validMembers = new HashSet<>();
            dfs(i, i, visited, validMembers, adjacency);
            if (validMembers.contains(i) && validMembers.size() > largestGroup)
            {
                largestGroup = validMembers.size();
            }
        }
        if (largestGroup == 0)
        {
            System.out.println(original - 1);
        }
        else
        {
            System.out.println(original - largestGroup);
        }
    }

    static void dfs (int curNode, int root, HashSet<Integer> visited, HashSet<Integer> validMembers, ArrayList<ArrayList<Integer>> adjacency)
    {
        HashSet<Integer> temp = new HashSet<>();
        if (dfsValid(curNode, root, temp, adjacency))
        {
            // System.out.println("HIT, ROOT: " + root);
            validMembers.add(curNode);
            for (int i : adjacency.get(curNode))
            {
                if (!visited.contains(i))
                {
                    visited.add(i);
                    dfs(i, root, visited, validMembers, adjacency);
                }
            }
        }
    }

    static boolean dfsValid(int curNode, int root, HashSet<Integer> visited, ArrayList<ArrayList<Integer>> adjacency)
    {
        for (int i : adjacency.get(curNode))
        {
            if (i == root)
                {
                    return true;
                }

            if (!visited.contains(i))
            {
                visited.add(i);
                
                
                if (dfsValid(i, root, visited, adjacency))
                {
                    return true;
                }
            }
        }

        return false;
    }
}

class Person
{
    public String speaks;
    public HashSet<String> understands;
    public int num;

    public Person(String spea, int i, HashSet<String> under)
    {
        speaks = spea;
        understands = under;
        num = i;
    }

}