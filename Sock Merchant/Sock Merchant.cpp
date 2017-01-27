#include <map>
#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    map<int, int> c;
    for(int i; cin >> i; ) {
        c[i]++;
    }
    for(auto& i : c) {
        result += i.second / 2;
    }
    cout << result;
    return 0;
}
