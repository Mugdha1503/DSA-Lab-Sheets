#include <stdio.h>
#include <limits.h>
int maxProfit(int arr[], int n)
{
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            maxProfit += arr[i] - arr[i - 1];
        }
    }
    return maxProfit;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int profit = maxProfit(a, n);
    printf("%d", profit);
    return 0;
}
