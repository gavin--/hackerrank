#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        auto i = 2, result = 0;
        for(; i < N / i; i++) {
            if(N % i == 0) {
                if(i % 2 == 0) {
                result++;
                }
                if((N / i) % 2 == 0) {
                    result++;
                }
            }
        }
        if(i * i == N && i % 2 == 0) {
            result++;
        }
        if(N % 2 == 0) {
            result++;
        }
        cout << result << endl;
    }
    return 0;
}
