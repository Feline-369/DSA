package JAVA;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = { 9, 7, 8, 0, 5, 4 };
        SelecSort(arr);
    }

    public static void SelecSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int min = i;

            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        for (int k = 0; k < arr.length; k++) {
            System.out.print(arr[k]);
        }

    }

}
