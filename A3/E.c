#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0;
    int res[n + m];
    int c = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res[c] = a[i];
            i++;
        }
        else
        {
            res[c] = b[j];
            j++;
        }
        c++;
    }
    while (i < n)
    {
        res[c] = a[i];
        i++;
        c++;
    }
    while (j < m)
    {
        res[c] = b[j];
        j++;
        c++;
    }
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", res[i]);
    }
}