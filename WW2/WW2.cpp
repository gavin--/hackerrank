#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> result(a.size(), vector<long long>(b[0].size()));
    for(int i = 0; i < a.size(); i++) {
        for(int k = 0; k < a[i].size(); k++) {
            for(int j = 0; j < b[k].size(); j++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> pow(vector<vector<long long>> x, int n) {
    vector<vector<long long>> result(x.size(), vector<long long>(x.size()));
    for(int i = 0; i < x.size(); i++) {
        result[i][i] = 1;
    }
    while(n != 0) {
        if(n % 2 == 1) {
            result = mul(result, x);
        }
        x = mul(x, x);
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        vector<vector<long long>> odd(m, vector<long long>(m)), even(m, vector<long long>(m));
        for(int i = 1; i < m; i++) {
            odd[i][i - 1] = 1;
            odd[i - 1][i] = 1;
            even[i][i - 1] = 1;
            even[i - 1][i] = 1;
            even[i][i] = 1;
        }
        even[0][0] = 1;
        auto matrix = mul(pow(odd, (n - 1) / 2 + (n - 1) % 2), pow(even, (n - 1) / 2));
        long long result = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                result = (result + matrix[i][j]) % MOD;
            }
        }
        cout << result << endl;
    }
    return 0;
}
