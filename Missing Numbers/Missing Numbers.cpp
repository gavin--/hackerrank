#include <map>
#include <set>
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
    set<int> missing;
    for(int j; cin >> j; ) {
        auto find = a.find(j);
        if(find != a.end()) {
            if(find->second == 1) {
                a.erase(find);
            } else {
                find->second--;
            }
        } else {
            missing.emplace(j);
        }
    }
    for(auto& i : missing) {
        cout << i << ' ';
    }
    return 0;
}
