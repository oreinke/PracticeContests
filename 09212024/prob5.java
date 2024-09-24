import java.util.*;

public class prob5 {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int i = 1; i <= numCases; i++)
        {
            TreeMap<Double, StringBuilder> result = new TreeMap<>();

            System.out.println("Triathlon #" + i); 
            int numCompetitors = input.nextInt();
            int d1 = input.nextInt();
            int d2 = input.nextInt();
            int d3 = input.nextInt();

            for (int j = 0; j < numCompetitors; j++)
            {
                String name = input.next();

                double s1 = input.nextDouble();
                double s2 = input.nextDouble();
                double s3 = input.nextDouble();
                
                double time = d1/s1 + d2/s2 + d3/s3;
                int timeInt = (int) time;
                StringBuilder str = new StringBuilder();

                str.append(name).append(" ").append(timeInt / 3600).append(" hour(s) ");
                timeInt %= 3600;
                str.append(timeInt / 60).append(" minute(s) ");
                timeInt %= 60;
                str.append(timeInt).append(" second(s)");

                result.put(time, str);
            }
            for (double val : result.keySet())
            {
                System.out.println(result.get(val));
            }

        }
    }
}
