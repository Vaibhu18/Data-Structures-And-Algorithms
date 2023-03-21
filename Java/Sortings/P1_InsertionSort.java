class P1_InsertionSort {

    static void InsertionSort(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int j = i;
            int temp = arr[i];

            while (j > 0 && temp < arr[j - 1]) {
                arr[j] = arr[j - 1];
                j -= 1;
            }
            arr[j] = temp;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 999, 921, 823, 816, 767, 712, 698, 657, 532, 412, 391, 323, 287, 256, 225, 162, 123, 64, 24, 6 };
        InsertionSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}