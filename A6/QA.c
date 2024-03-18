#include <stdio.h>
#include <stdlib.h>
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
void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}

