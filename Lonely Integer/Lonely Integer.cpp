#include <vector>
#include <iostream>
using namespace std;

int lonelyinteger(vector<int>& a) {
    int answer = 0;
    for(auto& i : a) {
        answer ^= i;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(auto i = 0; i < n; i++) {
        int j;
        cin >> j;
        a.emplace_back(j);
    }
    cout << lonelyinteger(a);
    return 0;
}
