#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; cout << endl) {
        switch((N - 3) % 4) {
            case 0:
            case 2:
                cout << 2;
                break;
            case 1:
                cout << 3;
                break;
            case 3:
                cout << 4;
                break;
        }
    }
    return 0;
}
