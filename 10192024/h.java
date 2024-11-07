import java.util.*;

class h {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
       
        int wheels = input.nextInt();
        int count = 0;
        for (int i = 0; i < 3; i++) {
            
            for (int j = 0; j < wheels; j++) {
                int num = input.nextInt();
                if (7 == num) {
                    count++;
                }
            }
        }

        if (3 != count) {
            System.out.println("0");
        }
        else {
            System.out.println("777");
        }
    }
}