import java.util.*;

public class b
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numFriends = input.nextInt();
            HashMap<Integer, Integer> debtors = new HashMap<Integer, Integer>();
            for (int i = 1; i <= numFriends; i++)
                debtors.put(i, input.nextInt());
            
            boolean[] inACycle = new boolean[numFriends];
            int totalDebtorsRemaining = numFriends;
            for (int i = 1; i <= numFriends; i++)
            {
                if (totalDebtorsRemaining == 0)
                {
                    break;
                }
                if (inACycle[i - 1])
                {
                    continue;
                }

                int[] result = cycleCheck(i, i, debtors, new HashSet<Integer>(), inACycle);
                if (result.length == 1)
                {
                    result = cycleCheck(result[0], result[0], debtors, new HashSet<Integer>(), inACycle);
                }

                if (result[0] != -1)
                {
                    for (int num : result)
                    {
                        inACycle[num - 1] = true;
                        totalDebtorsRemaining--;
                    }
                }
                else
                {
                    for (int j = 1; j < result.length; j++)
                    {
                        inACycle[result[j] - 1] = true;
                        
                    }
                }
            }
            System.out.println(totalDebtorsRemaining);            

            numCases--;
        }
    }

    public static int[] cycleCheck(int root, int current, HashMap<Integer, Integer> debtors, HashSet<Integer> visited, boolean[] inACycle)
    {
        visited.add(current);

        if (inACycle[current - 1] || inACycle[debtors.get(current) - 1])
        {
            int[] result = new int[visited.size() + 1];
            int count = 1;
            for (int num : visited)
            {
                result[count] = num;
                count++;
            }
            result[0] = -1;
            return result;
        }
        if (debtors.get(current) == root)
        {
            int[] result = new int[visited.size()];
            int count = 0;
            for (int num : visited)
            {
                result[count] = num;
                count++;
            }
            return result;
        }

        if ((visited.contains(debtors.get(current)) && debtors.get(current) != root))
        {
            return new int[]{debtors.get(current)};
        }

        return cycleCheck(root, debtors.get(current), debtors, visited, inACycle);
    }
}
