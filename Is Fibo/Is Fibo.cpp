#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    vector<long long> fib {0, 1};
    while(fib.back() + fib.rbegin()[1] <= 10000000000) {
        fib.emplace_back(fib.back() + fib.rbegin()[1]);
    } 
    for(cin >> T; T > 0; T--) {
        long long N;
        cin >> N;
        auto it = lower_bound(begin(fib), end(fib), N);
        if(it != end(fib) && *it == N) {
            cout << "IsFibo\n";
        } else {
            cout << "IsNotFibo\n";
        }
    }
    return 0;
}
