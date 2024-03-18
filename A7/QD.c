#include <stdio.h>
#include <stdlib.h>
int checkMissingSum(int arr[], int n, int k) {
    int* freq=(int*)malloc((n+1)*sizeof(int));
    for (int i = 0; i < n; i++) 
        freq[arr[i]]++;
    for (int i = 1; i <= n; i++) 
        if (freq[i] == 0 && freq[k - i] == 0 && k - i >= 1 && k - i <= n) 
            return 1;
    return 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    if (checkMissingSum(arr, n, k)) 
        printf("yes\n");
    else 
        printf("no\n");
    return 0;
}


