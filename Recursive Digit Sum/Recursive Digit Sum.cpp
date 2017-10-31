#include <iostream>
using namespace std;

long long solve(long long n) {
    if(n <= 9) {
        return n;
    }
    long long sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return solve(sum);
}

int main() {
    string n;
    long long k, sum = 0;
    cin >> n >> k;
    for(auto i : n) {
        sum += i - '0';
    }
    sum *= k;
    cout << solve(sum);
    return 0;
}
