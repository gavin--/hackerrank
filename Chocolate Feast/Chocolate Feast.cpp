#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, c, m; cin >> n >> c >> m; ) {
        auto result = n = n / c;
        while(n >= m) {
            result += n / m;
            n = n % m + n / m;
        }
        cout << result << endl;
    }
    return 0;
}
