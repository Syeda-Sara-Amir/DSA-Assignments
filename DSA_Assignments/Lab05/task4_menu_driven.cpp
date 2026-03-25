#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

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

void deleteAtPosition(Node*& head, int pos) {
    if (!head) { cout << "List is empty." << endl; return; }
    Node* temp = head;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) { cout << "Position out of range." << endl; return; }
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    cout << "Node deleted." << endl;
}

void reverseDLL(Node*& head) {
    Node* temp = nullptr;
    Node* curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
}

void display(Node* head) {
    if (!head) { cout << "List is empty." << endl; return; }
    cout << "DLL: ";
    while (head) { cout << head->data << " <-> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value, pos;

    do {
        cout << "\n===== DLL MENU =====" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete at Position" << endl;
        cout << "4. Reverse DLL" << endl;
        cout << "5. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter position: "; cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 4:
                reverseDLL(head);
                cout << "DLL reversed." << endl;
                break;
            case 5:
                display(head);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
