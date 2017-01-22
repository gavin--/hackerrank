#include <climits>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int A[N], largest = INT_MIN;
        for(auto i = 0; i < N; i++) {
            cin >> A[i];
            if(A[i] > largest) {
                largest = A[i];
            }
        }
        auto contiguous = A[0], current = A[0], sum = 0;
        if(A[0] > 0) {
            sum = A[0];
        }
        for(auto i = 1; i < N; i++) {
            if(current < 0) {
                current = A[i];
            } else {
                current += A[i];
            }
            if(A[i] > 0) {
                sum += A[i];
            }
            if(current > contiguous) {
                contiguous = current;
            }
        }
        if(sum == 0) {
            sum = largest;
        }
        cout << contiguous << ' ' << sum << endl;
    }
    return 0;
}
