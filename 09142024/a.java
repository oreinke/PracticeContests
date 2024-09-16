import java.util.*;

public class a
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        long numCases = input.nextLong();

        while (numCases > 0)
        {
            long numFish = input.nextLong();
            TreeMap<Long, Long> fishies = new TreeMap<Long,Long>();
            for (long i = 0; i < numFish; i++)
            {
                Long newFish = input.nextLong();
                fishies.put(newFish, fishies.getOrDefault(newFish, Long.valueOf(0)) + 1);
            }

            while (!fishies.isEmpty() && fishies.ceilingKey(fishies.firstKey() * 2 + 1) != null)
            {
                long smallFry = fishies.firstKey();
                long bigFry = fishies.ceilingKey(smallFry * 2 + 1);
                
                
                if (fishies.get(smallFry) == 1)
                {
                    fishies.remove(smallFry);
                }
                else
                {
                    fishies.put(smallFry, fishies.get(smallFry) - 1);
                }

                if (fishies.get(bigFry) == 1)
                {
                    fishies.remove(bigFry);
                }
                else
                {
                    fishies.put(bigFry, fishies.get(bigFry) - 1);
                }

                fishies.put(bigFry + smallFry, fishies.getOrDefault(bigFry + smallFry, Long.valueOf(0))  + 1);
            }
            

            ArrayList<Long> fishList = new ArrayList<>();
            for (Long entry : fishies.keySet())
            {
                for (long i = 0; i < fishies.get(entry); i++)
                    fishList.add(entry);
            }

            StringBuilder result = new StringBuilder();
            result.append(fishList.size()).append("\n");
            for (Long fish : fishList)
                result.append(fish).append("\n");

            System.out.print(result);
            numCases--;
        }
    }
}