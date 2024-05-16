#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};
struct Deque {
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}
void pushRear(struct Deque* dq, int value) {
    struct Node* newNode = createNode(value);
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}
void popFront(struct Deque* dq) {
    if (dq->front == NULL)
        return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;
    free(temp);
}
void popRear(struct Deque* dq) {
    if (dq->rear == NULL)
        return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;
    free(temp);
}
// Function to find the sliding window maximum
int* slidingWindowMaximum(int* A, int n, int K, int* returnSize) {
    if (n <= 0 || K <= 0)
        return NULL;
    int* ans = (int*)malloc((n - K + 1) * sizeof(int));
    struct Deque* dq = createDeque();
    int index = 0;
    for (int i = 0; i < n; i++) {
        // Remove elements outside the window
        while (dq->front != NULL && dq->front->value <= i - K) {
            popFront(dq);
        }
        // Remove smaller elements from the rear
        while (dq->rear != NULL && A[dq->rear->value] <= A[i]) {
            popRear(dq);
        }
        // Add current element's index to deque
        pushRear(dq, i);
        // Store the maximum element of current window
        if (i >= K - 1) 
            ans[index++] = A[dq->front->value];
    }
    *returnSize = index;
    return ans;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
}
int main() {
    int n, K;
    scanf("%d%d",&n,&K);
    int A[n];
    for(int i = 0; i<n; i++)
        scanf("%d",&A[i]);
    int returnSize;
    int* result = slidingWindowMaximum(A, n, K, &returnSize);
    printArray(result, returnSize);
    return 0;
}



