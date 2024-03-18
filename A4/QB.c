#include <stdio.h>
#include <limits.h>
int result = INT_MAX;
int min(int maxie, int result)
{
    if (maxie < result)
        result = maxie;
    return result;
}
void beauty(int ind, int a[], int n, int cookies[], int k)
{
    if (ind >= n)
    {
        int maxie = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            if (cookies[i] > maxie)
                maxie = cookies[i];
        }
        result = min(maxie, result);
        return;
    }
    int cookie = a[ind];
    for (int i = 0; i < k; i++)
    {
        cookies[i] += cookie;
        beauty(ind + 1, a, n, cookies, k);
        cookies[i] -= cookie;
    }
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int ind = 0;
    int cookies[k];
    for (int i = 0; i < k; i++)
       cookies[i] = 0;
    beauty(ind, a, n, cookies, k);
    printf("%d", result);
    return 0;
}


