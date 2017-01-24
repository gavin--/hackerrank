#include <iostream>
using namespace std;

bool palindrome(string S) {
    for(auto i = 0; i < S.size() / 2; i++) {
        if(S[i] != S[S.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string S;
        cin >> S;
        for(auto i = 0; i < S.size() / 2; i++) {
            if(S[i] != S[S.size() - i - 1]) {
                if(palindrome(S.substr(0, i) + S.substr(i + 1, S.size()))) {
                    cout << i << endl;
                    goto next;
                } else {
                    cout << S.size() - i - 1 << endl;
                }
                goto next;
            }
        }
        cout << -1 << endl;
        next:
        ;
    }
    return 0;
}
