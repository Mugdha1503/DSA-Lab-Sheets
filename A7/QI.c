#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Node structure for the heap
struct Node
{
    char character;
    int frequency;
};

// Min-heap structure
struct MinHeap
{
    int size;
    struct Node *array[MAX_SIZE];
};

// Function to create a new node
struct Node *newNode(char character, int frequency)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    return node;
}

// Function to create a Min Heap
struct MinHeap *createMinHeap()
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to swap two nodes of the heap
void swapNode(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain heap property
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx)
    {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to build the min heap
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to extract the minimum node from the heap
struct Node *extractMin(struct MinHeap *minHeap)
{
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node into the heap
void insertNode(struct MinHeap *minHeap, struct Node *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to find the minimum sum of squares
int minSumOfSquares(char *array, int n, int k)
{
    // Count frequency of each character
    int count[26] = {0};
    for (int i = 0; i < n; ++i)
        count[array[i] - 'a']++;

    // Create a min heap and insert all characters with their frequencies
    struct MinHeap *minHeap = createMinHeap();
    for (int i = 0; i < 26; ++i)
    {
        if (count[i] > 0)
            insertNode(minHeap, newNode('a' + i, count[i]));
    }

    // Find the minimum sum of squares
    int result = 0;
    while (k > 0)
    {
        struct Node *node = extractMin(minHeap);
        int take = node->frequency < k ? node->frequency : k;
        result += take * take;
        k -= take;
    }

    return result;
}

// Main function
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char array[n]; // defining the character array of size n
    scanf("%s", array);
    int minSum = minSumOfSquares(array, n, k);
    printf("%d\n", minSum);
    return 0;
}