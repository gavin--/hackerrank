#include <map>
#include <iostream>
using namespace std;

int max(map<char, int>& count) {
    auto result = 0;
    for(auto& i : count) {
        if(i.second > result) {
            result = i.second;
        }
    }
    return result;
}

int main() {
    int n;
    string S;
    cin >> n >> S;
    auto result = n;
    map<char, int> count;
    for(auto& i : S) {
        count[i]++;
    }
    if(max(count) <= n / 4) {
        result = 0;
    }
    for(auto i = 0, j = 0; j < S.size(); j++) {
        if(max(count) > n / 4) {
            count[S[j]]--;
        }
        while(max(count) <= n / 4) {
            if(j - i + 1 < result) {
                result = j - i + 1;
            }
            count[S[i]]++;
            i++;
        }
    }
    cout << result;
    return 0;
}
