#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    map<int, int> map;
    for(int a; cin >> a; map[a]++) {
    }
    for(auto& i : map) {
        auto find1 = map.find(i.first - 1), find2 = map.find(i.first + 1);
        if(find1 != end(map)) {
            result = max(result, i.second + find1->second);
        }
        if(find2 != end(map)) {
            result = max(result, i.second + find2->second);
        }
        result = max(result, i.second);
    }
    cout << result;
    return 0;
}
