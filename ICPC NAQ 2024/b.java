import java.util.*;

public class b
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numBarricades = input.nextInt();

        double closest = 1000;
        while (numBarricades > 0)
        {
            int x1 = input.nextInt();
            int y1 = input.nextInt();
            int x2 = input.nextInt();
            int y2 = input.nextInt();
            if ((x1 > 0 && x2 < 0) || (x1 < 0 && x2 > 0))
            {
                double slope = ((y2 - (double) y1) / (x2 - x1));
                double intersect = (-1 * slope * x1) + y1;
                if (intersect >= 0 && intersect < closest)
                {
                    closest = intersect;
                }

            }

           
            numBarricades--;
        }
        if (closest == 1000)
        {
            System.out.println(-1);
        }
        else
        {
            System.out.println(closest);
        }

    }
}