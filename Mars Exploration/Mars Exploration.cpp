#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    auto result = 0;
    for(auto i = 0; i != S.size(); i += 3) {
        if(S[i] != 'S') {
            result++;
        }
        if(S[i + 1] != 'O') {
            result++;
        }
        if(S[i + 2] != 'S') {
            result++;
        }
    }
    cout << result;
    return 0;
}
