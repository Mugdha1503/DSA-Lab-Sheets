// G
#include <stdio.h>
#include <stdlib.h>
void maxHeapify(int arr[], int i, int k, int x)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < k && abs(arr[left] - x) >= abs(arr[largest] - x))
        largest = left;
    if (right < k && abs(arr[right] - x) >= abs(arr[largest] - x))
        largest = right;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, largest, k, x);
    }
}
int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = k / 2 - 1; i >= 0; i--)
        maxHeapify(arr, i, k, x);
    for (int i = k; i < n; i++)
    {
        if (abs(arr[0] - x) > abs(arr[i] - x) || (abs(arr[0] - x) == abs(arr[i] - x) && arr[0] - x > 0 && arr[i] - x < 0))
        {
            arr[0] = arr[i];
            maxHeapify(arr, 0, k, x);
        }
    }
    for (int i = 1; i < k; i++)
        maxHeapify(arr, i, k, x);
    for (int i = (k - 1); i >= 0; i--)
        printf("%d ", arr[i]);
}
