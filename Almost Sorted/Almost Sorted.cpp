#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], sorted[n], left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + n);
    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted[i]) {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != sorted[i]) {
            right = i;
            break;
        }
    }
    if (left == -1 && right == -1) {
        cout << "yes";
    } else {
        swap(arr[left], arr[right]);
        if (is_sorted(arr, arr + n)) {
            cout << "yes\n";
            cout << "swap " << left + 1 << ' ' << right + 1;
        } else {
            swap(arr[left], arr[right]);
            reverse(arr + left, arr + right + 1);
            if (is_sorted(arr, arr + n)) {
                cout << "yes\n";
                cout << "reverse " << left + 1 << ' ' << right + 1;
            } else {
                cout << "no";
            }
        }
    }
    return 0;
}
