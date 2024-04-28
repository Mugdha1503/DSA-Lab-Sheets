#include <stdio.h>
int knapsack(int r[], int t[], int indx, int k)
{
    if (indx == 0)
    {
        if (t[indx] <= k)
            return r[indx];
        return 0;
    }
    int notTaken = knapsack(r, t, indx - 1, k);
    int taken = 0;
    if (t[indx] <= k)
        taken = r[indx] + knapsack(r, t, indx - 1, k - t[indx]);
    return (notTaken > taken) ? notTaken : taken;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ratings[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ratings[i]);
    int time[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &time[i]);
    printf("%d", knapsack(ratings, time, n - 1, k));
}
