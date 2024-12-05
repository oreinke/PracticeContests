import java.util.*;

public class j
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int l = input.nextInt();

        int xNum = input.nextInt();
        int xDen = input.nextInt();
        int yNum = input.nextInt();
        int yDen = input.nextInt();
        int zNum = input.nextInt();
        int zDen = input.nextInt();
        

        xNum *= (Math.pow(3, l) / xDen);
        yNum *= (Math.pow(3, l) / yDen);
        zNum *= (Math.pow(3, 1) / zDen);

        int count = 0;
        if (xNum % 3 == 2)
        {
            count++;
        }

        if (yNum % 3 == 2)
        {
            count++;
        }

        if (zNum % 3 == 2)
        {
            count++;
        }
        
        if (count > 1)
        {
            System.out.println(0);
        }
        else
        {
            System.out.println(1);
        }
    }
}