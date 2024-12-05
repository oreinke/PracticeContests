import java.util.*;

public class g
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numGear = input.nextInt();
        HashMap<Integer, ArrayList<Integer>> gears = new HashMap<>();

        while (numGear > 0)
        {
            int size = input.nextInt();
            if (gears.containsKey(size))
            {
                gears.get(size).add(input.nextInt());
            }
            else
            {
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(input.nextInt());
                gears.put(size, temp);
            }

            numGear--;
        }

            ArrayList<Double> multiples = new ArrayList<>();
            for (int size : gears.keySet())
            {
                double speed = 1;
                ArrayList<Integer> curGears = gears.get(size);
                Collections.sort(curGears);
                // System.out.println(curGears.size());
                for (int i = 0; i < curGears.size() / 2; i++)
                {
                    speed *= curGears.get(curGears.size() - 1 - i) / (float) curGears.get(i);
                }            
                multiples.add(speed);
            }

            Collections.sort(multiples);

            double finalSpeed = 1;
            for (int i = 0; i  < multiples.size(); i++)
            {
                finalSpeed *= multiples.get(i);
            }
            // needs to be log
            System.out.println(Math.log(finalSpeed));
    }
}