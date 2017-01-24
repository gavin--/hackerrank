#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string s;
        cin >> s;
        auto result = 0;
        for(auto i = 0; i < s.size() / 2; i++) {
            result += abs(s[i] - s[s.size() - 1 - i]);
        }
        cout << result << endl;
    }
    return 0;
}
