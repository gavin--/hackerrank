#include <iostream>
using namespace std;

int main() {
    string s;
    long long n, a = 0, b = 0;
    cin >> s >> n;
    for(auto i = 0; i != s.size(); i++) {
        if(s[i] == 'a') {
            a++;
            if(i < n % s.size()) {
                b++;
            }
        }
    }
    cout << n / s.size() * a + b;
    return 0;
}
