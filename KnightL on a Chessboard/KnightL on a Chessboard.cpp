#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(auto a = 1; a < n; a++) {
        for(auto b = 1; b < n; b++) {
            short moves[n][n];
            for(auto i = 0; i < n; i++) {
                fill(moves[i], moves[i] + n, -1);
            }
            queue<pair<short, short>> queue;
            moves[0][0] = 0;
            queue.emplace(0, 0);
            while(!queue.empty()) {
                auto front = queue.front();
                queue.pop();
                if(front.first + a < n) {
                    if(front.second + b < n && moves[front.first + a][front.second + b] == -1) {
                        queue.emplace(front.first + a, front.second + b);
                        moves[front.first + a][front.second + b] = moves[front.first][front.second] + 1;
                    }
                    if(front.second - b >= 0 && moves[front.first + a][front.second - b] == -1) {
                        queue.emplace(front.first + a, front.second - b);
                        moves[front.first + a][front.second - b] = moves[front.first][front.second] + 1;
                    }
                }
                if(front.first - a >= 0) {
                    if(front.second + b < n && moves[front.first - a][front.second + b] == -1) {
                        queue.emplace(front.first - a, front.second + b);
                        moves[front.first - a][front.second + b] = moves[front.first][front.second] + 1;
                    }
                    if(front.second - b >= 0 && moves[front.first - a][front.second - b] == -1) {
                        queue.emplace(front.first - a, front.second - b);
                        moves[front.first - a][front.second - b] = moves[front.first][front.second] + 1;
                    }
                }
                if(front.first + b < n) {
                    if(front.second + a < n && moves[front.first + b][front.second + a] == -1) {
                        queue.emplace(front.first + b, front.second + a);
                        moves[front.first + b][front.second + a] = moves[front.first][front.second] + 1;
                    }
                    if(front.second - a >= 0 && moves[front.first + b][front.second - a] == -1) {
                        queue.emplace(front.first + b, front.second - a);
                        moves[front.first + b][front.second - a] = moves[front.first][front.second] + 1;
                    }
                }
                if(front.first - b >= 0) {
                    if(front.second + a < n && moves[front.first - b][front.second + a] == -1) {
                        queue.emplace(front.first - b, front.second + a);
                        moves[front.first - b][front.second + a] = moves[front.first][front.second] + 1;
                    }
                    if(front.second - a >= 0 && moves[front.first - b][front.second - a] == -1) {
                        queue.emplace(front.first - b, front.second - a);
                        moves[front.first - b][front.second - a] = moves[front.first][front.second] + 1;
                    }
                }
            }
            cout << moves[n - 1][n - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}
