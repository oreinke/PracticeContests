import java.util.*;

class k {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        input.nextLine();
        String str = input.nextLine();

        boolean flag = true;
        for (int i = 1; i < n; i++){
            if (i < 10) {
                if (str.charAt(i - 1) != '0' + i) {
                    System.out.println(i);
                    flag = false;
                    break;

                }
            }
            else {
                if (!str.substring(i - 1 + (i - 10), i - 1 + (i - 10) + 2).equals(Integer.toString(i))) {
                    System.out.println(i);
                    flag = false;
                    break;

                }
            }
        }
        if (flag) {
            System.out.println(n);
        }



    }
}