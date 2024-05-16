#include <stdio.h> //GFG
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r, int x) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x) {
            break;
        }
    }
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] >= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int findMedian(int arr[], int n) {
    // Simple sorting algorithm
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) 
                swap(&arr[i], &arr[j]);
        }
    }
    return arr[n / 2];
}
int kthLargest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++) 
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n) {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : kthLargest(median, 0, i - 1, i / 2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos - l == k - 1) 
            return arr[pos];
        if (pos - l > k - 1)
            return kthLargest(arr, l, pos - 1, k);
        return kthLargest(arr, pos + 1, r, k - (pos - l + 1));
    }
    return -1; // Return -1 for invalid cases
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("%d\n", kthLargest(arr, 0, n - 1, k));
    return 0;
}

