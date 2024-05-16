#include <stdio.h>
void findDaysToNextJar(int arr[], int n) {
int next, i, j;
int days[n];
for (i = 0; i < n; i++) {
    next = -1;
    days[i] = 0;
    
    for (j = i + 1; j < n; j++) {
        if (arr[i] < arr[j]) {
            next = arr[j];
            days[i] = j - i;
            break;
        }
    }
}
for (i = 0; i < n; i++) 
    printf("%d ", days[i]);
}
void findDaysToNextSmaller(int arr[], int n) {
int next, i, j;
int days[n];
for (i = 0; i < n; i++) {
    next = -1;
    days[i] = 0;
    
    for (j = i + 1; j < n; j++) {
        if (arr[i] > arr[j]) {
            next = arr[j];
            days[i] = j - i;
            break;
        }
    }
}
for (i = 0; i < n; i++) 
    printf("%d ", days[i]);
}
int main() {
int n;
scanf("%d", &n);
int arr[n];
for (int i = 0; i < n; i++) 
    scanf("%d", &arr[i]);
findDaysToNextJar(arr, n);
printf("\n");
findDaysToNextSmaller(arr,n);
return 0;
}
