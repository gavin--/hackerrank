#include <map>
#include <iostream>
using namespace std;

int main() {
    int N, K, result = 0;
    cin >> N >> K;
    map<int, int> sweet;
    for(int A; cin >> A; sweet[A]++) {
    }
    while(true) {
        auto cookie = sweet.begin()->first;
        if(cookie >= K) {
            cout << result;
            return 0;
        }
        if(sweet.begin()->second == 1) {
            sweet.erase(sweet.begin());
            if(sweet.empty()) {
                break;
            }
            cookie += 2 * sweet.begin()->first;
            if(sweet.begin()->second == 1) {
                sweet.erase(sweet.begin());
            } else {
                sweet.begin()->second -= 1;
            }
        } else {
            cookie += 2 * sweet.begin()->first;
            if(sweet.begin()->second == 2) {
                sweet.erase(sweet.begin());
            } else {
                sweet.begin()->second -= 2;
            }
        }
        sweet[cookie]++;
        result++;
    }
    cout << -1;
    return 0;
}
