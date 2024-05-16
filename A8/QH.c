#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 1000000

// Structure to represent a node in the heap
typedef struct HeapNode {
    int data;
    int priority; // Time of insertion
} HeapNode;

// Structure to represent the heap
typedef struct Heap {
    HeapNode *array;
    int capacity;
    int size;
} Heap;

// Function to create a new node
HeapNode* createNode(int data, int priority) {
    HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

// Function to create a min heap
Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    return heap;
}

// Function to swap two nodes in the heap
void swapNodes(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property
void heapify(Heap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left].priority < heap->array[smallest].priority)
        smallest = left;
    if (right < heap->size && heap->array[right].priority < heap->array[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to insert a new node into the heap
void insertNode(Heap *heap, int data, int priority) {
    if (heap->size == heap->capacity) {
        printf("Overflow: Could not insert node\n");
        return;
    }

    HeapNode* newNode = createNode(data, priority);
    heap->array[heap->size] = *newNode;
    int i = heap->size;
    heap->size++;

    while (i != 0 && heap->array[(i-1)/2].priority > heap->array[i].priority) {
        swapNodes(&heap->array[(i-1)/2], &heap->array[i]);
        i = (i-1)/2;
    }
}

// Function to remove the root node (minimum element) from the heap
void removeRoot(Heap *heap) {
    if (heap->size == 0) {
        printf("Underflow: Could not remove root\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
}

// Function to get the root node (minimum element) from the heap
int getRoot(Heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->array[0].data;
}

// Function to calculate the average of elements in the heap
int getHeapAverage(Heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < heap->size; i++) {
        sum += heap->array[i].data;
    }
    return sum / heap->size;
}

// Function to handle the operations according to the given input format
void handleOperations(int q) {
    Heap *stack = createHeap(MAX_Q_SIZE);
    Heap *queue = createHeap(MAX_Q_SIZE);
    int i;
    for (i = 0; i < q; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            int x;
            scanf("%d", &x);
            insertNode(stack, x, i); // Priority is time of insertion
            insertNode(queue, x, i);
        } else if (operation == 2) {
            removeRoot(stack);
            removeRoot(queue);
        } else if (operation == 3) {
            printf("%d %d\n", getRoot(stack), getHeapAverage(queue));
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);
    handleOperations(q);
    return 0;
}

