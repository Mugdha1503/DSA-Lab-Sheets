#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] < arr[mid])
            low = mid;
        else
            high = mid - 1;
    }
    printf("%d", low + 1);
    return 0;
}
