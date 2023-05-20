package JAVA;

import java.util.*;

class Temp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t >= 0) {
            int d = sc.nextInt();
            int ans = 2 * d;
            System.out.println(ans);
            t--;
        }
        sc.close();
    }
}