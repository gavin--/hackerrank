#include <stack>
#include <iostream>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    stack<int> op, app;
    stack<string> del;
    for(string S, W; Q > 0; Q--) {
        int t, k;
        cin >> t;
        switch(t) {
            case 1:
                cin >> W;
                op.emplace(1);
                app.emplace(W.size());
                S.append(W);
                break;
            case 2:
                cin >> k;
                op.emplace(2);
                del.emplace(S.substr(S.size() - k, k));
                while(k > 0) {
                    k--;
                    S.pop_back();
                }
                break;
            case 3:
                cin >> k;
                cout << S[k - 1] << endl;
                break;
            case 4:
                switch(op.top()) {
                    case 1:
                        for(auto i = app.top(); i > 0; i--) {
                            S.pop_back();
                        }
                        app.pop();
                        break;
                    case 2:
                        S.append(del.top());
                        del.pop();
                }
                op.pop();
        }
    }
    return 0;
}
