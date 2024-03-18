#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            printf("%d", mid + 1);
            return 0;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
