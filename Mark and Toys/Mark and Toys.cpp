#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, result = 0;
    cin >> N >> K;
    int toy[N];
    for(auto i = 0; cin >> toy[i]; i++) {
    }
    sort(toy, toy + N);
    for(auto& i : toy) {
        if(i <= K) {
            result++;
            K -= i;
        }
    }
    cout << result;
    return 0;
}
