#include <iostream>
using namespace std;

int M(string& P, string& Q, int i, int j, int S) {
    auto result = 0, L = 0;
    for(auto k = 0; i + L < P.size() && j + L < Q.size(); ) {
        if(P[i + L] != Q[j + L]) {
            k++;
        }
        if(k > S) {
            result = max(result, L);
            while(P[i] == Q[j]) {
                i++;
                j++;
                L--;
            }
            i++;
            j++;
            k--;
        } else {
            L++;
        }
    }
    return max(result, L);
}

int main() {
    int T, S;
    cin >> T;
    for(string P, Q; cin >> S >> P >> Q; ) {
        auto result = M(P, Q, 0, 0, S);
        for(auto i = 1; i < P.size(); i++) {
            auto m = max(M(P, Q, 0, i, S), M(P, Q, i, 0, S));
            if(m > result) {
                result = m;
            }
        }
        cout << result << endl;
    }
    return 0;
}
