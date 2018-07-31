#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; cin >> a[i]; i++) {
    }
    for(int i = 1; i < n; i++) {
        int j = i, k = a[i];
        while(j >= 1 && a[j - 1] > k) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = k;
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
