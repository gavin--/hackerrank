#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string s;
        cin >> s;
        int count[3] = {};
        for(auto& i : s) {
            count[i - 'a']++;
        }
        if(count[0] == s.size() || count[1] == s.size() || count[2] == s.size()) {
            cout << s.size() << endl;
            continue;
        }
        if(count[0] % 2 == count[1] % 2 && count[1] % 2 == count[2] % 2) {
            cout << 2;
        } else {
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}
