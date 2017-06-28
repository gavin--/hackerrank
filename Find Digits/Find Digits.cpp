#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        auto result = 0;
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
