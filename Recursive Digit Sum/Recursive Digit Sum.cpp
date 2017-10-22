#include <iostream>
using namespace std;

long long solve(string n) {
    if(n.size() == 1) {
        return n[0] - '0';
    }
    int sum = 0;
    for(auto i : n) {
        sum += i - '0';
    }
    return solve(to_string(sum));
}

int main() {
    string n;
    long long k, sum = 0;
    cin >> n >> k;
    for(auto i : n) {
        sum += i - '0';
    }
    sum *= k;
    cout << solve(to_string(sum));
    return 0;
}
