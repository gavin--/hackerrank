#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> generate(const string& S) {
    vector<string> result;
    for(auto i = 0; i != S.size(); i++) {
        auto current = generate(S.substr(i + 1));
        for(auto& j : current) {
            j.insert(0, 1, S[i]);
        }
        result.emplace_back(string(1, S[i]));
        result.insert(end(result), begin(current), end(current));
    }
    return result;
} 

void print(string& S) {
    for(auto& j : generate(S)) {
        cout << j << endl;
    }
}

int main() {
    int T, N;
    cin >> T;
    for(string S; cin >> N >> S; ) {
        sort(begin(S), end(S));
        print(S);
    }
    return 0;
}
