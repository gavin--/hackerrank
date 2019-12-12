#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; cin >> arr[i]; i++) {
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            result++;
        }
    }
    cout << result;
    return 0;
}
