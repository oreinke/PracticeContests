import java.util.*;

public class prob4 {
    public static void main (String args[])
    {
        Scanner input = new Scanner(System.in);
        HashMap<String,String> first = new HashMap<>();
        HashMap<String,String> last = new HashMap<>();

        for (int i = 0; i < 26; i++)
        {
            String letter = input.next().substring(0, 1);
            String bunny = input.nextLine();
            while (bunny.charAt(0) == ' ')
                bunny = bunny.substring(1);
            while (bunny.charAt(bunny.length() - 1) == 0)
                bunny = bunny.substring(0, bunny.length() - 1);
            first.put(letter, bunny);
        }
        for (int i = 0; i < 26; i++)
        {
            String letter = input.next().substring(0, 1);
            String bunny = input.nextLine();
            while (bunny.charAt(0) == ' ')
                bunny = bunny.substring(1);
            while (bunny.charAt(bunny.length() - 1) == 0)
                bunny = bunny.substring(0, bunny.length() - 1);
            last.put(letter, bunny);
        }

        int numCases = input.nextInt();

        for (int i = 0; i < numCases; i++)
        {
            String f = input.next();
            String l = input.next();
            System.out.println(f + " " + l + " = " + first.get(f.substring(0,1)) + " "  + last.get(l.substring(0, 1)));
        }
    }
}
