#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, result = 0;
        cin >> N;
        for(auto n = N; n > 0; n /= 10) {
            auto d = n % 10;
            if(d != 0 && N % d == 0) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
