#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, M; cin >> N >> M; cout << endl) {
        if(N % 2 == 0 || M == 1) {
            cout << 2;
        } else {
            cout << 1;
        }
    }
    return 0;
}
