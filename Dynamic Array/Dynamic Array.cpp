#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, Q, lastAns = 0;
    cin >> N >> Q;
    vector<int> seqList[N];
    for(int q, x, y; cin >> q >> x >> y; ) {
        switch(q) {
            case 1:
                seqList[(x ^ lastAns) % N].emplace_back(y);
                break;
            case 2:
                lastAns = seqList[(x ^ lastAns) % N][y % seqList[(x ^ lastAns) % N].size()];
                cout << lastAns << endl;
        }
    }
    return 0;
}
