#include <stdio.h>
int isprime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int flag = 0;
    long long int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (isprime(a[i]) == 0)
        {
            prod = (prod * a[i]) % (1000000007);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", prod);
    }
}