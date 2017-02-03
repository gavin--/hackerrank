#include <iostream>
using namespace std;

int isqrt(int n) {
    auto begin = 1, end = n / 2 + 1;
    while(begin < end) {
        auto mid = (end + begin + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

bool even_square(int n) {
    if(n % 2 == 1) {
        return 0;
    }
    auto sq = isqrt(n);
    return sq * sq == n;
}

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        auto top = 0, bottom = 1, i = 2;
        for(; i * i < N; i++) {
            if(N % i == 0) {
                if(even_square(i)) {
                    top++;
                }
                if(even_square(N / i)) {
                    top++;
                }
                bottom += 2;
            }
        }
        if(i * i == N) {
            if(even_square(i)) {
                top++;
            }
            bottom++;
        }
        if(top == 0) {
            cout << 0;
        } else {
            auto g = gcd(top, bottom);
            cout << top / g << '/' << bottom / g;
        }
        cout << endl;
    }
    return 0;
}
