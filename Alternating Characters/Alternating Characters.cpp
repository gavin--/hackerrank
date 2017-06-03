#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        auto result = 0;
        for(auto i = 1; i != s.size(); i++) {
            if(s[i] == s[i - 1]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
