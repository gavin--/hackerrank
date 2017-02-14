#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> s1, s2, s3;
    int n1, n2, n3, h1 = 0, h2 = 0, h3 = 0;
    cin >> n1 >> n2 >> n3;
    for(auto i = 0; i != n1; i++) {
        int s;
        cin >> s;
        h1 += s;
        s1.emplace(s);
    }
    for(auto i = 0; i != n2; i++) {
        int s;
        cin >> s;
        h2 += s;
        s2.emplace(s);
    }
    for(auto i = 0; i != n3; i++) {
        int s;
        cin >> s;
        h3 += s;
        s3.emplace(s);
    }
    while(h1 != h2 || h2 != h3) {
        if(h1 > h2) {
            if(h3 > h1) {
                h3 -= s3.front();
                s3.pop();
            } else {
                h1 -= s1.front();
                s1.pop();
            }
        } else {
            if(h3 > h2) {
                h3 -= s3.front();
                s3.pop();
            } else {
                h2 -= s2.front();
                s2.pop();
            }
        }
    }
    cout << h1;
    return 0;
}
