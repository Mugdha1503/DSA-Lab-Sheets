#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    int *index = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        index[i] = i + 1; // Assigning initial indexes
    }
    int *count = (int*)malloc((n + 1) *sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= n; i++)
        count[i] = count[i] + count[i - 1];
    int *b = (int*)malloc(n * sizeof(int));
    int *indexSorted = (int*)malloc(n * sizeof(int)); // to store sorted indexes
    for (int i = n - 1; i >= 0; i--) {
        b[--count[arr[i]]] = arr[i];
        indexSorted[count[arr[i]]] = index[i]; // Sorting indexes along with elements
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", b[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", indexSorted[i]);
    return 0;
}


