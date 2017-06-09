#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3, h1 = 0, h2 = 0, h3 = 0;
    cin >> n1 >> n2 >> n3;
    int s1[n1], s2[n2], s3[n3];
    for(auto i = 0; i != n1; i++) {
        cin >> s1[i];
        h1 += s1[i];
    }
    for(auto i = 0; i != n2; i++) {
        cin >> s2[i];
        h2 += s2[i];
    }
    for(auto i = 0; i != n3; i++) {
        cin >> s3[i];
        h3 += s3[i];
    }
    for(n1 = 0, n2 = 0, n3 = 0; h1 != h2 || h2 != h3; ) {
        if(h1 > h2) {
            if(h3 > h1) {
                h3 -= s3[n3];
                n3++;
            } else {
                h1 -= s1[n1];
                n1++;
            }
        } else {
            if(h3 > h2) {
                h3 -= s3[n3];
                n3++;
            } else {
                h2 -= s2[n2];
                n2++;
            }
        }
    }
    cout << h1;
    return 0;
}
