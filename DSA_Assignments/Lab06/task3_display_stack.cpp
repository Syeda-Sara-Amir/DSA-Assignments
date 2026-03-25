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

// Display without modifying the stack
void display() {
    if (isEmpty()) { cout << "Stack is empty." << endl; return; }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Display (non-destructive)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; push(value); break;
            case 2: display(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
