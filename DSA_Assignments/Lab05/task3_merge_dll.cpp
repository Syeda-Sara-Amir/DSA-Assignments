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

Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    Node* tail = head1;
    while (tail->next) tail = tail->next;
    tail->next = head2;
    head2->prev = tail;
    return head1;
}

void display(Node* head) {
    cout << "DLL: ";
    while (head) { cout << head->data << " <-> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n, value;

    cout << "Enter nodes for DLL 1:" << endl;
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head1, value);
    }

    cout << "Enter nodes for DLL 2:" << endl;
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head2, value);
    }

    cout << "DLL 1: "; display(head1);
    cout << "DLL 2: "; display(head2);

    Node* merged = mergeDLL(head1, head2);
    cout << "Merged "; display(merged);
    return 0;
}
