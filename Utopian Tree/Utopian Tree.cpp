#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        auto result = 1ll;
        bool d = true;
        while(N > 0) {
            N--;
            if(d) {
                result *= 2;
                d = false;
            } else {
                result += 1;
                d = true;
            }
        }
        cout << result << endl;
    }
    return 0;
}
