#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int A[N];
    pair<int, int> B[N];
    for(auto i = 0; cin >> A[i]; i++) {
        B[i] = {A[i], i};
    }
    sort(B, B + N, greater<pair<int, int>>());
    for(auto i = 0; i < N && K > 0; i++) {
        auto it = lower_bound(B, B + N, pair<int, int>(A[i], i), greater<pair<int, int>>());
        it->second = B[i].second;
        if(A[i] != B[i].first) {
            swap(A[i], A[B[i].second]);
            K--;
        }
    }
    for(auto& i : A) {
        cout << i << ' ';
    }
    return 0;
}
