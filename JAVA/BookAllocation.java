package JAVA;

public class BookAllocation {
    public static void main(String[] args) {
        int n = 3;
        int m = 5;
        int[] time = { 1, 2, 2, 3, 1 };
        long ans = ayushGivesNinjatest(n, m, time);
        System.out.println(ans);
    }

    // dry run 3 5 {1 2 2 3 1}
    public static long ayushGivesNinjatest(int n, int m, int[] time) {
        // Write your code here.
        long s = 0;
        long e = 0;
        long ans = -1; // 5
        for (int i = 0; i < time.length; i++) {
            e = e + time[i];
        } // e=9
          // 0<=9
          // 0<=3
        while (s <= e) {
            // mid=4
            long mid = s + (e - s) / 2;
            if (isPossible(n, m, time, mid)) {
                ans = mid;// ans=4
                e = mid - 1;// e=4-1=3
            } else
                s = mid + 1;
        }
        return ans;

    }

    public static boolean isPossible(int n, int m, int[] t, long mid) {
        int days = 1;
        long sum = 0;
        // 5
        for (int i = 0; i < m; i++) {
            // 0+1<=4 i=0
            // 1+2<=4 i=1
            // 3+2!<=4 i=2
            // 2+3!<=4 i=3
            // 3+1<=4 i=4
            if (sum + t[i] <= mid) {
                // sum=0+1=1
                // sum=1+2=3
                // sum=3+1=4
                sum = sum + t[i];
            } else {
                // days=1
                // days=2
                days++;
                // 1>3
                // 2>3
                if (days > n || t[i] > mid) {
                    return false;
                }
                // sum=2
                // sum=3
                sum = t[i];
            }
        }
        return true;
        // true

    }
}