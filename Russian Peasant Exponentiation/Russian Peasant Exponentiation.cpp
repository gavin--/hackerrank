#include <iostream>
using namespace std;

pair<long long, long long> mul(pair<long long, long long>& a, pair<long long, long long>& b, long long m) {
    pair<long long, long long> result = {((a.first * b.first - a.second * b.second) % m + m) % m, (a.first * b.second + b.first * a.second) % m};
    return result;
}

pair<long long, long long> pow(pair<long long, long long>& n, long long k, long long m) {
    pair<long long, long long> result = {1, 0};
    while(k != 0) {
        if(k % 2 == 1) {
            result = mul(result, n, m);
        }
        n = mul(n, n, m);
        k /= 2;
    }
    return result;
}

int main() {
    int q;
    for(cin >> q; q > 0; q--) {
        pair<long long, long long> n;
        long long k, m;
        cin >> n.first >> n.second >> k >> m;
        auto result = pow(n, k, m);
        cout << result.first << ' ' << result.second << endl;
    }
    return 0;
}
