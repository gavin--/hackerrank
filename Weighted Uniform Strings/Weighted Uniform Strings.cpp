#include <map>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    map<int, bool> map;
    map[s[0] - 'a' + 1] = 1;
    for(auto i = 1, j = s[0] - 'a' + 1; i != s.size(); i++) {
        if(s[i] == s[i - 1]) {
            j += s[i] - 'a' + 1;
        } else {
            j = s[i] - 'a' + 1;
        }
        map[s[i] - 'a' + 1] = 1;
        map[j] = 1;
    }
    for(int x; cin >> x; ) {
        if(map[x]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
