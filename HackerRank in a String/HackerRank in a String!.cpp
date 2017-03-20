#include <iostream>
using namespace std;

string p = "hackerrank";

int main() {
    int q;
    cin >> q;
    for(string s; cin >> s; ) {
        auto i = 0;
        for(auto& j : s) {
            if(j == p[i]) {
                i++;
            }
        }
        if(i == p.size()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
