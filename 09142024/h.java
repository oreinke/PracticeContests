// problems f, h, j were completed w/ assistance from chatgpt
// all others solved w/ java docs as reference material
// no code generated from gpt, algorithm/math approach was generated.
// god bless o1-preview

import java.util.*;

public class h
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();

        ArrayList<Integer> primes = new ArrayList<>();

        for (int i = 2; i < 1000; i++)
        {
            boolean foundDivisor = false;
            for (int num : primes)
            {
                if (i % num == 0)
                {
                    foundDivisor = true;
                    break;
                }
            }

            if (!foundDivisor)
            {
                primes.add(i);
            }
        }
        
        while (numCases > 0)
        {
            int a = input.nextInt();
            int b = input.nextInt();

            long total = 1;

            ArrayList<Integer> factors = new ArrayList<>();

            for (int prime : primes)
            {
                if (a == 1)
                    break;

                long count = 0;
                while (a % prime == 0)
                {
                    count++;
                    a /= prime;
                }

                if (count != 0)
                {
                    count *= b;
                    total = total * (((count + 1) * (count + 2) / 2)) % ((long) Math.pow(10, 9) + 7);
                }
            } 

            System.out.println(total);
            numCases--;
        }
    }
}
