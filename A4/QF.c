#include <stdio.h>
int count_combinations(int weights[], int n, int k) {
    int dp[k+1];
    for(int i = 0; i <= k; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = weights[i]; j <= k; j++) {
            dp[j] += dp[j - weights[i]];
        }
    }
    return dp[k];
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int weights[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    int ways = count_combinations(weights, n, k);
    printf("%d\n", ways);
    return 0;
}



