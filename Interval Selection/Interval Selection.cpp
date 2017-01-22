#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int s;
    for(cin >> s; s > 0; s--) {
        int n;
        cin >> n;
        pair<int, int> intervals[n];
        for(auto i = 0; i != n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        sort(intervals, intervals + n);
        list<pair<int, int>> list;
        for(auto& i : intervals) {
            list.emplace_back(i);
            auto count = 0;
            auto k = list.end();
            for(auto j = list.begin(); j != list.end(); j++) {
                if(j->second >= i.first) {
                    count++;
                    if(k == list.end() || k->second < j->second) {
                        k = j;
                    }
                }
            }
            if(count == 3) {
                list.erase(k);
            }
        }
        cout << list.size() << endl;
    }
    return 0;
}
