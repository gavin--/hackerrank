#include <iostream>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    for(auto i = 0; i != n; i++) {
        for(auto j = 0; j != i; j++) {
            if((a[i] + a[j]) % k == 0) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}
