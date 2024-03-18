#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[100];
    for (int i = 0; i < N - 1; i++)
        scanf("%d", arr + i);
    int low = 0, high = N - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == 7)
        {
            printf("%d", mid);
            return 0;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= 7 && 7 <= arr[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= 7 && 7 <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    printf("-1");
    return 0;
}
