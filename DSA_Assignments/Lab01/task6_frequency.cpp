#include <iostream>
using namespace std;

void frequency(int arr[], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    cout << "Element Frequencies:" << endl;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
                visited[j] = true;
            }
        }
        cout << arr[i] << " -> " << count << " time(s)" << endl;
    }
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

    frequency(arr, n);
    return 0;
}
