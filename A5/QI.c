#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node {
    char data;
    struct Node *next;
} Node;
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* convertArr2LL(char str[], int n) {
    Node* head = createNode(str[0]);
    Node* mover = head;
    for(int i = 1; i < n; i++) {
        Node* temp = createNode(str[i]);
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
bool isPalindrome(Node *head) {
    if(head == NULL || head->next == NULL)
        return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head; 
    Node* second = newHead;
    while(second) {
        if(first->data != second->data) {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    char str[n];
    for(int i = 0; i < n; i++)
        scanf(" %c", &str[i]);
    Node* head = convertArr2LL(str, n);
    if(isPalindrome(head))
        printf("YES ");
    else
        printf("NO ");
    return 0;
}


