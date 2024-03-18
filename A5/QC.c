#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* convertArr2LL(int arr[], int n) {
    Node* head = createNode(arr[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++) {
        Node* temp = createNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* reverseLinkedList(Node *head)
{
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    Node* head = convertArr2LL(arr, n);
    head = reverseLinkedList(head);
    print(head);
    return 0;
}
