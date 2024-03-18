#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

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

Node* sortTwoLists(Node* first, Node* second) {
    Node* t1 = first;
    Node* t2 = second;
    Node* dummyNode = createNode(-1);
    Node* temp = dummyNode;
    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1) temp->next = t1;
    if (t2) temp->next = t2;
    return dummyNode->next;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    Node* head1 = convertArr2DLL(arr1, n1);
    Node* head2 = convertArr2DLL(arr2, n2);
    Node* head = sortTwoLists(head1, head2);
    print(head);
    return 0;
}

