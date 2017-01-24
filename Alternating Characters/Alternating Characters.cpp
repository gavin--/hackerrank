#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string s;
        cin >> s;
        auto result = 0;
        for(auto i = 1; i != s.size(); i++) {
            if(s[i] == s[i - 1]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
