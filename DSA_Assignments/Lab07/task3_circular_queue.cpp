#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return (rear + 1) % MAX == front; }

void enqueue(int value) {
    if (isFull()) { cout << "Circular Queue is Full!" << endl; return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) { cout << "Circular Queue is Empty!" << endl; return; }
    cout << queue[front] << " dequeued." << endl;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (isEmpty()) { cout << "Queue is empty." << endl; return; }
    cout << "Circular Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
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
