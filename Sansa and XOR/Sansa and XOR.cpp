#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int result = 0;
        for(int i = 0, a; i != N; i++) {
            cin >> a;
            if((i + 1) % 2 * (N - i) % 2 == 1) {
                result = result ^ a;
            }
        }
        cout << result << endl;
    }
    return 0;
}
