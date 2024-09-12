import java.util.*;

public class stock {
    public static void main (String args[])
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        while (numCases > 0)
        {
            int days = input.nextInt();
            double fee = input.nextDouble();
            double cash = input.nextDouble();
            double[] stock1 = new double[days];
            double[] stock2 = new double[days];

            for (int i = 0; i < days; i++)
            {
                stock1[i] = input.nextDouble();
            }

            for (int i = 0; i < days; i++)
            {
                stock2[i] = input.nextDouble();
            }

            System.out.printf("%.2f\n", recursion(0, days - 1, 0, 0, fee, cash, stock1, stock2));
            numCases--;
        }
    }

    public static double recursion(int day, int days, int holding, int shares, double fee, double cash, double[] stock1, double[] stock2)
    {
        if (day == days)
        {
            if (holding == 0)
            {
                return cash;
            }
            if (holding == 1)
            {
                return cash - fee + stock1[day] * shares;
            }
            return cash - fee + stock2[day] * shares;
        }

        // recursion(day + 1, days, , , fee, , stock1, stock2)
        if (holding == 0)
        {
            double buy = Math.max(recursion(day + 1, days, 1,(int) ((cash - fee) / stock1[day]), fee, cash - fee - (((int) ((cash - fee) / stock1[day])) * stock1[day]), stock1, stock2),
                                  recursion(day + 1, days, 2,(int) ((cash - fee) / stock2[day]), fee,cash - fee - (((int) ((cash - fee) / stock2[day])) * stock2[day]) , stock1, stock2));
            return Math.max(buy, recursion(day + 1, days, 0, shares, fee, cash, stock1, stock2));
        }
        else if (holding == 1)
        {
            double sell = Math.max(recursion(day + 1, days, 0, 0, fee, cash - fee + stock1[day] * shares, stock1, stock2),
            recursion(day + 1, days, 2,(int) (((cash - fee + stock1[day] * shares) - fee) / stock2[day]), fee, ((cash - fee + stock1[day] * shares) - fee) -(((int) (((cash - fee + stock1[day] * shares) - fee) / stock2[day])) * stock2[day]), stock1, stock2));
            return Math.max(sell, recursion(day + 1, days, 1, shares, fee, cash, stock1, stock2));
        }
        else
        {
            double sell = Math.max(recursion(day + 1, days, 0, 0, fee, cash - fee + stock2[day] * shares, stock1, stock2),
            recursion(day + 1, days, 1,(int) (((cash - fee + stock2[day] * shares) - fee) / stock1[day]), fee, ((cash - fee + stock2[day] * shares) - fee) - (((int) (((cash - fee + stock2[day] * shares) - fee) / stock1[day])) * stock1[day]), stock1, stock2));
            return Math.max(sell, recursion(day + 1, days, 2, shares, fee, cash, stock1, stock2));
        }
    }

}
