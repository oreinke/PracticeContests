import java.util.*;

class j {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        String str = input.nextLine();
        boolean[] arr = new boolean[26];
        boolean flag = false;
        for (int i = 0; i < str.length(); i++) {
            if (arr[str.charAt(i) - 'a']) {
                flag = true;
                break;
            }
            else {
                arr[str.charAt(i) - 'a'] = true;
            }
        }

        if (flag) {
            System.out.println(0);
        }
        else {
            System.out.println(1);
        }
    }

}