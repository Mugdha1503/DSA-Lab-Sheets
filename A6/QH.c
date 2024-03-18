#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct {
    int value;
    int arrIndex;
    int nextIndex;
} HeapNode;
void swap(HeapNode* x, HeapNode* y) {
    HeapNode temp = *x;
    *x = *y;
    *y = temp;
}
void minHeapify(HeapNode arr[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && arr[left].value < arr[smallest].value)
        smallest = left;
    if (right < size && arr[right].value < arr[smallest].value)
        smallest = right;
    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}
void buildMinHeap(HeapNode arr[], int size) {
    int i = (size - 1) / 2;
    while (i >= 0) {
        minHeapify(arr, size, i);
        i--;
    }
}
void mergeKSortedArrays(int* arrays[], int sizes[], int k) {
    int totalElements = 0;
    for (int i = 0; i < k; ++i)
        totalElements += sizes[i];
    int outputIndex = 0;
    HeapNode minHeap[k];
    for (int i = 0; i < k; ++i) {
        minHeap[i].value = arrays[i][0];
        minHeap[i].arrIndex = i;
        minHeap[i].nextIndex = 1;
    }
    buildMinHeap(minHeap, k);
    while (outputIndex < totalElements) {
        HeapNode minNode = minHeap[0];
        printf("%d ", minNode.value);
        outputIndex++;
        if (minNode.nextIndex < sizes[minNode.arrIndex]) {
            minHeap[0].value = arrays[minNode.arrIndex][minNode.nextIndex];
            minHeap[0].nextIndex++;
        } else 
            minHeap[0].value = INT_MAX;
        minHeapify(minHeap, k, 0);
    }
}
int main() {
    int k; // Number of arrays
    scanf("%d", &k);
    int sizes[k]; // Sizes of the arrays
    int* arrays[k];
    for (int i = 0; i < k; ++i) {
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; ++j)
            scanf("%d", &arrays[i][j]);
    }
    mergeKSortedArrays(arrays, sizes, k);
    return 0;
}

