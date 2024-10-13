import java.util.*;

class k
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numDays = input.nextInt();

        while (numDays > 0)
        {   
            int numSpells = input.nextInt();
            int numToads = input.nextInt();
            int target = input.nextInt();

            HashSet<Integer> add = new HashSet<>();
            HashSet<Integer> mult = new HashSet<>();
            HashSet<Integer> sub = new HashSet<>();

            for (int i = 0; i < numSpells; i++)
            {
                String str = input.next();
                if (str.equals("M"))
                {
                    add.add(input.nextInt());
                }
                else if (str.equals("C"))
                {
                    mult.add(input.nextInt());
                }
                else
                {
                    sub.add(input.nextInt());
                }
            }
            

            ArrayDeque<Integer> frontier = new ArrayDeque<>();
            HashSet<Integer> visited = new HashSet<>();
            visited.add(numToads);
            frontier.add(numToads);
            int step = 0;
            while (!frontier.isEmpty())
            {
                if (visited.contains(target))
                {
                    break;
                }
                step++;
                ArrayDeque<Integer> next = new ArrayDeque<>();
                while (!frontier.isEmpty())
                {
                    int curToads = frontier.pop();
                    for (int term : add)
                    {
                        int subject = term + curToads;
                        
                        if (!visited.contains(subject) && subject >= 0 && subject <= 100000)
                        {
                            visited.add(subject);
                            next.add(subject);
                        }
                    
                    }
                    for (int term : mult)
                    {
                        long subject = (long) term * (long) curToads;
                        int subjectInt = term * curToads;
                        
                        if (!visited.contains(subjectInt) && subject >= 0 && subject <= 100000)
                        {
                            visited.add(subjectInt);
                            next.add(subjectInt);
                        }
                    
                    }
                    for (int term : sub)
                    {
                        int subject = curToads - term;
                        
                        if (!visited.contains(subject) && subject >= 0 && subject <= 100000)
                        {
                            visited.add(subject);
                            next.add(subject);
                        }
                    
                    }
                }
                frontier = next;
            }

            if (visited.contains(target))
            {
                System.out.println(step);
            }
            else
            {
                System.out.println("-1");
            }

            numDays--;
        }
    }
}