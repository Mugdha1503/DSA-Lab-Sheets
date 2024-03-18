#include <stdio.h>
#include <stdlib.h>
// Function to find the maximum weight of peanut butter Nom and Psy can eat
long long int maxPeanutButter(int n, long long int *a)
{
    long long int maxWeight = 0;
    long long int nomWeight = 0;
    long long int psyWeight = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        if (nomWeight <= psyWeight)
        {
            nomWeight += a[left];
            left++;
        }
        else
        {
            psyWeight += a[right];
            right--;
        }
        if (nomWeight == psyWeight)
        {
            maxWeight = nomWeight; // Update maxWeight when Nom and Psy eat the same total weight
        }
    }
    return maxWeight;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long int *a = (long long int *)malloc(n * sizeof(long long int));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    long long int result = maxPeanutButter(n, a);
    printf("%lld\n", result);
    free(a);
    return 0;
}
