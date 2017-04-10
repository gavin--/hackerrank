#include <iostream>
using namespace std;

bool palindrome(string S) {
    for(auto i = 0; i < S.size() / 2; i++) {
        if(S[i] != S.rbegin()[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for(string S; cin >> S; ) {
        auto result = -1;
        for(auto i = 0; i < S.size() / 2; i++) {
            if(S[i] != S.rbegin()[i]) {
                if(palindrome(S.substr(0, i) + S.substr(i + 1, S.size()))) {
                    result = i;
                } else {
                    result = S.size() - i - 1;
                }
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}
