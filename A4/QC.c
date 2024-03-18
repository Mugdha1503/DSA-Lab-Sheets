#include <stdio.h>
int maxSumOfRatings(int n, int k, int ratings[], int time[]) {
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (time[i - 1] <= j)
                dp[i][j] = (ratings[i - 1] + dp[i - 1][j - time[i - 1]]) > dp[i - 1][j] ?
                           (ratings[i - 1] + dp[i - 1][j - time[i - 1]]) : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][k];
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ratings[n], time[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ratings[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &time[i]);
    int maxSum = maxSumOfRatings(n, k, ratings, time);
    printf("%d\n", maxSum);
    return 0;
}


