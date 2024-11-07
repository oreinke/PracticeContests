import java.util.*;

class c {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        HashSet<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');

        String str = input.nextLine();
        int count = 0;
        int countY = 0;

        for (int i= 0; i < str.length(); i++) {
            if (vowels.contains(str.charAt(i))) {
                count++;
                countY++;
            }
            else if (str.charAt(i) == 'y'){
                countY++;
            }
        }
        System.out.println(count + " " + countY);
    }
}