#include <stdio.h>
#define MAXN 100005
struct pair {
    int first;
    int second;
};
void countSort(struct pair arr[], int n, int exp) {
    struct pair output[n];
    int count[MAXN] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i].first / exp) % 10]++;
    for (int i = 1; i < MAXN; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) 
        output[--count[(arr[i].first / exp) % 10] ] = arr[i];
    for (int i = 0; i < n; i++) 
        arr[i] = output[i];
}
void radixSort(struct pair arr[], int n) {
    int m = arr[0].first;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > m)
            m = arr[i].first;
    }
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int n;
    scanf("%d", &n);
    struct pair arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i].first);
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i].second);
    radixSort(arr, n);
    for (int i = 1; i < n; i++) {
        if (arr[i].first == arr[i - 1].first && arr[i].second < arr[i - 1].second) {
            struct pair temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            while (i > 1 && arr[i].second < arr[i - 1].second) {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i].first);
    printf("\n");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i].second);
    printf("\n");
    return 0;
}


