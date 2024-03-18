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
    Node* back = head;
    for (int i = 1; i < size; i++) {
        Node* temp = createNode(arr[i]);
        temp->prev = back;
        back->next = temp;
        back = temp;
    }
    return head;
}
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
Node* add2numbers(Node *head1, Node *head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummynode = createNode(-1);
    Node* curr = dummynode;
    int carry = 0;
    while (t1 != NULL || t2 != NULL) {
        int sum = carry;
        if (t1) sum += t1->data;
        if (t2) sum += t2->data;
        Node* newNode = createNode(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if (t1) t1 = t1->next;
        if (t2) t2 = t2->next;
    }
    if (carry) {
        Node* newNode1 = createNode(carry);
        curr->next = newNode1;
    }
    return dummynode->next;
}

int main() {
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int arr1[1000],arr2[1000];
    for(int i=0;i<n1;i++)
    scanf("%d",&arr1[i]);
    for(int i=0;i<n2;i++)
    scanf("%d",&arr2[i]);
    Node* head1 = convertArr2DLL(arr1, n1);
    Node* head2 = convertArr2DLL(arr2, n2);
    Node* head3 = add2numbers(head1, head2);
    print(head3);
    return 0;
}



