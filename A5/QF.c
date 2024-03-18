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

Node* removeDuplicates(Node *head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* nextNode = temp->next;
        while (nextNode != NULL && temp->data == nextNode->data) {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if (nextNode != NULL) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* head = convertArr2DLL(arr, n);
    head = removeDuplicates(head);
    print(head);
    free(arr);
    // Free the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}


