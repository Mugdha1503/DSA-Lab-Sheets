#include <stdio.h>
void swap(int * a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int arr[], int N, int i)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] < arr[smallest])
		smallest = left;	
	if (right < N && arr[right] < arr[smallest])
		smallest = right;
	if (smallest != i) {
		swap(&arr[i], &arr[smallest]);		
		minHeapify(arr, N, smallest);
	}
}
void buildMinHeap(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) 
        minHeapify(arr, N, i);
}
int sumOfSmallestK(int arr[], int N, int k) {
    int sum = 0;
    buildMinHeap(arr, N);
    // Extract k smallest elements and calculate sum
    for (int i = 0; i < k; i++) {
        sum += arr[0]; // Add the root to sum
        arr[0] = arr[N - i - 1]; // Replace root with the last element
        minHeapify(arr, N - i - 1, 0); // Heapify to maintain min heap property
    }
    return sum;
}
int main(){
     int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);  
    printf("%d", sumOfSmallestK(arr, n, k));
}
