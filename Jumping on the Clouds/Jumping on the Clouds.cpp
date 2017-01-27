#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    vector<bool> c(n);
    for(auto i = 0; i != n; i++) {
        int j;
        cin >> j;
        if(j == 1) {
            c[i] = 1;
        }
    }
    for(auto i = 0; i < n - 1; ) {
        if(i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i++;
        }
        result++;
    }
    cout << result;
    return 0;
}
