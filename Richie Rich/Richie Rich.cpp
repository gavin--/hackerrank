#include <iostream>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for(auto i = 0; i < s.size() / 2; i++) {
        if(s[i] != s.rbegin()[i]) {
            k--;
        }
    }
    if(k < 0) {
        s = "-1";
    } else {
        for(auto i = 0; i < s.size() / 2; i++) {
            if(s[i] != s.rbegin()[i]) {
                if(k > 0 && max(s[i], s.rbegin()[i]) != '9') {
                    s.rbegin()[i] = s[i] = '9';
                    k--;
                } else {
                    if(s[i] > s.rbegin()[i]) {
                        s.rbegin()[i] = s[i];
                    } else {
                        s[i] = s.rbegin()[i];
                    }
                }
            } else if(s[i] != '9' && k >= 2) {
                s.rbegin()[i] = s[i] = '9';
                k -= 2;
            }
        }
        if(k > 0 && s.size() % 2 == 1) {
            s[s.size() / 2] = '9';
        }
    }
    cout << s;
    return 0;
}
