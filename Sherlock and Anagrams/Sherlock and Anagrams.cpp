#include <map>
#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        string S;
        cin >> S;
        auto result = 0;
        for(auto i = 0; i != S.size(); i++) {
            for(auto j = 1; i + j <= S.size(); j++) {
                map<char, short> count1;
                for(auto k = i; k < i + j; k++) {
                    count1[S[k]]++;
                }
                auto count2 = count1;
                for(auto k = i + 1; k + j <= S.size(); k++) {
                    auto find = count2.find(S[k - 1]);
                    if(find->second == 1) {
                        count2.erase(find);
                    } else {
                        find->second--;
                    }
                    count2[S[k + j - 1]]++;
                    if(count1 == count2) {
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
