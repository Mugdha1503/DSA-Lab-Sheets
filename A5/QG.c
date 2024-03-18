#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
int findMeetingBlock(int n, int a, int b) {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= n; ++i) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head; // Making the list circular
    Node* dwight = head;
    Node* jim = head;
    while (a > 1) {
        dwight = dwight->next;
        --a;
    }
    while (b > 1) {
        jim = jim->next;
        --b;
    }
    while (dwight != jim) {
        dwight = dwight->next->next;
        jim = jim->next;
    }
    return dwight->data;
}
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int meetingBlock = findMeetingBlock(n, a, b);
    cout << meetingBlock << endl;
    return 0;
}

