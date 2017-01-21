#include <iostream>
using namespace std;

bool solve(string& N) {
    if(N.size() == 2) {
        for(auto i = 0; i < N.size(); i++) {
            for(auto j = 0; j < N.size(); j++) {
                if(i != j && (N[j] - '0' + 10 * (N[i] - '0')) % 8 == 0) {
                    return true;
                }
            }
        }
    }
    if(N.size() == 1) {
        if((N[0] - '0') % 8 == 0) {
            return true;
        }
    }
    for(auto i = 0; i < N.size(); i++) {
        for(auto j = 0; j < N.size(); j++) {
            for(auto k = 0; k < N.size(); k++) {
                if(i != j && j != k && i != k && (N[k] - '0' + 10 * (N[j] - '0') + 100 * (N[i] - '0')) % 8 == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string N;
        cin >> N;
        if(solve(N)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
