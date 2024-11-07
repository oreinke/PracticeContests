import java.util.*;

public class c {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);

        StringBuilder result = new StringBuilder();

        int t = input.nextInt();
        while (t > 0) {
            input.nextLine();
            String strB= input.nextLine();
            StringBuilder str = new StringBuilder(strB);

            int count = 0;
            for (int i = 0; i < str.length() - 3; i++) {
                if (str.charAt(i) == '1' && str.charAt(i + 1) == '1' && str.charAt(i + 2) == '0' && str.charAt(i + 3) == '0') {
                    count++;
                }
            }
            
            int q = input.nextInt();
            // System.out.println(q);
            while (q > 0) {
                int i = input.nextInt() - 1;
                int chrB =  input.nextInt();
                char chr = '0';
                if (chrB == 1) {
                    chr = '1';
                }

                if (str.charAt(i) != chr) {                    
                    if ((i + 3) < str.length() && str.charAt(i) == '1' && str.charAt(i + 1) == '1' && str.charAt(i + 2) == '0' && str.charAt(i + 3) == '0') {
                        count--;
                    }
                    if ((i + 2) < str.length() && (i - 1) >= 0 && str.charAt(i - 1) == '1' && str.charAt(i) == '1' && str.charAt(i + 1) == '0' && str.charAt(i + 2) == '0') {
                        count--;
                    }
                    if ((i + 1) < str.length() && (i - 2) >= 0 && str.charAt(i - 2) == '1' && str.charAt(i - 1) == '1' && str.charAt(i) == '0' && str.charAt(i + 1) == '0') {
                        count--;
                    }
                    if ((i - 3) >= 0 && str.charAt(i - 3) == '1' && str.charAt(i - 2) == '1' && str.charAt(i - 1) == '0' && str.charAt(i) == '0') {
                        count--;
                    }
                        
                    str.setCharAt(i, chr);

                    if ((i + 3) < str.length() && str.charAt(i) == '1' && str.charAt(i + 1) == '1' && str.charAt(i + 2) == '0' && str.charAt(i + 3) == '0') {
                        count++;
                    }
                    if ((i + 2) < str.length() && (i - 1) >= 0 && str.charAt(i - 1) == '1' && str.charAt(i) == '1' && str.charAt(i + 1) == '0' && str.charAt(i + 2) == '0') {
                        count++;
                    }
                    if ((i + 1) < str.length() && (i - 2) >= 0 && str.charAt(i - 2) == '1' && str.charAt(i - 1) == '1' && str.charAt(i) == '0' && str.charAt(i + 1) == '0') {
                        count++;
                    }
                    if ((i - 3) >= 0 && str.charAt(i - 3) == '1' && str.charAt(i - 2) == '1' && str.charAt(i - 1) == '0' && str.charAt(i) == '0') {
                        count++;
                    }
                }
                
                // result.append(count).append("\n");
                if (count > 0) {
                    result.append("YES\n");
                }
                else {
                    result.append("NO\n");
                }
                
                q--;
            }
            t--;
        }
        System.out.print(result);
    }
}
