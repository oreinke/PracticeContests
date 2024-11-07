import java.util.*;

class h {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        
        String str = input.nextLine();
        StringBuilder curStr = new StringBuilder(str);
        String sub1 = str.substring(0, str.length() - 1);
        String sub2 = str.substring(1, str.length());
        boolean searching1 = true;
        boolean searching2= true;
        curStr.reverse();

        for (int i = 0; i < str.length(); i++) {
            if (!searching1 && !searching2)
                break;
            curStr.append(curStr.charAt(0));
            curStr.deleteCharAt(0);
            if (searching1 && curStr.indexOf(sub1) != -1) {
                searching1 = false;
            }

            if (searching2 && curStr.indexOf(sub2) != -1) {
                searching2 = false;
            }
        }

        if (!searching1 && !searching2) {
            System.out.println(1);
        }
        else {
            System.out.println(0);
        }
     }
}