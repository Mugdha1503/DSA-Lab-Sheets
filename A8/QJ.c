#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function to partition the array around a pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
// Quickselect function to find the k-th largest element
int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        // Partition the array around a pivot
        int pivotIndex = partition(arr, low, high);
        // If pivot is the k-th largest element
        if (pivotIndex == k - 1)
            return arr[pivotIndex];
        // If k-th largest element is in the left subarray
        else if (pivotIndex > k - 1)
            return quickselect(arr, low, pivotIndex - 1, k);
        // If k-th largest element is in the right subarray
        else
            return quickselect(arr, pivotIndex + 1, high, k);
    }
    return -1; // Error case
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    srand(time(0)); // Seed for random function
    int kthLargest = quickselect(arr, 0, n - 1, n - k + 1);
    printf("%d\n", kthLargest);
    return 0;
}

