#include <iostream>
#include <algorithm>
using namespace std;

string multiply(const string& a, const string& b) {
    int product[a.size() + b.size()];
    fill(product, product + a.size() + b.size(), 0);
    for(auto i = 0; i < a.size(); i++) {
        for(auto j = 0; j < b.size(); j++) {
            product[i + j] += (a.rbegin()[i] - '0') * (b.rbegin()[j] - '0');
        }
    }
    auto size = 0;
    for(auto i = 0, j = 0; i < a.size() + b.size(); i++) {
        auto t = product[i] + j;
        product[i] = t % 10;
        j = t / 10;
        if(product[i] != 0) {
            size = i + 1;
        }
    }
    if(size == 0) {
        return "0";
    }
    string result;
    result.reserve(size);
    for(auto i = size - 1; i >= 0; i--) {
        result.push_back(product[i] + '0');
    }
    return result;
}

int main() {
    int N;
    string result = "1";
    for(cin >> N; N > 1; N--) {
        result = multiply(result, to_string(N));
    }
    cout << result;
    return 0;
}
