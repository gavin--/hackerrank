#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        auto sum = 0;
        int A[N];
        for(auto i = 0; i != N; i++) {
            cin >> A[i];
            sum += A[i];
        }
        auto result = "NO\n";
        for(auto i = 0, j = 0; i != N; i++) {
            if(j == sum - j - A[i]) {
                result = "YES\n";
                break;
            }
            j += A[i];
        }
        cout << result;
    }
    return 0;
}
