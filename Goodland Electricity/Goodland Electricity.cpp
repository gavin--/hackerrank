#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k, j = 0, result = 0;
    cin >> n >> k;
    vector<bool> c(n);
    for(auto i = 0; i != n; i++) {
        bool j;
        cin >> j;
        c[i] = j;
    }
    for(auto i = 0, last = -1; i != n; i++) {
        if(i - j >= k) {
            if(last == -1 || last - j >= k) {
                cout << -1;
                return 0;
            }
            j = last + k;
            result++;
        }
        if(c[i]) {
            last = i;
        }
    }
    if(j < n) {
        result++;
    }
    cout << result;
    return 0;
}
