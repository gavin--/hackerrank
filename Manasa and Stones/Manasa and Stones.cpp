#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, a, b; cin >> n >> a >> b; cout << endl) {
        int result[n];
        for(auto i = 0; i < n; i++) {
            result[i] = i * a + (n - i - 1) * b;
        }
        sort(result, result + n);
        cout << result[0] << ' ';
        for(auto i = 1; i < n; i++) {
            if(result[i] != result[i - 1]) {
                cout << result[i] << ' ';
            }
        }
    }
    return 0;
}
