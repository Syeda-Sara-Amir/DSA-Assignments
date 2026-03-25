#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() { return top == -1; }

void push(int value) {
    if (top == MAX - 1) { cout << "Stack Overflow!" << endl; return; }
    stack[++top] = value;
    cout << value << " pushed." << endl;
}

void pop() {
    if (isEmpty()) { cout << "Stack Underflow!" << endl; return; }
    cout << stack[top--] << " popped." << endl;
}

void peek() {
    if (isEmpty()) { cout << "Stack is empty." << endl; return; }
    cout << "Top element (peek): " << stack[top] << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
