#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string s;
        cin >> s;
        bool funny = true;
        for(auto i = 1; i < s.size(); i++) {
            auto j = s.size() - i;
            if(abs(s[i] - s[i - 1]) != abs(s[j - 1] - s[j])) {
                funny = false;
            }
        }
        if(funny) {
            cout << "Funny\n";
        } else {
            cout << "Not Funny\n";
        }
    }
    return 0;
}
