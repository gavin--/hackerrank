#include <iostream>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for(auto i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) {
            k--;
        }
    }
    if(k < 0) {
        cout << -1;
        return 0;
    }
    for(auto i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) {
            if(k > 0 && max(s[i], s[s.size() - i - 1]) != '9') {
                s[i] = '9';
                s[s.size() - i - 1] = '9';
                k--;
            } else {
                if(s[i] > s[s.size() - i - 1]) {
                    s[s.size() - i - 1] = s[i];
                } else {
                    s[i] = s[s.size() - i - 1];
                }
            }
        } else if(s[i] != '9' && k >= 2) {
            s[i] = '9';
            s[s.size() - i - 1] = '9';
            k -= 2;
        }
    }
    if(k > 0 && s.size() % 2 == 1) {
        s[s.size() / 2] = '9';
    }
    cout << s;
    return 0;
}
