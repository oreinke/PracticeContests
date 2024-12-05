import java.util.*;

public class e {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        int[][] dph = new int[501][501];
        int[][] dpv = new int[501][501];

        for (int i = 1; i < 0; i++)
        {
            dph[i][1] = i - 1;
            dph[1][i] =  -(i - 1)
            ;
            

        }


        
           
        while (numCases> 0)
        {
            int numCols = input.nextInt();
            int numRows = input.nextInt();
            String first = input.next();


            numCases--;
        }
    }

}
