import java.util.*;

class i
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numDays = input.nextInt();

        while (numDays > 0)
        {
            int r = input.nextInt();
            int l = input.nextInt();

            System.out.printf("%.2f\n", ((float) l * l) - ((Math.PI * r * r)/4));


            numDays--;
        }
    }
}