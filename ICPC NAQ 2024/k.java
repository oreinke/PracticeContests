import java.util.*;

public class k
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int expected = input.nextInt();
        int actual = input.nextInt();

        ArrayList<Integer> expectedInput = new ArrayList<>();
        ArrayList<Integer> actualInput = new ArrayList<>();

        for (int i = 0; i < expected; i++)
        {
            expectedInput.add(input.nextInt());
        }

        for (int i = 0; i < actual; i++)
        {
            actualInput.add(input.nextInt());
        }
        Collections.sort(actualInput);
        Collections.sort(expectedInput);
        HashMap<Integer,Integer> dp = new HashMap<>();
        System.out.println(recursion(0, 0, 0, expectedInput, actualInput, dp));
    }

    public static int recursion(int sum, int expectedNum, int actualNum, ArrayList<Integer> expected, ArrayList<Integer> actual, HashMap<Integer,Integer> dp)
    {
        if (dp.containsKey(expectedNum * 10000 + actualNum))
        {
            return sum + dp.get(expectedNum * 10000 + actualNum);
        }

        if (expectedNum >= expected.size() || actualNum >= actual.size())
        {
            return sum;
        }

        int max = sum;
        if (!dp.containsKey((expectedNum + 1) * 10000 + actualNum))
        {
            dp.put((expectedNum + 1) * 10000 + actualNum, recursion(0, expectedNum + 1, actualNum, expected, actual, dp));
        }
        int newSum = dp.get((expectedNum + 1) * 10000 + actualNum) + sum;
        if (newSum > max)
        {
            max = newSum;
        }

        while (actualNum < actual.size() && Math.abs(expected.get(expectedNum) - actual.get(actualNum)) > 102)
        {
            actualNum++;
        }
        
        if (actualNum >= actual.size())
        {
            return max;
        }

     
        if (!dp.containsKey((expectedNum + 1) * 10000 + actualNum + 1))
        {
            dp.put((expectedNum + 1) * 10000 + actualNum + 1, recursion(0, expectedNum + 1, actualNum + 1, expected, actual, dp));
        }
        newSum = dp.get((expectedNum + 1) * 10000 + actualNum + 1) + sum + 2;
        if (newSum > max)
        {
            max = newSum;
        }

        while (actualNum < actual.size() && Math.abs(expected.get(expectedNum) - actual.get(actualNum)) > 43)
        {
            actualNum++;
        }
        
        if (actualNum >= actual.size())
        {
            return max;
        }


        if (!dp.containsKey((expectedNum + 1) * 10000 + actualNum + 1))
        {
            dp.put((expectedNum + 1) * 10000 + actualNum + 1, recursion(0, expectedNum + 1, actualNum + 1, expected, actual, dp));
        }
        newSum = dp.get((expectedNum + 1) * 10000 + actualNum + 1) + sum + 4;
        if (newSum > max)
        {
            max = newSum;
        } 

        while (actualNum < actual.size() && Math.abs(expected.get(expectedNum) - actual.get(actualNum)) > 23)
        {
            actualNum++;
        }
        
        if (actualNum >= actual.size())
        {
            return max;
        }

        if (!dp.containsKey((expectedNum + 1) * 10000 + actualNum + 1))
        {
            dp.put((expectedNum + 1) * 10000 + actualNum + 1, recursion(0, expectedNum + 1, actualNum + 1, expected, actual, dp));
        }
        newSum = dp.get((expectedNum + 1) * 10000 + actualNum + 1) + sum + 6;
        if (newSum > max)
        {
            max = newSum;
        }

        while (actualNum < actual.size() && Math.abs(expected.get(expectedNum) - actual.get(actualNum)) > 15)
        {
            actualNum++;
        }
        
        if (actualNum >= actual.size())
        {
            return max;
        }

        if (!dp.containsKey((expectedNum + 1) * 10000 + actualNum + 1))
        {
            dp.put((expectedNum + 1) * 10000 + actualNum + 1, recursion(0, expectedNum + 1, actualNum + 1, expected, actual, dp));
        }
        newSum = dp.get((expectedNum + 1) * 10000 + actualNum + 1) + sum + 7;
        if (newSum > max)
        {
            max = newSum;
        }

        return max;
    }
}