import java.util.*;

public class j {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        while (numCases > 0) {
            int n = input.nextInt();
            int m = input.nextInt();
            String ops[][] = new String[n][2];
            input.nextLine();
            for (int i = 0; i < n; i++) {
                String str[] = input.nextLine().split(" ");
                ops[i][0] = str[0];
                ops[i][1] = str[1];
            }

            HashMap<String, String> nameMap = new HashMap<>();
            for (int i = 0; i < m; i++) {
                String str[] = input.nextLine().split(" ");
                nameMap.put(str[1], str[0]);
            }

            HashMap<String, Integer> counts = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (ops[i][0].equals("1")) {
                    String name = nameMap.get(ops[i][1].substring(0, 12));
                    int add = Integer.parseInt(ops[i][1].substring(12));

                    counts.put(name, counts.getOrDefault(name, 0) + add);
                }
                else {
                    System.out.println(counts.getOrDefault(ops[i][1], 0));
                }
            }
            
            
            numCases--;
        }
    }

}