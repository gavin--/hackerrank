#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, result, max = 0;
    cin >> n;
    map<int, int> count;
    for(int i; cin >> i; ) {
        count[i]++;
    }
    for(auto& i : count) {
        if(i.second > max) {
            result = i.first;
            max = i.second;
        }
    }
    cout << result;
    return 0;
}
