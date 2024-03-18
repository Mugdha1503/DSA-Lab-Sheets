#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* buildCircularList(int n) {
    Node* head = createNode(1);
    Node* temp = head;
    for (int i = 2; i <= n; ++i) {
        temp->next = createNode(i);
        temp = temp->next;
    }
    temp->next = head; 
    return head;
}
int findLastPerson(int n, int k) {
    Node* head = buildCircularList(n);
    Node* current = head;
    Node* previous = NULL;
    while (current->next != current) {
        for (int i = 0; i < k - 1; ++i) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        current = previous->next;
    }
    int lastPerson = current->data;
    free(current);
    return lastPerson;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int lastPerson = findLastPerson(n, k);
    printf("%d\n", lastPerson);
    return 0;
}


