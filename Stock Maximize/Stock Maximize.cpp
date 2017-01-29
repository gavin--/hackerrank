#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int WOT[N];
        for(auto i = 0; i != N; i++) {
            cin >> WOT[i];
        }
        int dp = WOT[N - 1];
        auto profit = 0ll;
        for(auto i = N - 2; i >= 0; i--) {
            dp = max(dp, WOT[i]);
            profit += dp - WOT[i];
        }
        cout << profit << endl;
    }
    return 0;
}
