package JAVA;
//https://leetcode.com/problems/peak-index-in-a-mountain-array/

public class MountainArray {
    public static void main(String[] args) {
        int arr[] = { 34, 56, 67, 78, 38, 24, 14, 9, 8, 7, 1 };
        int index = peakIndexInMountainArray(arr);
        System.out.println(index);

    }

    public static int peakIndexInMountainArray(int[] arr) {
        int s = 0;
        int e = arr.length - 1;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (arr[m] > arr[m + 1])
                e = m;
            else
                s = m + 1;
        }
        return s;

    }

}
