#include <map>
#include <set>
#include <iostream>
using namespace std;

int main() {
    int n, result = -1;
    cin >> n;
    map<int, set<int>> buckets;
    for(int i = 1, j; cin >> j; i++) {
        buckets[j].emplace(i);
    }
    for(auto& i : buckets) {
        auto bucket = i.second;
        auto current = *bucket.rbegin() - *bucket.begin();
        if(current > 0 && (result == -1 || current < result)) {
            result = current;
        }
    }
    cout << result;
    return 0;
}
