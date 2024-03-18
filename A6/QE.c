#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int temp[high - low + 1];
    int k = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp[k++] = arr[left++];
        else
            temp[k++] = arr[right++];
    }
    while (left <= mid)
        temp[k++] = arr[left++];
    while (right <= high)
        temp[k++] = arr[right++];
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void quickSort(int arr[], int low, int high, int maxDepth) {
    if (low < high) {
        int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high) 
            i++;
        while (arr[j] > pivot && j > low) 
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
        int depth = log2(high - low + 1);
        if (depth > maxDepth) {
            mergeSort(arr, low, high);
        } else {
            quickSort(arr, low, j-1, maxDepth);
            quickSort(arr, j+1, high, maxDepth);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    int maxDepth = 2 * log2(n);
    quickSort(arr, 0, n - 1, maxDepth);
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    return 0;
}

