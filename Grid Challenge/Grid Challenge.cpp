#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        string G[N];
        for(auto i = 0; i != N; i++) {
            cin >> G[i];
            sort(begin(G[i]), end(G[i]));
        }
        auto result = true;
        for(auto i = 0; i != N; i++) {
            for(auto j = 1; j != N; j++) {
                if(G[j][i] < G[j - 1][i]) {
                    result = false;
                }
            }
        }
        if(result) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
