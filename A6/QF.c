#include <stdio.h>
#include <stdlib.h>
int merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int index = 0;
    int cnt = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) 
            temp[index++] = arr[left++];
        else {
            temp[index++] = arr[right++];
            cnt += (mid - left + 1);
        }
    }
    while (left <= mid) 
        temp[index++] = arr[left++];
    while (right <= high) 
        temp[index++] = arr[right++];
    for (int i = low; i <= high; i++) 
        arr[i] = temp[i - low];
    return cnt;
}
int mergeSort(int arr[], int low, int high) {
    int cnt = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
    }
    return cnt;
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int cnt = mergeSort(arr, 0,n-1);
    printf("%d\n", cnt);
    return 0;
}

