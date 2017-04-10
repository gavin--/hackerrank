#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        auto result = 0;
        for(auto i = 0; i < s.size() / 2; i++) {
            result += abs(s[i] - s.rbegin()[i]);
        }
        cout << result << endl;
    }
    return 0;
}
