#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* convertArr2DLL(int arr[], int size) {
    Node* head = createNode(arr[0]);
    Node* prev = head;
    for (int i = 1; i < size; i++) {
        Node* temp = createNode(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
Node* findKthNode(Node* temp, int k) {
    while (k > 1 && temp != NULL) {
        temp = temp->next;
        k--;
    }
    return temp;
}
Node* rotateLeft(Node* head, int k) {
    if (head == NULL || k == 0) return head;
    int len = 1;
    Node* temp = head;
    while (temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    k = k % len;
    if (k == 0) return head;
    Node* newTail = findKthNode(head, k);
    Node* newHead = newTail->next;
    temp->next = head;
    head->prev = temp;
    newTail->next = NULL;
    newHead->prev = NULL;
    return newHead;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    Node* head = convertArr2DLL(arr, n);
    head = rotateLeft(head, k);
    print(head);
    return 0;
}


