#include <stdio.h>
// Function to compute the total number of contiguous subarrays
int countContiguousSubarrays(int arr[], int n, int k) {
 // Initialize count of contiguous subarrays
 int count = 0;
 // Iterate through all elements of array
 for (int i = 0; i < n; i++) {
 // Start with current element
 for (int j = i; j < n; j++) {
 // Check if absolute difference of any two elements in the subarray is less than or equal to k
 int maxEl = arr[i], minEl = arr[i];
 for (int x = i; x <= j; x++) {
 maxEl = (arr[x] > maxEl) ? arr[x] : maxEl;
 minEl = (arr[x] < minEl) ? arr[x] : minEl;
 }
 if (maxEl - minEl <= k)
 count++;
 else
 break; // If absolute difference exceeds k, no need to check further for this subarray
 }
 }
 return count;
}
int main() {
 int n,k;
 scanf("%d %d", &n,&k);
 int arr[n];
 for (int i = 0; i < n; i++) 
 scanf("%d", &arr[i]);
 int totalCount = countContiguousSubarrays(arr, n, k);
 printf("%d\n", totalCount);
 return 0;
}

