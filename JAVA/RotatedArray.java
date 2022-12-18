package JAVA;

public class RotatedArray {
  public static void main(String[] args) {
    int[] arr = { 4, 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int ans = pivot(arr);
    System.out.println(ans);

  }

  static int pivot(int arr[]) {
    int s = 0;
    int e = arr.length - 1;
    while (s <= e) {
      int m = s + (e - s) / 2;
      // 4 cases
      if (e > m && arr[m] > arr[m + 1])
        return arr[m];
      else if (m > s && arr[m] < arr[m - 1])
        return arr[m - 1];
      else if (arr[m] <= arr[s])
        e = m + 1;
      else
        s = s + 1;
    }
    return -1;
  }
}
