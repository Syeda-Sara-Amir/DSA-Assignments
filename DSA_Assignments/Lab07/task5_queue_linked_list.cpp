#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() { return front == nullptr; }

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty()) { front = rear = newNode; }
    else { rear->next = newNode; rear = newNode; }
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) { cout << "Queue is Empty!" << endl; return; }
    Node* temp = front;
    cout << front->data << " dequeued." << endl;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void display() {
    if (isEmpty()) { cout << "Queue is empty." << endl; return; }
    Node* temp = front;
    cout << "Queue (front to rear): ";
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== LINKED LIST QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; enqueue(value); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
