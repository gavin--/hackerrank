#include <queue>
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    queue<int> queue;
    for(int type; cin >> type; ) {
        switch(type) {
            case 1:
                int x;
                cin >> x;
                queue.emplace(x);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                cout << queue.front() << endl;
        }
    }
    return 0;
}
