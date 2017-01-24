#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    auto result = 0;
    for(auto i = 1; i < s.size() - 1; i++) {
        if(s[i - 1] == '0' && s[i] == '1' && s[i + 1] == '0') {
            result++;
            s[i + 1] = '1';
        }
    }
    cout << result;
    return 0;
}
