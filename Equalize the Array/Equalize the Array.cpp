#include <map>
#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    map<int, int> count;
    for(int i; cin >> i; ) {
        count[i]++;
    }
    for(auto& i : count) {
        result = max(result, i.second);
    }
    cout << n - result;
    return 0;
}
