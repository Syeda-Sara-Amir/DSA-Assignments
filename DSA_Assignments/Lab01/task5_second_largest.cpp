#include <iostream>
using namespace std;

void secondLargest(int arr[], int n) {
    if (n < 2) {
        cout << "Array must have at least 2 elements." << endl;
        return;
    }
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MIN)
        cout << "No second largest element found (all elements may be equal)." << endl;
    else
        cout << "Second largest element: " << second << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    secondLargest(arr, n);
    return 0;
}
