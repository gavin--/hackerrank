#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int A[N];
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
        }
        cout << A[0] << ' ';
        for(auto i = 1; i < N; i++) {
            cout << lcm(A[i], A[i - 1]) << ' ';
        }
        cout << A[N - 1] << endl;
    }
    return 0;
}
