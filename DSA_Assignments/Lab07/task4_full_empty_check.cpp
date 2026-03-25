#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return (rear + 1) % MAX == front; }

void checkStatus() {
    if (isEmpty()) cout << "Queue Status: EMPTY" << endl;
    else if (isFull()) cout << "Queue Status: FULL" << endl;
    else cout << "Queue Status: Has elements (neither full nor empty)" << endl;
}

void enqueue(int value) {
    if (isFull()) { cout << "Queue is Full!" << endl; return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) { cout << "Queue is Empty!" << endl; return; }
    cout << queue[front] << " dequeued." << endl;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE STATUS CHECK MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check Full/Empty Status" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; enqueue(value); break;
            case 2: dequeue(); break;
            case 3: checkStatus(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
