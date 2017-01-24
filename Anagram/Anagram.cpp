#include <map>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string S;
        cin >> S;
        if(S.size() % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        map<char, int> count;
        for(auto i = 0; i != S.size() / 2; i++) {
            count[S[i]]++;
        }
        auto result = 0;
        for(auto i = S.size() / 2; i != S.size(); i++) {
            auto find = count.find(S[i]);
            if(find == count.end()) {
                result++;
            } else {
                if(find->second == 1) {
                    count.erase(find);
                } else {
                    find->second--;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
