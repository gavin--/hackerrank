#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    for(auto i = 0; i < s.size(); i++) {
        if(t.size() == 0 || s[i] != t.back()) {
            t.push_back(s[i]);
        } else {
            t.pop_back();
        }
    }
    if(t.size() == 0) {
        cout << "Empty String";
    } else {
        cout << t;
    }
    return 0;
}
