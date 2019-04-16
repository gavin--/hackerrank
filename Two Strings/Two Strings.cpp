#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int p;
    cin >> p;
    for(string a, b; cin >> a >> b; ) {
        char chars[a.size()];
        for(int i = 0; i < a.size(); i++) {
            chars[i] = a[i];
        }
        sort(chars, chars + a.size());
        string result = "NO\n";
        for(char i : b) {
            auto it = lower_bound(chars, chars + a.size(), i);
            if(it != chars + a.size() && *it == i) {
                result = "YES\n";
                break;
            }
        }
        cout << result;
    }
    return 0;
}
