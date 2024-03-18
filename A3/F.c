#include <stdio.h>
int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            sum[i] = a[i];
        }
        else
            sum[i] = sum[i - 1] + a[i];
    }
    int i = 0, j = k - 1, c = 0;
    while (j < n)
    {
        if (i == 0)
        {
            if ((sum[j] / k) >= x)
            {
                c++;
            }
        }
        else
        {
            if ((sum[j] - sum[i - 1]) / k >= x)
            {
                c++;
            }
        }
        i++;
        j++;
    }
    printf("%d", c);
}