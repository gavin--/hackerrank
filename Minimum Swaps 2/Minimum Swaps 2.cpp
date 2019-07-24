#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int current = 0;
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            current++;
        }
        result += current;
    }
    cout << result;
    return 0;
}
