#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
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
        cout << endl;
    }
    return 0;
}
