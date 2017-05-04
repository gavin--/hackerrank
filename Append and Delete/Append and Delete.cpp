#include <iostream>
using namespace std;

int main() {
    string s, t, result = "No";
    int k;
    cin >> s >> t >> k;
    if(s == t && (k % 2 == 0 || k > 2 * s.size())) {
        result = "Yes";
    } else {
        for(auto i = 0; i <= min(s.size(), t.size()); i++) {
            if(s[i] != t[i]) {
                int size = k - s.size() + i - t.size() + i;
                if(size > 0 && (size % 2 == 0 || size > 2 * i)) {
                    result = "Yes";
                }
            }
        }
    }
    cout << result;
    return 0;
}
