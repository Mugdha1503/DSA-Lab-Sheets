#include <stdio.h>
#define MOD 1000000007
long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % p;
        }
        y = y / 2;
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
    }
    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        result = (result * power(a[i], b[i], MOD)) % MOD;
    }
    printf("%lld\n", result);
}
