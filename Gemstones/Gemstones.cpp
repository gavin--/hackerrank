#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    map<char, int> count;
    for(string rock; cin >> rock; ) {
        set<char> s;
        for(auto& i : rock) {
            s.emplace(i);
        }
        for(auto& i : s) {
            count[i]++;
        }
    }
    for(auto& i : count) {
        if(i.second == N) {
            result++;
        }
    }
    cout << result;
    return 0;
}
