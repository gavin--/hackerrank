#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int petro[N], distance[N];
    for(auto i = 0; cin >> petro[i] >> distance[i]; i++) {
    }
    auto result = 0;
    for(auto i = 0, tank = 0; i < N; i++) {
        tank += petro[i];
        if(tank >= distance[i]) {
            tank -= distance[i];
        } else {
            result = i + 1;
            tank = 0;
        }
    }
    cout << result;
    return 0;
}
