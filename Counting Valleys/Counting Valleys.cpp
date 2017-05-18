#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    string s;
    cin >> n >> s;
    for(auto i = 0, sum = 0; i < s.size(); i++) {
        if(s[i] == 'U') {
            sum++;
        } else {
            sum--;
        }
        if(sum == 0 && s[i] == 'U') {
            result++;
        }
    }
    cout << result;
    return 0;
}
