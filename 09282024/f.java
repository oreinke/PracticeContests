import java.util.*;
public class f{

    public static void main(String args[]) 
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        input.nextLine();

        HashSet<Character> letters = new HashSet<>();
        for (int i = 0; i < 26; i++)
        {
            int letter = 'a' + i;
            letters.add((char) letter);
        }

        while (numCases > 0)
        {   
            HashSet<Character> curLetters = new HashSet<>(letters);
            String str = input.nextLine().toLowerCase();
            for (int i = 0; i < str.length(); i++)
            {
                if (curLetters.isEmpty())
                {
                    break;
                }
                curLetters.remove(str.charAt(i));
            }

            if (curLetters.isEmpty())
            {
                System.out.println("pangram");
            }
            else
            {
                System.out.print("missing ");
                for (char c : curLetters)
                {
                    System.out.print(c);
                }
                System.out.println();
            }
            numCases--;
        }
    }
}