#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;
    int S[k] = {}, count[k] = {};
    pair<int, int> a[n];
    for(auto i = 0; cin >> a[i].second; i++) {
        a[i].second = a[i].second % k;
        count[a[i].second]++;
    }
    for(auto& i : a) {
        i.first = count[i.second];
    }
    sort(a, a + n, greater<pair<int, int>>());
    for(auto& i : a) {
        if(S[(k - i.second) % k] == 0) {
            result++;
            S[i.second]++;
        }
    }
    cout << result;
    return 0;
}
