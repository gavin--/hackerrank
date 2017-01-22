#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int H[N];
        auto sum = 0ll;
        for(auto i = 0; i != N; i++) {
            cin >> H[i];
            sum += H[i];
        }
        sort(H, H + N);
        auto S = 1ll, P = sum;
        for(auto i = 0; i != N; i++) {
            S++;
            sum -= H[i];
            P = max(P, sum * S);
        }
        cout << P << endl;
    }
    return 0;
}
