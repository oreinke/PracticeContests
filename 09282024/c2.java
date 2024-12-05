import java.util.*;

public class c2
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

        boolean change = true;

        while(change)
        {
            // System.out.println("persons size: " + persons.size());
            change = false;
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

            ArrayList<Integer> toRemove = new ArrayList<>();
            for (int i = 0; i < persons.size(); i++)
            {
                // System.out.println(i);
                HashSet<Integer> visited = new HashSet<>();
                dfs(i, visited, persons, adjacency);
                // System.out.println(visited.toString());
                if (!visited.contains(i))
                {
                    
                    toRemove.add(i);
                    change = true;
                }
            }

            count += toRemove.size();
            // System.out.println("Count: " + count);
            for (int i = toRemove.size() - 1; i >= 0; i--)
            {
                // System.out.println("Removing: " + persons.get(toRemove.get(i)).num);
                persons.remove(persons.get(toRemove.get(i)));
            }

            
        }
        // if (count == original)
        // {
        //     count--;
        // }

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
            dfs(i, visited, persons, adjacency);
            if (visited.contains(i) && visited.size() > largestGroup)
            {
                largestGroup = visited.size();
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

    static void dfs (int curNode, HashSet<Integer> visited, ArrayList<Person> persons, ArrayList<ArrayList<Integer>> adjacency)
    {
        for (int i : adjacency.get(curNode))
        {
            if (!visited.contains(i))
            {
                visited.add(i);
                dfs(i, visited, persons, adjacency);
            }
        }
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