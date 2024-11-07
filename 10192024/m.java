import java.util.*;

class  m{
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
       
        String num = input.nextLine();
        
        boolean flag = true;
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) != ('1' + i)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            System.out.println(num.length());
        }
        else {
            System.out.println("-1");
        }
        
    }
}