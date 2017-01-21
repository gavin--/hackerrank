#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K, luck = 0;
    cin >> N >> K;
    vector<int> L;
    for(int l, t; cin >> l >> t; ) {
        if(t == 1) {
            L.emplace_back(l);
        } else {
            luck += l;
        }
    }
    sort(begin(L), end(L), greater<int>());
    for(auto i = 0; i < K && i < L.size(); i++) {
        luck += L[i];
    }
    for(auto i = K; i < L.size(); i++) {
        luck -= L[i];
    }
    cout << luck;
    return 0;
}
