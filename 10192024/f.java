import java.util.*;

class f {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        
        int numRolled = input.nextInt();
        HashSet<Integer> rolled = new HashSet<>();
        boolean flag = false;


        for (int i = 0; i < numRolled; i++) {
            int num = input.nextInt();
            if (rolled.contains(num)) {
                flag = true;
                break;
            }
            rolled.add(num);
        }

        if (flag) {
            if (numRolled == 1 ) {
                System.out.println("0 216");
            }
            else if (numRolled == 2) {
                System.out.println("0 36");
            }
            else {
                System.out.println("0 6");
            }
            
        }
        else {
            if (numRolled == 1) {
                System.out.println("60 156");
            }
            else if (numRolled == 2) {
                System.out.println("12 24");
            }
            else {
                System.out.println("3 3");
            }
        }
        
    }
}