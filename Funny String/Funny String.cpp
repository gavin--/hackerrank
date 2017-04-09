#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        auto funny = true;
        for(auto i = 1; i < s.size(); i++) {
            if(abs(s[i] - s[i - 1]) != abs(s.rbegin()[i] - s.rbegin()[i - 1])) {
                funny = false;
                break;
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
