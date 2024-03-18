#include <stdio.h>
#include <limits.h>
int maxProfit(int arr[], int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minPrice)
            minPrice = arr[i];
        if ((arr[i] - minPrice) > maxPro)
            maxPro = arr[i] - minPrice;
    }
    return maxPro;
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
