#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int current = 0;
        while (arr[i].second != i) {
            swap(arr[i], arr[arr[i].second]);
            current++;
        }
        result += current - 1;
    }
    cout << result;
    return 0;
}
