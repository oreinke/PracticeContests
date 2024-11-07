import java.util.*;

class k {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        StringBuilder result = new StringBuilder();


        while (numCases > 0) {
            int ser = input.nextInt();
            int cas = input.nextInt();
            int a = input.nextInt();
            int b = input.nextInt();
            int sessions = 0;

            boolean flag = false;
            if (!compareFractions(ser, ser + 1, a, b)) {
                result.append("-1\n");
            }
            else {
                while (cas > 0){
                    cas -=  (b - a) * (ser / a) + (((ser % a) * (b - a)) / a);
                    ser +=  (b - a) * (ser / a) + (((ser % a) * (b - a)) / a);

                    sessions++;                    
                }


                result.append(sessions).append("\n");
            }
           
            numCases--;
        }
        System.out.print(result);

    }

    public static boolean compareFractions(int n1, int d1, int n2, int d2) {
        return (n1 * d2 >= n2 * d1);
            
    }
}