import java.util.*;

class g {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
       
        int r = input.nextInt();
        int c = input.nextInt();
        if (1 == r ) {
            if (1 == c) {
                System.out.println(1);
            }
            else {
                System.out.println(0);
            }
        }
        else {
            // System.out.println( long (r * Math.pow(r - 1, c - 1)));
            long sum = r;
            for (int i = 0; i < c - 1; i++) {
                sum = ((sum % 998244353) * (r - 1)) % 998244353;
            } 
            System.out.println(sum % 998244353);
        }
    }

    
}