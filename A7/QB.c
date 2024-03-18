#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Node structure for linked list
struct Node {
    float data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node** head, float value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void removeTrailingZeros(char* str) {
    int end = strlen(str) - 1;
    while (end >= 0 && str[end] == '0') 
        end--;
    if (end >= 0 && str[end] == '.') 
        end--;
    str[end + 1] = '\0';
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        char floatStr[32];
        snprintf(floatStr, sizeof(floatStr), "%.6f", temp->data);
        removeTrailingZeros(floatStr);
        printf("%s ", floatStr);
        temp = temp->next;
    }
}
// Bucket sort function
void bucketSort(float arr[], int n) {
    // Create an array of linked list buckets
    struct Node* buckets[n];
    int bucket_sizes[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
        bucket_sizes[i] = 0;
    }
    // Insert elements into respective buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        insertAtEnd(&buckets[index], arr[i]);
        bucket_sizes[index]++;
    }
    for (int i = 0; i < n; i++) {
        if (buckets[i] != NULL) {
            // Perform insertion sort on the bucket
            struct Node* current = buckets[i];
            struct Node* sorted = NULL;
            while (current != NULL) {
                struct Node* next = current->next;
                if (sorted == NULL || sorted->data >= current->data) {
                    current->next = sorted;
                    sorted = current;
                } else {
                    struct Node* temp = sorted;
                    while (temp->next != NULL && temp->next->data < current->data) {
                        temp = temp->next;
                    }
                    current->next = temp->next;
                    temp->next = current;
                }
                current = next;
            }
            // Replace the original bucket with the sorted one
            buckets[i] = sorted;
        }
    }
    // Print sorted array and number of elements in each bucket
    for (int i = 0; i < n; i++) {
        if (buckets[i] != NULL) 
            printList(buckets[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++)
            printf("%d ", bucket_sizes[i]);
    // Free memory allocated to buckets
    for (int i = 0; i < n; i++) 
        freeList(buckets[i]);
}
int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%f", &arr[i]);
    bucketSort(arr, n);
    return 0;
}


