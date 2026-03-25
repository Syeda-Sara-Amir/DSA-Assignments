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

// Modified insertAtPosition that handles last position without insertAtEnd()
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 1) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    int currentLen = 0;
    Node* last = nullptr;
    while (temp) { currentLen++; last = temp; temp = temp->next; }

    // If inserting at last or beyond last position
    if (pos > currentLen) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = last;
        if (last) last->next = newNode;
        else head = newNode;
        return;
    }

    // Insert at a middle position
    temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void display(Node* head) {
    cout << "DLL: ";
    while (head) { cout << head->data << " <-> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    display(head);

    int value, pos;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;
    insertAtPosition(head, value, pos);
    display(head);
    return 0;
}
