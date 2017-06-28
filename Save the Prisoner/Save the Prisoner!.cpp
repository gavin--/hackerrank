#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, M, S; cin >> N >> M >> S; ) {
        auto result = (M + S - 1) % N;
        if(result == 0) {
            result = N;
        }
        cout << result << endl;
    }
    return 0;
}
