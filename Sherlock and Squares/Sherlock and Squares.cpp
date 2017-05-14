#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int A, B; cin >> A >> B; ) {
        auto i = 1, result = 0;
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
