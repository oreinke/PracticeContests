import java.util.*;

class h
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {   
            int xNum = input.nextInt();
            int yNum = input.nextInt();
            int zNum = input.nextInt();

            TreeSet<Long> x = new TreeSet<>(Comparator.reverseOrder());
            TreeSet<Long> y = new TreeSet<>(Comparator.reverseOrder());
            TreeSet<Long> z = new TreeSet<>();

            long v = input.nextLong();

            while (xNum > 0)
            {
                x.add(input.nextLong());
                xNum--;
            }

            while (yNum > 0)
            {
                y.add(input.nextLong());
                yNum--;
            }
            while (zNum > 0)
            {
                z.add(input.nextLong());
                zNum--;
            }

            long max = -1;
            for (long i : x)
            {
                for (long j : y)
                {
                    if (v / (i * j) > 0)
                    {
                        if (z.floor(v / (i * j)) != null)
                        {
                            if (i * j * z.floor(v / (i * j)) > max)
                            {
                                max = i * j * z.floor(v / (i * j));
                            }
                        }
                    }
                }
            }
            if (max == -1)
            {
                System.out.println("DISQUALIFIED!");
            }
            else
            {
                System.out.println(max);
            }
            numCases--;
        }
    }
}