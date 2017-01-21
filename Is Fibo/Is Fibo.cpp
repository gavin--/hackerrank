#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    long long prev2 = 0, prev1 = 1;
    vector<long long> fib {0, 1};
    while(prev2 + prev1 <= 10000000000) {
        auto t = prev2 + prev1;
        fib.emplace_back(t);
        prev2 = prev1;
        prev1 = t;
    } 
    for(cin >> T; T > 0; T--) {
        long long N;
        cin >> N;
        auto it = lower_bound(begin(fib), end(fib), N);
        if(it != end(fib) && *it == N) {
            cout << "IsFibo";
        } else {
            cout << "IsNotFibo";
        }
        cout << endl;
    }
    return 0;
}
