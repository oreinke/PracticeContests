import java.util.*;

public class c {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0) {
            int n = input.nextInt();
            input.nextLine();

            HashMap<String, Long> counts = new HashMap<>();
            
            while (n > 0) {
                String crypt = cipher(input.nextLine());
                counts.put(crypt, counts.getOrDefault(crypt,0L) + 1);
                n--;
            }

            long answer = 0;
            for (String key : counts.keySet()) {
                answer += counts.get(key) * counts.get(key);
            }

            System.out.println(answer);

            numCases--;
        }
    }

    public static String cipher (String str) {
        StringBuilder result = new StringBuilder();
        HashMap<Character, Character> mappings = new HashMap<>();
        char strArr[] = str.toCharArray();

        int count = 0;
        for (int i = 0; i < strArr.length; i++) {
            if (!mappings.containsKey(strArr[i])) {
                mappings.put(strArr[i], (char) ('a' + count));
                count++;
            }
            result.append(mappings.get(strArr[i]));
        }

        return result.toString();
    }
}