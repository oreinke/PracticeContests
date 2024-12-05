import java.util.*;

public class g {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int numPersons = input.nextInt();

        ArrayList<Integer> personsLeft = new ArrayList<>();

        for (int i = 0; i < numPersons; i++)
        {
            personsLeft.add(input.nextInt());
        }

        Collections.sort(personsLeft);

        System.out.println(recursion(0, personsLeft, new ArrayList<>()));
    }

    public static int recursion (int time, ArrayList<Integer> personsLeft, ArrayList<Integer> personsRight)
    {
        Collections.sort(personsLeft);
        Collections.sort(personsRight);
        if (personsLeft.size() < 3)
        {
            return time + personsLeft.get(personsLeft.size() - 1);
        }

        if (personsLeft.size() == 3)
        {
            return time + personsLeft.get(0) + personsLeft.get(1) + personsLeft.get(2);
        }

        ArrayList<Integer> newRight = new ArrayList<>(personsRight);
        ArrayList<Integer> newLeft = new ArrayList<>(personsLeft);
        
        newRight.add(0, newLeft.remove(newLeft.size() - 1));
        int runOne = recursion(time + personsLeft.get(personsLeft.size() - 1) + personsLeft.get(0), newLeft, newRight);

        newRight.add(0, newLeft.remove(newLeft.size() - 1));
        int runGroup = recursion(time + personsLeft.get(0) + personsLeft.get(1) * 2 + personsLeft.get(personsLeft.size() -1), newLeft, newRight);

        return Math.min(runOne, runGroup);
    }
}
