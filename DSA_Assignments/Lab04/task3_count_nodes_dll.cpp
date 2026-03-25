#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (!head) { newNode->prev = nullptr; head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int countNodes(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int main() {
    Node* head = nullptr;
    int n, value;
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head, value);
    }
    cout << "Total nodes in DLL: " << countNodes(head) << endl;
    return 0;
}
