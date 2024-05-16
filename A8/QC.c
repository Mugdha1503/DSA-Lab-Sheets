#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
// Function to find the sum of minimums of all subarrays
long long sumOfMinimums(int arr[], int n) {
    long long result = 0;
    long long left[n], right[n];
    int stack[n], top = -1;
    // Finding the index of the previous smaller element
    for (int i = 0; i < n; ++i) {
        while (top != -1 && arr[stack[top]] >= arr[i])
            --top;
        left[i] = (top == -1) ? i + 1 : i - stack[top];
        stack[++top] = i;
    }
    // Clearing the stack
    top = -1;
    // Finding the index of the next smaller element
    for (int i = n - 1; i >= 0; --i) {
        while (top != -1 && arr[stack[top]] > arr[i])
            --top;
        right[i] = (top == -1) ? n - i : stack[top] - i;
        stack[++top] = i;
    }
    // Calculating the sum of minimums for each element
    for (int i = 0; i < n; ++i)
        result = (result + arr[i] * left[i] % MOD * right[i] % MOD) % MOD;
    return result;
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    long long ans = sumOfMinimums(arr, n);
    printf("%lld\n", ans);
    return 0;
}

