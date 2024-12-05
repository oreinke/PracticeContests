import java.util.*;

public class d {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        ArrayList<int[]> vectors = new ArrayList<>();

        int numVectors = input.nextInt();

        for (int i = 0; i < numVectors; i++)
        {
            vectors.add(new int[]{input.nextInt(), input.nextInt()});
        }

        HashMap<String, Long> memo = new HashMap<>();
        System.out.println(dp(0, 0, 0, vectors, memo) - 1);
    }

    public static long dp(int step, long x, long y, ArrayList<int[]> vectors, HashMap<String, Long> memo)
    {
        if (step == vectors.size())
        {
            if (x == 0 && y == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (!memo.containsKey(step + "," + x +"," + y))
        {
            memo.put(step + "," + x +"," + y, dp(step + 1, x + vectors.get(step)[0], y + vectors.get(step)[1], vectors, memo) + dp(step + 1, x, y, vectors, memo));        
        }

        return memo.get(step + "," + x +"," + y);
    }
}
