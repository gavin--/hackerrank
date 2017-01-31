#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int A, B, result = 0;
        cin >> A >> B;
        auto i = 1;
        while(i * i < A) {
            i++;
        }
        while(i * i <= B) {
            i++;
            result++;
        }
        cout << result << endl;
    }
    return 0;
}
