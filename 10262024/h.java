import java.util.*;

public class h {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();

        while (numCases > 0) {
            int numNames = input.nextInt();
            input.nextLine();
            String names[] = new String[numNames];

            int count = 1;
            for (int i = 0; i < numNames; i++) {
                names[i] = input.nextLine();
            }

            int middle = numNames / 2;
            boolean found = false;
            while (!found && middle < numNames - 1) {
                // compare left and right

                int i = middle - 1;
                int j = middle + 1;
                while (j < numNames) {
                    if (!names[i].equals(names[j])) {
                        break;
                    }

                    i--;
                    j++;
                }

                if (j == numNames) {
                    found = true;
                    break;
                }
                middle++;
            }
            System.out.println(2 * middle - numNames + 1);


            numCases--;
        }
    }

}