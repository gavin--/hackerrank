#include <climits>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int A[N], largest = INT_MIN;
        for(auto i = 0; i < N; i++) {
            cin >> A[i];
            if(A[i] > largest) {
                largest = A[i];
            }
        }
        auto contiguous = A[0], current = -1, sum = 0;
        for(auto i = 0; i < N; i++) {
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
