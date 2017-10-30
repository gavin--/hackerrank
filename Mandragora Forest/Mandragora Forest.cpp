#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; T--) {
        int H[N];
        long long sum = 0;
        for(auto i = 0; i != N; i++) {
            cin >> H[i];
            sum += H[i];
        }
        sort(H, H + N);
        long long S = 1, P = sum;
        for(auto i = 0; i != N; i++) {
            S++;
            sum -= H[i];
            P = max(P, sum * S);
        }
        cout << P << endl;
    }
    return 0;
}
