#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    map<char, int> count;
    for(string rock; cin >> rock; ) {
        sort(begin(rock), end(rock));
        count[rock[0]]++;
        for(auto i = 1; i < rock.size(); i++) {
            if(rock[i] != rock[i - 1]) {
                count[rock[i]]++;
            }
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
