#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    long long A[N];
    for(auto i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto g = 0ll;
    for(auto i = 1; i < N; i++) {
        g = gcd(g, A[i] - A[i - 1]);
    }
    for(long long K; cin >> K; ) {
        cout << gcd(g, A[0] + K) << endl;
    }
    return 0;
}
