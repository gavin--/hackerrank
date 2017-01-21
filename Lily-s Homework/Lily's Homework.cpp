#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

template <class Compare>
int cycle(pair<int, int>* a, int n, Compare comp) {
    auto result = 0;
    sort(a, a + n, comp);
    vector<bool> visited(n);
    for(auto i = 0; i != n; i++) {
        if(visited[i] || i == a[i].second) {
            continue;
        }
        auto size = 0, current = i;
        while(visited[current] == false) {
            visited[current] = true;
            current = a[current].second;
            size++;
        }
        result += size - 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(auto i = 0; cin >> a[i].first; i++) {
        a[i].second = i;
    }
    cout << min(cycle(a, n, greater<pair<int, int>>()), cycle(a, n, less<pair<int, int>>()));
    return 0;
}
