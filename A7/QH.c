// H
#include <stdio.h>
void minHeap(int arr[], int i, int k)
{
    int left = (2 * i + 1), right = (2 * i + 2), smallest = i;
    if (left < k && arr[left] < arr[smallest])
        smallest = left;
    if (right < k && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
        minHeap(arr, smallest, k);
    }
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);
    for (int i = 0; i < n; i++)
        arr1[i] = arr1[i] + arr2[i];
    for (int i = k / 2 - 1; i >= 0; i--)
        minHeap(arr1, i, k);
    for (int i = k; i < n; i++)
    {
        if (arr1[0] < arr1[i])
        {
            arr1[0] = arr1[i];
            minHeap(arr1, 0, k);
        }
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr1[i] > 0)
            sum += arr1[i];
    }
    printf("%d", sum);
}