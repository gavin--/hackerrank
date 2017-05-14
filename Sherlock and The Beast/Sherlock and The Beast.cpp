#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        string result = "-1\n";
        for(auto i = 0; i <= N; i += 5) {
            if((N - i) % 3 == 0) {
                result = "";
                result.reserve(N);
                for(auto j = 0; j != N - i; j++) {
                    result.push_back('5');
                }
                for(auto j = 0; j != i; j++) {
                    result.push_back('3');
                }
                result.push_back('\n');
                break;
            }
        }
        cout << result;
    }
    return 0;
}
