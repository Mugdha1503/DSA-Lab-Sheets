#include <stdio.h>
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
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <n; i++)
    {
        for (int j = i; j > 0; j--)
            if (arr[j-1] > arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
    }
}
void mergeSortWithInsertion(int arr[], int l, int r, int k) {
    if (l < r) {
        if (r - l <= k) {
            insertion_sort(arr + l, r - l + 1);
        } else {
            int m = l + (r - l) / 2;
            mergeSortWithInsertion(arr, l, m, k);
            mergeSortWithInsertion(arr, m + 1, r, k);
            merge(arr,l,m,r);
        }
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    mergeSortWithInsertion(arr, 0, n - 1, k);
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

