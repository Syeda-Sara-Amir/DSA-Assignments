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

// Modified deleteAtPosition that handles last position without deleteAtEnd()
void deleteAtPosition(Node*& head, int pos) {
    if (!head) { cout << "List is empty." << endl; return; }

    Node* temp = head;
    // Find the node at position
    for (int i = 1; i < pos && temp != nullptr; i++) temp = temp->next;

    if (!temp) { cout << "Position out of range." << endl; return; }

    // This handles last node too since temp->next would be nullptr
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next; // deleting head

    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
    cout << "Node at position " << pos << " deleted." << endl;
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
    insertAtEnd(head, 40);
    display(head);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    deleteAtPosition(head, pos);
    display(head);
    return 0;
}
