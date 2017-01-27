#include <iostream>
using namespace std;

#define NEXT(prev, n)  (((prev) + (n)/(prev)) / 2)
 
int isqrt1(int n) {
    auto prev = n, current = NEXT(prev, n);
    while(abs(current - prev) > 1) {
        prev = current;
        current = NEXT(prev, n);
    }
    while(current * current > n) {
        current--;
    }
    return current;  
}

int main() {
    string s;
    cin >> s;
    auto sq = isqrt1(s.size());
    if(sq * sq != s.size()) {
        sq++;
    }
    auto row = sq, column = sq;
    string m[row];
    for(auto i = 0; i < row; i++) {
        if(i * column < s.size()) {
            m[i] = s.substr(i * column, column);
        } else {
            m[i] = "";
        }
    }
    for(auto i = 0; i < column; i++) {
        for(auto j = 0; j < row; j++) {
            if(i < m[j].size()) {
                cout << m[j][i];
            }
        }
        cout << ' ';
    }
    return 0;
}
