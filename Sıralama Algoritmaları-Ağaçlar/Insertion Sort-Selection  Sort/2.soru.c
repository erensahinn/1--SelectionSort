#include <stdio.h>

void customSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int max_idx = start;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] > arr[max_idx])
                max_idx = i;
        }
        int temp = arr[end];
        arr[end] = arr[max_idx];
        arr[max_idx] = temp;
        end--;

   
        int min_idx = start;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
      
        temp = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp;
        start++;
    }
}

int main() {
    int arr[] = { 60, 80, 3, 9, 57, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

 
    printf("Öncesi:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    customSort(arr, n);

    printf("Sonrasý:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}