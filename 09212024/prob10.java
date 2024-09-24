import java.util.*;

public class prob10
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        HashMap<Integer, Integer> previous2 = new HashMap<>();
        HashMap<Integer, Integer> previous = new HashMap<>();

        previous2.put(0, 1);

        for (int i = 1; i < 102; i++)
        {
            HashMap<Integer, Integer> next = new HashMap<>();
    
            for (int key : previous2.keySet())
            {
                next.put(key + i * i, next.getOrDefault(key + i * i, 0) + previous2.get(key));
            }

            for (int key : previous.keySet())
            {
                previous2.put(key, previous2.getOrDefault(key, 0) + previous.get(key));
            }

            previous = next;
        }
        
        int numCases = input.nextInt();
        for (int i = 0; i < numCases; i++)
            System.out.println(previous2.getOrDefault(input.nextInt(), 0));


    }
}
