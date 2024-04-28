#include <stdio.h>
long peanutButter(int arr[], int ind, int k)
{
    if (ind == 0)
    {
        return (k % arr[0] == 0);
    }
    long notTaken = peanutButter(arr, ind - 1, k);
    long taken = 0;
    if (arr[ind] <= k)
        taken = peanutButter(arr, ind, k - arr[ind]);
    return notTaken + taken;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", peanutButter(arr, n - 1, k));

    return 0;
}
