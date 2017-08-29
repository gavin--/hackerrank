#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> back;
    priority_queue<int> front;
    for(int a; cin >> a; ) {
        if(back.size() == front.size()) {
            if(front.empty() || front.top() < a) {
                back.emplace(a);
            } else {
                front.emplace(a);
            }
        } else if(back.size() < front.size()) {
            if(front.top() < a) {
                back.emplace(a);
            } else {
                back.emplace(front.top());
                front.pop();
                front.emplace(a);
            }
        } else {
            if(back.top() > a) {
                front.emplace(a);
            } else {
                front.emplace(back.top());
                back.pop();
                back.emplace(a);
            }
        }
        if(back.size() == front.size()) {
            cout << (front.top() + back.top()) / 2;
            if((front.top() + back.top()) % 2 == 1) {
                cout << ".5\n";
            } else {
                cout << ".0\n";
            }
        } else {
            if(back.size() < front.size()) {
                cout << front.top() << ".0\n";
            } else {
                cout << back.top() << ".0\n";
            }
        }
    }
    return 0;
}
