#include <stdio.h>
#define SIZE 60
#define ULL unsigned long long;
void updateVector(int x, int *v, int increment)
{
    x = (long)x;
    for (int i = 0; i < SIZE; i++)
    {
        if ((x & (1ULL << i)) != 0)
        {
            v[i] += increment;
        }
    }
}
int countNonZero(int *v)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (v[i] != 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    int v[SIZE] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i = 0, j = k - 1, c = 0, maxCount = 0;
    while (i <= j)
    {
        updateVector(a[i], v, 1);
        i++;
    }
    c = countNonZero(v);
    i = 0;
    maxCount = c;
    while (j < n - 1)
    {
        i++;
        j++;
        updateVector(a[i - 1], v, -1);
        updateVector(a[j], v, 1);
        c = countNonZero(v);
        if (c > maxCount)
        {
            maxCount = c;
        }
    }
    printf("%d", maxCount);
}