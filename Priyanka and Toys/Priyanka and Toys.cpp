#include <set>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    set<int> w;
    for(int i; cin >> i; ) {
        w.emplace(i);
    }
    while(!w.empty()) {
        auto m = *w.begin();
        w.erase(m);
        w.erase(m + 1);
        w.erase(m + 2);
        w.erase(m + 3);
        w.erase(m + 4);
        result++;
    }
    cout << result;
    return 0;
}
