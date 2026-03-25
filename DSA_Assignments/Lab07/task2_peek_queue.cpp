#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { return front == -1; }

void enqueue(int value) {
    if (rear == MAX - 1) { cout << "Queue is Full!" << endl; return; }
    if (isEmpty()) front = 0;
    queue[++rear] = value;
    cout << value << " enqueued." << endl;
}

void peek() {
    if (isEmpty()) { cout << "Queue is empty." << endl; return; }
    cout << "Front element (peek): " << queue[front] << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; enqueue(value); break;
            case 2: peek(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
