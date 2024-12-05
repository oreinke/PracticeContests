import java.util.*;

public class j
{
    public static void main(String args[])
    {
        Scanner input =  new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0)
        {
            int numRows = input.nextInt();
            int numCols = input.nextInt();

            String[] stars = new String[numRows];

            for (int i = 0; i < numRows; i++)
            {
                stars[i] = input.next();
            }

            // We can narrow down the algo to consider 2 possible solutions.
            // based off of first row, the column lasers must be equal to the stars from 
            // from the first row or the inverse.

            String laserCols = stars[0];
            String laserColsInverse = "";

            boolean match1 = true;
            String result1 = "0";            

            for (int i = 0; i < laserCols.length(); i++)
            {
                if (laserCols.charAt(i) == '0')
                {
                    laserColsInverse += '1';
                }
                else if (laserCols.charAt(i) == '1')
                {
                    laserColsInverse += '0';
                }
            }

            for (int i = 1; i < numRows; i++)
            {
                if (stars[i].equals(laserCols))
                {
                    result1 += " 0";
                }
                else if (stars[i].equals(laserColsInverse))
                {
                    result1 += " 1";
                }
                else
                {
                    match1 = false;
                    break;
                }
            }

            boolean match2 = true;
            String result2 = "1";            

            for (int i = 1; i < numRows; i++)
            {
                if (stars[i].equals(laserColsInverse))
                {
                    result2 += " 0";
                }
                else if (stars[i].equals(laserCols))
                {
                    result2 += " 1";
                }
                else
                {
                    match2 = false;
                    break;
                }
            }

            String rowLaser1 = "";
            for (int i = 0; i < laserCols.length(); i++)
            {
                if (laserCols.charAt(i) == '0')
                {
                    rowLaser1 += "0 ";
                }
                else if (laserCols.charAt(i) == '1')
                {
                    rowLaser1 += "1 ";
                }
            }

            String rowLaser2 = "";
            for (int i = 0; i < laserCols.length(); i++)
            {
                if (laserColsInverse.charAt(i) == '0')
                {
                    rowLaser2 += "0 ";
                }
                else if (laserColsInverse.charAt(i) == '1')
                {
                    rowLaser2 += "1 ";
                }
            }

            result1 = result1.trim();
            result2 = result2.trim();
            rowLaser1 = rowLaser1.trim();
            rowLaser2 = rowLaser2.trim();

            if (match1 && match2)
            {
                if (result1.charAt(0) == '1')
                {

                    System.out.println(result1);
                    System.out.println(rowLaser1);
                }
                else
                {
                    System.out.println(result2);
                    System.out.println(rowLaser2);
                }
            }
            else if (match1)
            {
                System.out.println(result1);
                System.out.println(rowLaser1);
            }
            else if (match2)
            {
                System.out.println(result2);
                System.out.println(rowLaser2);
            }
            else
            {
                System.out.println("impossible");
            }

            numCases--;
        }
    }
}