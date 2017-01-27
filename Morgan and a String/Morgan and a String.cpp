#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string A, B, result;
        cin >> A >> B;
        result.reserve(A.size() + B.size() + 1);
        for(auto i = 0, j = 0; i < A.size() || j < B.size(); ) {
            auto k = i, l = j;
            while(k < A.size() && l < B.size() && A[k] == B[l]) {
                k++;
                l++;
            }
            if(k == A.size()) {
                for(l = j; j < B.size() && B[j] == B[l]; j++) {
                    result.push_back(B[j]);
                }
            } else if(l == B.size()) {
                for(k = i; i < A.size() && A[i] == A[k]; i++) {
                    result.push_back(A[i]);
                }
            } else if(A[k] < B[l]) {
                for(k = i; i < A.size() && A[i] == A[k]; i++) {
                    result.push_back(A[i]);
                }
            } else {
                for(l = j; j < B.size() && B[j] == B[l]; j++) {
                    result.push_back(B[j]);
                }
            }
        }
        result.push_back('\n');
        cout << result;
    }
    return 0;
}
