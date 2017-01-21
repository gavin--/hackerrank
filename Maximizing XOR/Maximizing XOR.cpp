#include <iostream>
using namespace std;

int main() {
    int L, R, result = 0;
    cin >> L >> R;
    for(auto i = L; i <= R; i++) {
        for(auto j = L; j <= i; j++) {
            result = max(result, i ^ j);
        }
    }
    cout << result;
    return 0;
}
