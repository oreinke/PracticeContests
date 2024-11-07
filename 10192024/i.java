import java.util.*;

class Page {
    HashSet<Integer> pre;
    HashSet<Integer> target;
    int count;

    public Page() {
        count = 0;
        pre = new HashSet<>();
        target = new HashSet<>();
    }
}

class i {
    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int start = input.nextInt();
        int p = input.nextInt();
        int q = input.nextInt();

        int lastPageSize = n % m;
        Page[] pages;
        if (lastPageSize == 0) {
            pages = new Page[n / m];
        }
        else {
            pages = new Page[n / m + 1];
        }

        for (int i = 0; i < pages.length; i++) {
            pages[i] = new Page();
        }

        for (int i = 0; i < p; i++) {
            int num = input.nextInt() - 1;
            pages[num / m].pre.add(num);
        }

        for (int i = 0; i < q; i++) {
            int num = input.nextInt() - 1;
            if (pages[num / m].pre.contains(num)) {
                pages[num / m].pre.remove(num);
                pages[num / m].count++;
            }
            else {
                pages[num / m].target.add(num);
            }
        }
        boolean[] visit = new boolean[pages.length];
        int result = 0;
        for (int i = 0; i < pages.length; i++) {
            Page curPage = pages[i];

            int optimal = Integer.MAX_VALUE;
            
            if (pages.length - 1 == i && 0 != lastPageSize) {
                optimal = Math.min(curPage.target.size() + curPage.pre.size(), 1 + curPage.target.size() + curPage.count);
                optimal = Math.min(optimal, lastPageSize - (curPage.target.size() + curPage.count) + 1);
                
            }
            else {
                optimal = Math.min(curPage.target.size() + curPage.pre.size(), 1 + curPage.target.size() + curPage.count);
                optimal = Math.min(optimal, m - (curPage.target.size() + curPage.count) + 1);
            }

            result+= optimal;
            if (optimal > 0) {
                visit[i] = true;
            }
        }
        int left = 0;
        int right = pages.length - 1;
        while (!visit[left] && left < pages.length)
            left++;

        while (!visit[right] && right >= 0)
            right--;
        
        if (left != pages.length) {
            right++;
            left++;

            if (start <= left)
            {
                result += right - start;
            }
            else if (start >= right) {
                result += start - left;
            }
            else {
                start -= left;
                right -= left;
                left = 0;
                
                result += Math.min(start - 1 + right - 1, right - start + right - 1);
            }
            
        }
        
        System.out.println(result);

        /*
        for (int i = 0; i < pages.length; i++) {
            System.out.println("Page: " + (i + 1) + "\nPreselected:");
            for (int num : pages[i].pre) {
                System.out.print(num + 1 + " ");
            }
            System.out.println();

            System.out.println("Target:");
            for (int num : pages[i].target) {
                System.out.print(num + 1 + " ");
            }
            System.out.println();
            System.out.println("---------------------------------------------");
            
        }
        System.out.println("Nav: " + Math.min(start - 1 + numPages - 1, numPages - start + numPages - 1));
        */
    }
}