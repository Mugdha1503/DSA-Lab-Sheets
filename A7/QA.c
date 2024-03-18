#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hexValue(char digit) {
    if (digit >= '0' && digit <= '9')
        return digit - '0';
    else if (digit >= 'A' && digit <= 'F')
        return 10 + digit - 'A';
    else 
        return 0;
}
void radixSortHex(int n, char **arr, int k) {
    int count[16];
    char **output = (char **)malloc(n * sizeof(char *));
    for (int digit = 1; digit <= k; digit++) {
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; i++) {
            int val = hexValue(arr[i][k - digit]);
            count[val]++;
        }
        for (int i = 1; i < 16; i++) 
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int val = hexValue(arr[i][k - digit]);
            output[--count[val]] = arr[i];
        }
        for (int i = 0; i < n; i++) 
            arr[i] = output[i];
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(101 * sizeof(char)); // Assuming max length of hexadecimal number is 100
        scanf("%s", arr[i]);
        // Add zeroes to the left if the hexadecimal number has fewer than k digits
        int len = strlen(arr[i]);
        if (len < k) {
            for (int j = 0; j < k - len; j++) {
                memmove(arr[i] + 1, arr[i], len + 1); // Shift characters to the right
                arr[i][0] = '0'; // Add '0' to the left
            }
        }
    }
    radixSortHex(n, arr, k);
    for (int i = 0; i < n; i++) {
        int len = strlen(arr[i]);
        int j = 0;
        while (arr[i][j] == '0' && j < len - 1) 
            j++;
        printf("%s ", arr[i] + j);
    }
    printf("\n");
    return 0;
}




