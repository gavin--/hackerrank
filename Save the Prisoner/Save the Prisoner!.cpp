#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, M, S;
        cin >> N >> M >> S;
        auto result = (M + S - 1) % N;
        if(result == 0) {
            result = N;
        }
        cout << result << endl;
    }
    return 0;
}
