#include <iostream>
using namespace std;

long long sqrt(long long n) {
    auto begin = 1ll, end = n / 2 + 1;
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

bool sq(long long n) {
    auto t = sqrt(n);
    if(t * t == n) {
        return true;
    }
    return false;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long D, P, result = 0;
        cin >> D >> P;
        if(D == 0) {
            if(P == 0) {
                result = 1;
            } else {
                if(sq(P)) {
                    result = 2;
                }
            }
        } else if(D > 0) {
            auto discriminant = D * D + 4 * P, t = sqrt(discriminant);
            if(discriminant == 0) {
                result = 2;
            } else if(t * t == discriminant) {
                if((-D + t) % 2 == 0) {
                    result += 2;
                }
                if((-D - t) % 2 == 0) {
                    result += 2;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
