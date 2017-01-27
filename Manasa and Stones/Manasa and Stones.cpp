#include <set>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int n, a, b;
        cin >> n >> a >> b;
        set<int> set;
        for(auto i = 0; i < n; i++) {
            set.emplace(i * a + (n - i - 1) * b);
        }
        for(auto& i : set) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
