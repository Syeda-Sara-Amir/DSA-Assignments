#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (!root) return newNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node* temp = root->right; delete root; return temp; }
        if (!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, value, searchKey, deleteKey;

    cout << "How many elements to insert? ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal (sorted): ";
    inorder(root);
    cout << endl;

    cout << "\nEnter value to search: ";
    cin >> searchKey;
    if (search(root, searchKey))
        cout << searchKey << " found in BST." << endl;
    else
        cout << searchKey << " not found in BST." << endl;

    cout << "\nEnter value to delete: ";
    cin >> deleteKey;
    root = deleteNode(root, deleteKey);
    cout << "After deletion, Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
