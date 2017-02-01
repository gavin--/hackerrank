#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string map[n];
    for(auto i = 0; cin >> map[i]; i++) {
    }
    for(auto i = 1; i < n - 1; i++) {
        for(auto j = 1; j < n - 1; j++) {
            if(map[i - 1][j] < map[i][j] && map[i][j - 1] < map[i][j] && map[i + 1][j] < map[i][j] && map[i][j + 1] < map[i][j]) {
                map[i][j] = 'X';
            }
        }
    }
    for(auto& i : map) {
        cout << i << endl;
    }
    return 0;
}
