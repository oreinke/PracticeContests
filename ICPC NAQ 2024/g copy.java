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

            ArrayList<Float> multiples = new ArrayList<>();
            for (int size : gears.keySet())
            {
                if (gears.get(size).size() < 2)
                {
                    continue;
                }
                float speed = 1;
                ArrayList<Integer> curGears = gears.get(size);
                Collections.sort(curGears);

                float best = -1;
                for (int i = 0; i < curGears.size(); i++)
                {
                    ArrayList<Integer> newList = new ArrayList<>(curGears);
                    newList.remove(i);
                    float run = greatestMult(1, curGears.get(i), newList);
                    if (run > best)
                    {
                        best = run;
                    }
                }
                multiples.add(best);                
            }

            Collections.sort(multiples);

            float finalSpeed = 1;
            for (int i = multiples.size() - 1; i >=0; i--)
            {
                finalSpeed *= multiples.get(i);
            }
            // needs to be log
            System.out.println(Math.log(finalSpeed));
    }

    public static float greatestMult(float speed, int prevGear, ArrayList<Integer> remaining)
    {
        if (remaining.isEmpty())
        {
            return speed;
        }

        float best = -1;

        for (int i = 0; i < remaining.size(); i++)
        {
            ArrayList<Integer> newList = new ArrayList<>(remaining);
            newList.remove(i);
            float run = greatestMult(speed * (prevGear / ((float) remaining.get(i))),  remaining.get(i), newList);
            if (run > best)
            {
                best = run;
            }
        }
        return best;
    }
}