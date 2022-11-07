package JAVA;

class Ceiling {
    public static void main(String[] args) {
        int arr[] = { 34, 56, 67, 78, 89, 90, 345 };
        int t = 76;
        int ceil = ceiling(arr, t);
        System.out.println(ceil);

    }

    static int ceiling(int arr[], int t) {
        int s = 0;
        int e = arr.length - 1;
        if (arr[e] < t) {
            return -1;
        }
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (arr[m] < t)
                s = m + 1;
            else if (arr[m] > t)
                e = m - 1;
            else
                return arr[m];

        }
        return arr[s];
    }

}
