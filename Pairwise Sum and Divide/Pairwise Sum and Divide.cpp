#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        long long one = 0, two = 0;
        for(auto i = 0; i != N; i++) {
            int A;
            cin >> A;
            switch(A) {
                case 1:
                    one++;
                    break;
                case 2:
                    two++;
            }
        }
        cout << one * (N - 1) + two * (two - 1) / 2 << endl;
    }
    return 0;
}
