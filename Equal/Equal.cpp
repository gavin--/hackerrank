#include <climits>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, m = INT_MAX;
        cin >> N;
        int c[N];
        for(auto i = 0; i != N; i++) {
            cin >> c[i];
            m = min(m, c[i]);
        }
        auto current = 0;
        for(auto i = 0; i != N; i++) {
            auto distance = c[i] - m;
            current += distance / 5;
            current += (distance % 5) / 2;
            current += (distance % 5) % 2;
        }
        auto result = current;
        current = 0;
        for(auto i = 0; i != N; i++) {
            auto distance = c[i] - m + 1;
            current += distance / 5;
            current += (distance % 5) / 2;
            current += (distance % 5) % 2;
        }
        result = min(result, current);
        current = 0;
        for(auto i = 0; i != N; i++) {
            auto distance = c[i] - m + 2;
            current += distance / 5;
            current += (distance % 5) / 2;
            current += (distance % 5) % 2;
        }
        cout << min(result, current) << endl;
    }
    return 0;
}
