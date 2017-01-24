#include <iostream>
using namespace std;

int main() {
    int N, K;
    string s;
    cin >> N >> s >> K;
    K = K % 26;
    for(auto& i : s) {
        if(isalpha(i)) {
            if(isupper(i)) {
                i = i + K;
                if(!isupper(i)) {
                    i = i - 'Z' + 'A' - 1;
                }
            } else {
                i = i + K;
                if(!islower(i)) {
                    i = i - 'z' + 'a' - 1;
                }
            }
        }
    }
    cout << s;
    return 0;
}
