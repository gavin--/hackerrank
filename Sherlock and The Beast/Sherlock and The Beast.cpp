#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        for(auto i = 0; i <= N; i += 5) {
            if((N - i) % 3 == 0) {
                string result;
                result.reserve(N);
                for(auto j = 0; j != N - i; j++) {
                    result.push_back('5');
                }
                for(auto j = 0; j != i; j++) {
                    result.push_back('3');
                }
                cout << result << endl;
                goto next;
            }
        }
        cout << -1 << endl;
        next:
        ;
    }
    return 0;
}
