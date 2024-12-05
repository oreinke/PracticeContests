import java.util.*;

public class k
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numSensor = input.nextInt();

        int[][] sensors = new int[numSensor][3];

        for (int i = 0; i < numSensor; i++)
        {
            sensors[i][0] = input.nextInt();
            sensors[i][1] = input.nextInt();
            sensors[i][2] = input.nextInt();
        }

        HashMap<Integer, Integer> groups = new HashMap<>();
        HashMap<Integer, boolean[]> edgeConnections = new HashMap<>();
        int groupNum = 1;

        int k = 0;
        boolean blocked = false;
        while (k < numSensor && !blocked)
        {
            boolean touchingLeft = touching(sensors[k], new int[]{0, sensors[k][1], 0});
            boolean touchingRight = touching(sensors[k], new int[]{200, sensors[k][1], 0});
            // System.out.println(touchingLeft);
            // System.out.println(touchingRight);

            HashSet<Integer> touchingSensorGroup = new HashSet<>();
            boolean foundConnect = false;
            for (int i = k - 1; i >= 0; i--)
            {
                if (touching(sensors[i], sensors[k]))
                {
                    touchingSensorGroup.add(groups.get(i));
                }
            }

            if (touchingSensorGroup.isEmpty())
            {
                groups.put(k, groupNum);
                edgeConnections.put(groupNum, new boolean[]{touchingLeft, touchingRight});
                groupNum++;
            }
            else if (touchingSensorGroup.size() == 1)
            {
                for (int i : touchingSensorGroup)
                    groups.put(k, i);
                if (touchingLeft)
                {
                    edgeConnections.get(groups.get(k))[0] = true;
                }

                if (touchingRight)
                {
                    edgeConnections.get(groups.get(k))[1] = true;
                }
            }
            else
            {
                int count = 0;
                int firstKey = 0;
                for (int i : touchingSensorGroup)
                {
                    if (count == 0)
                    {
                        firstKey = i;
                        groups.put(k, i);
                        if (touchingLeft)
                        {
                            edgeConnections.get(groups.get(k))[0] = true;
                        }

                        if (touchingRight)
                        {
                            edgeConnections.get(groups.get(k))[1] = true;
                        }
                    }
                    else
                    {
                        if (edgeConnections.get(i)[0])
                        {
                            edgeConnections.get(firstKey)[0] = true;
                        }

                        if (edgeConnections.get(i)[1])
                        {
                            edgeConnections.get(firstKey)[1] = true;
                        }
                    }

                    count++;
                }

                for (int i : groups.keySet())
                {
                    if (touchingSensorGroup.contains(groups.get(i)))
                    {
                        groups.put(i, firstKey);
                    }
                }
            }

            if (edgeConnections.get(groups.get(k))[0] && edgeConnections.get(groups.get(k))[1])
            {
                // System.out.println("HIT");
                blocked = true;
                k--;
            }

            k++;
        }


        System.out.println(k);
    }

    public static boolean touching (int[] s1, int[] s2)
    {
        // System.out.println(s1[0] + " " + s1[1] + " " + s1[2] + " | " + s2[0] + " " + s2[1] + " " + s2[2]);
        double distance = Math.sqrt((s1[0] - s2[0]) * (s1[0] - s2[0]) + (s1[1] - s2[1]) * (s1[1] - s2[1]));
        // System.out.println(distance);
        return distance <= s1[2] + s2[2];
    }
}
