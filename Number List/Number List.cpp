#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, K; cin >> N >> K; ) {
        auto result = 0ll;
        for(auto i = 0, last = -1; i != N; i++) {
            int A;
            cin >> A;
            if(A > K) {
                result += (i - last) * (N - i);
                last = i;
            }
        }
        cout << result << endl;
    }
    return 0;
}
