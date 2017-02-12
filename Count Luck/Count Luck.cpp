#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, M, K, result = 0;
        cin >> N >> M;
        char forest[N][M];
        int count[N][M];
        queue<pair<int, int>> queue;
        vector<bool> visited[N];
        fill(visited, visited + N, vector<bool>(M));
        for(auto i = 0; i != N; i++) {
            for(auto j = 0; j != M; j++) {
                cin >> forest[i][j];
                if(forest[i][j] == 'M') {
                    queue.emplace(i, j);
                    visited[i][j] = true;
                    count[i][j] = 0;
                }
            }
        }
        cin >> K;
        while(true) {
            auto front = queue.front();
            queue.pop();
            auto current = 0;
            vector<pair<int, int>> next;
            if(forest[front.first][front.second] == '*') {
                if(count[front.first][front.second] == K) {
                    cout << "Impressed\n";
                } else {
                    cout << "Oops!\n";
                }
                break;
            }
            if(front.first > 0 && !visited[front.first - 1][front.second] && (forest[front.first - 1][front.second] == '.' || forest[front.first - 1][front.second] == '*')) {
                queue.emplace(front.first - 1, front.second);
                visited[front.first - 1][front.second] = true;
                next.emplace_back(front.first - 1, front.second);
                current++;
            }
            if(front.second > 0 && !visited[front.first][front.second - 1] && (forest[front.first][front.second - 1] == '.' || forest[front.first][front.second - 1] == '*')) {
                queue.emplace(front.first, front.second - 1);
                visited[front.first][front.second - 1] = true;
                next.emplace_back(front.first, front.second - 1);
                current++;
            }
            if(front.first < N - 1 && !visited[front.first + 1][front.second] && (forest[front.first + 1][front.second] == '.' || forest[front.first + 1][front.second] == '*')) {
                queue.emplace(front.first + 1, front.second);
                visited[front.first + 1][front.second] = true;
                next.emplace_back(front.first + 1, front.second);
                current++;
            }
            if(front.second < M - 1 && !visited[front.first][front.second + 1] && (forest[front.first][front.second + 1] == '.' || forest[front.first][front.second + 1] == '*')) {
                queue.emplace(front.first, front.second + 1);
                visited[front.first][front.second + 1] = true;
                next.emplace_back(front.first, front.second + 1);
                current++;
            }
            if(current > 1) {
                count[front.first][front.second]++;
            }
            for(auto& i : next) {
                count[i.first][i.second] = count[front.first][front.second];
            }
        }
    }
    return 0;
}
