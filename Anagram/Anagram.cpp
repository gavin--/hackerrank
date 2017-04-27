#include <map>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string S; cin >> S; ) {
        auto result = 0;
        if(S.size() % 2 == 1) {
            result = -1;
        } else {
            map<char, int> count;
            for(auto i = 0; i != S.size() / 2; i++) {
                count[S[i]]++;
            }
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
        }
        cout << result << endl;
    }
    return 0;
}
