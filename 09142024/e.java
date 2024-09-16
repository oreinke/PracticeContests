import java.util.*;

public class e
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numPeople = input.nextInt();
            int numProspects = input.nextInt();

            ArrayList<Integer> l1a = new ArrayList<Integer>();
            ArrayList<Integer> l1d = new ArrayList<Integer>();
            ArrayList<Integer> l2a = new ArrayList<Integer>();
            ArrayList<Integer> l2d = new ArrayList<Integer>();

            for (int i = 0; i < numPeople; i++)
            {
                int line = input.nextInt();
                if (line == 1)
                {
                    l1a.add(input.nextInt());
                    l1d.add(input.nextInt());

                }
                else
                {

                    l2a.add(input.nextInt());
                    l2d.add(input.nextInt());
                }
            }
            Collections.sort(l1a);
            Collections.sort(l1d);
            Collections.sort(l2a);
            Collections.sort(l2d);

            TreeMap<Integer, Integer> l1aM = new TreeMap<>();
            TreeMap<Integer, Integer> l1dM = new TreeMap<>();
            TreeMap<Integer, Integer> l2aM = new TreeMap<>();
            TreeMap<Integer, Integer> l2dM = new TreeMap<>();

            
            for (int i = 0; i < l1a.size(); i++)
                l1aM.put(l1a.get(i), i + 1);
            
            for (int i = 0; i < l1d.size(); i++)
                l1dM.put(l1d.get(i), i + 1);

            for (int i = 0; i < l2a.size(); i++)
                l2aM.put(l2a.get(i), i + 1);

            for (int i = 0; i < l2d.size(); i++)
                l2dM.put(l2d.get(i), i + 1);

            for (int i = 0; i < numProspects; i++)
            {
                int arrival = input.nextInt();
                int l1Size = (l1aM.floorEntry(arrival) == null) ? 0 : l1aM.floorEntry(arrival).getValue();
                l1Size -= (l1dM.floorEntry(arrival - 1) == null) ? 0 : l1dM.floorEntry(arrival - 1).getValue();
                int l2Size = (l2aM.floorEntry(arrival) == null) ? 0 : l2aM.floorEntry(arrival).getValue(); 
                l2Size -= (l2dM.floorEntry(arrival - 1) == null) ? 0 : l2dM.floorEntry(arrival - 1).getValue();
                // System.out.println("Arrival: " + arrival + ", 1: " + l1Size + ", 2: " + l2Size);

                if (l1Size > l2Size)
                    System.out.println("2");
                else if (l1Size < l2Size)
                {
                    System.out.println("1");
                }
                else
                {
                    System.out.println("either");
                }

            }


            numCases--;
        }
    }
}
