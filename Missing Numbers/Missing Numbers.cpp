#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<int, int> a;
    for(auto i = 0; i != n; i++) {
        int j;
        cin >> j;
        a[j]++;
    }
    cin >> m;
    vector<int> missing;
    for(int j; cin >> j; ) {
        auto find = a.find(j);
        if(find != a.end()) {
            if(find->second == 1) {
                a.erase(find);
            } else {
                find->second--;
            }
        } else {
            missing.emplace_back(j);
        }
    }
    sort(begin(missing), end(missing));
    if(!missing.empty()) {
        cout << missing[0] << ' ';
    }
    for(auto i = 1; i < missing.size(); i++) {
        if(missing[i] != missing[i - 1]) {
            cout << missing[i] << ' ';
        }
    }
    return 0;
}
