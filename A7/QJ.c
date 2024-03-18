// J
#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x)
            count++;
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x)
            printf("%d ", i + 1);
    }
    return 0;
}
