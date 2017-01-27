#include <iostream>
using namespace std;

int count(string& a, string& b) {
    auto result = 0;
    for(auto i = 0; i != a.size(); i++) {
        if(a[i] == '1' || b[i] == '1') {
            result++;
        }
    }
    return result;
}

int main() {
    int n, m, topic = 0, team;
    cin >> n >> m;
    string a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    for(auto i = 0; i != n; i++) {
        for(auto j = 0; j != i; j++) {
            auto current = count(a[i], a[j]);
            if(current > topic) {
                topic = current;
                team = 1;
            } else if(current == topic) {
                team++;
            }
        }
    }
    cout << topic << endl << team;
    return 0;
}
