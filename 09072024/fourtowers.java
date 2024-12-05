import java.util.*;

public class fourtowers
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int count = 1;
        while (input.hasNext())
        {
            int n = input.nextInt();

            System.out.println("Case " + count + ": " + hanoi(n, 1, 2, 3, 4));

            count++;
            input.nextLine();
        }
    }

    // n = num disks
    // s = source peg
    // f1 = free peg 1
    // f2 = free peg 2
    // d = destination
    public static int hanoi(int n, int s, int f1, int f2, int d)
    {
        
    }
}