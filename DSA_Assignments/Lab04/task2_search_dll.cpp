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

void search(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) {
            cout << "Value " << key << " found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Value " << key << " not found." << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, key;
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head, value);
    }
    cout << "Enter value to search: ";
    cin >> key;
    search(head, key);
    return 0;
}
