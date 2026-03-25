#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

void sortList(Node* head) {
    if (!head) return;
    for (Node* i = head; i != nullptr; i = i->next)
        for (Node* j = i->next; j != nullptr; j = j->next)
            if (i->data > j->data) swap(i->data, j->data);
    cout << "List sorted." << endl;
}

void display(Node* head) {
    cout << "List: ";
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
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
    display(head);
    sortList(head);
    display(head);
    return 0;
}
