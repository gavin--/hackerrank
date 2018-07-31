#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n], k;
    for(int i = 0, j; i < n / 2; i++) {
        cin >> j >> k;
        s[j].push_back('-');
        s[j].push_back(' ');
    }
    for(int i = 0, j; i < n / 2; i++) {
        cin >> j >> k;
        s[j].insert(s[j].end(), k.begin(), k.end());
        s[j].push_back(' ');
    }
    for(int i = 0; i < n; i++) {
        cout << s[i];
    }
    return 0;
}
