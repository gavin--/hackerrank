#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long inverse(long long n) {
    return pow(n, MOD - 2);
}

long long C(long long N, long long K) {
    auto top = 1ll, bottom = 1ll;
    for(auto i = 1ll; i <= K; i++) {
        top = top * (N + 1 - i) % MOD;
        bottom = bottom * i % MOD;
    }
    return top * inverse(bottom) % MOD;
}

int main() {
    int N, K;
    cin >> N >> K;
    pair<int, int> rectangle[2], stain[N];
    cin >> rectangle[0].first >> rectangle[0].second;
    rectangle[1] = rectangle[0];
    stain[0] = rectangle[0];
    for(auto i = 1; cin >> stain[i].first >> stain[i].second; i++) {
        auto x = stain[i].first, y = stain[i].second;
        if(x > rectangle[1].first) {
            rectangle[1].first = x;
        }
        if(y < rectangle[1].second) {
            rectangle[1].second = y;
        }
        if(x < rectangle[0].first) {
            rectangle[0].first = x;
        }
        if(y > rectangle[0].second) {
            rectangle[0].second = y;
        }
    }
    auto top = 0, bottom = 0, left = 0, right = 0, topleft = 0, topright = 0, bottomleft = 0, bottomright = 0;
    for(auto i = 0; i != N; i++) {
        auto x = stain[i].first, y = stain[i].second;
        if(x == rectangle[0].first) {
            left++;
            if(y == rectangle[0].second) {
                topleft++;
            }
            if(y == rectangle[1].second) {
                bottomleft++;
            }
        }
        if(x == rectangle[1].first) {
            right++;
            if(y == rectangle[0].second) {
                topright++;
            }
            if(y == rectangle[1].second) {
                bottomright++;
            }
        }
        if(y == rectangle[0].second) {
            top++;
        }
        if(y == rectangle[1].second) {
            bottom++;
        }
    }
    auto result = 0ll;
    if(top <= K) {
        result += C(N - top, K - top);
    }
    if(bottom <= K) {
        result += C(N - bottom, K - bottom);
    }
    if(left <= K) {
        result += C(N - left, K - left);
    }
    if(right <= K) {
        result += C(N - right, K - right);
    }
    if(top + bottom <= K) {
        result -= C(N - top - bottom, K - top - bottom);
    }
    if(top + left - topleft <= K) {
        result -= C(N - top - left + topleft, K - top - left + topleft);
    }
    if(top + right - topright <= K) {
        result -= C(N - top - right + topright, K - top - right + topright);
    }
    if(bottom + left - bottomleft <= K) {
        result -= C(N - bottom - left + bottomleft, K - bottom - left + bottomleft);
    }
    if(bottom + right - bottomright <= K) {
        result -= C(N - bottom - right + bottomright, K - bottom - right + bottomright);
    }
    if(left + right <= K) {
        result -= C(N - left - right, K - left - right);
    }
    if(top + bottom + left - topleft - bottomleft <= K) {
        result += C(N - top - bottom - left + topleft + bottomleft, K - top - bottom - left + topleft + bottomleft);
    }
    if(top + bottom + right - topright - bottomright <= K) {
        result += C(N - top - bottom - right + topright + bottomright, K - top - bottom - right + topright + bottomright);
    }
    if(top + left + right - topleft - topright <= K) {
        result += C(N - top - left - right + topleft + topright, K - top - left - right + topleft + topright);
    }
    if(bottom + left + right - bottomleft - bottomright <= K) {
        result += C(N - bottom - left - right + bottomleft + bottomright, K - bottom - left - right + bottomleft + bottomright);
    }
    if(top + bottom + left + right - topright - topleft - bottomleft - bottomright <= K) {
        result -= C(N - top - bottom - left - right + topright + topleft + bottomleft + bottomright, K - top - bottom - left - right + topright + topleft + bottomleft + bottomright);
    }
    cout << (result % MOD + MOD) % MOD;
    return 0;
}
