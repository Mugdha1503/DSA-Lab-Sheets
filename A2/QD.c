#include <stdio.h>
int Sqrt(int n)
{
    int ans;
    int low = 0, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1.0;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    int tempSol = Sqrt(n);
    double ans = morePrecision(n, 6, tempSol);
    printf("%lf", ans);
    return 0;
}
