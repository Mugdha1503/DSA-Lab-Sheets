#include <stdio.h>
#include <stdlib.h>
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i+1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left]) 
        largest = left;
    if (right < n && arr[largest] < arr[right]) 
        largest = right;
    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    int size = n-1;
    while (size > 0) {
        int temp = arr[size];
        arr[size] = arr[0];
        arr[0] = temp;
        heapify(arr, size, 0);
        size--;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc((n) * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    for (int i = n / 2-1; i >= 0; i--) 
        heapify(arr, n, i);
    heapSort(arr, n);
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}



