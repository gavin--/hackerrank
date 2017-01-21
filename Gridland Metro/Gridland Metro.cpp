#include <forward_list>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    auto result = (long long)n * m;
    map<int, forward_list<pair<int, int>>> grid;
    for(int r, c1, c2; cin >> r >> c1 >> c2; ) {
        grid[r - 1].emplace_front(c1, c2);
    }
    for(auto& i : grid) {
        auto r = i.second;
        r.sort();
        if(r.begin() == r.end()) {
            continue;
        }
        for(auto i = r.begin(), j = next(r.begin()); j != r.end(); ) {
            if(i->second >= j->first) {
                i->second = max(j->second, i->second);
                j = r.erase_after(i);
            } else {
                i++;
                j++;
            }
        }
        for(auto& i : r) {
            result -= i.second - i.first + 1;
        }
    }
    cout << result;
    return 0;
}
