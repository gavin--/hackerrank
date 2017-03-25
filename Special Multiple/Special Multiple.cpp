#include <iostream>
using namespace std;

long long next(long long X) {
    for(auto i = X, j = 9ll; ; i /= 10, j *= 10) {
        if(i % 10 == 0) {
            X += j;
            return X;
        } else {
            X -= j;
        }
    }
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long N, X = 9;
        cin >> N;
        while(X % N != 0) {
            X = next(X);
        }
        cout << X << endl;
    }
    return 0;
}
