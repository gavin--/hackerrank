#include <iostream>
using namespace std;

int main() {
    int n, d, result = 0;
    cin >> n >> d;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    for(auto i = 0, j = i + 1, k = j + 1; i < n; i++) {
        while(j < n && a[j] - a[i] < d) {
            j++;
        }
        k = j + 1;
        if(a[j] - a[i] == d) {
            while(k < n && a[k] - a[j] < d) {
                k++;
            }
            if(a[k] - a[j] == d) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}
