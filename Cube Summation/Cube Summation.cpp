#include <vector>
#include <iostream>
using namespace std;

int lowbit(int n) {
    return n & -n;
}

long long sum(vector<vector<vector<long long>>>& bit, long long x, long long y, long long z) {
    long long result = 0;
    while(x > 0) {
        for(auto t = y; t > 0; t -= lowbit(t)) {
            for(auto r = z; r > 0; r -= lowbit(r)) {
                result += bit[x][t][r];
            }
        }
        x -= lowbit(x);
    }
    return result;
}

long long sum(vector<vector<vector<long long>>>& bit, long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    auto result = sum(bit, x2, y2, z2);
    result -= sum(bit, x1 - 1, y2, z2);
    result -= sum(bit, x2, y1 - 1, z2);
    result -= sum(bit, x2, y2, z1 - 1);
    result += sum(bit, x1 - 1, y1 - 1, z2);
    result += sum(bit, x2, y1 - 1, z1 - 1);
    result += sum(bit, x1 - 1, y2, z1 - 1);
    result -= sum(bit, x1 - 1, y1 - 1, z1 - 1);
    return result;
}

void add(vector<vector<vector<long long>>>& bit, long long x, long long y, long long z, long long val) {
    while(x < bit.size()) {
        for(auto t = y; t < bit[x].size(); t += lowbit(t)) {
            for(auto r = z; r < bit[x][t].size(); r += lowbit(r)) {
                bit[x][t][r] += val;
            }
        }
        x += lowbit(x);
    }
}

int main() {
    int T;
    cin >> T;
    for(int N, M; cin >> N >> M; ) {
        vector<vector<vector<long long>>> bit(N + 1, vector<vector<long long>>(N + 1, vector<long long>(N + 1, 0)));
        do {
            string op;
            long long x1, y1, z1, x2, y2, z2, w;
            cin >> op;
            switch(op[0]) {
                case 'U':
                    cin >> x1 >> y1 >> z1 >> w;
                    add(bit, x1, y1, z1, w - sum(bit, x1, y1, z1, x1, y1, z1));
                    break;
                case 'Q':
                    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                    cout << sum(bit, x1, y1, z1, x2, y2, z2) << endl;
            }
            M--;
        } while(M > 0);
    }
    return 0;
}
