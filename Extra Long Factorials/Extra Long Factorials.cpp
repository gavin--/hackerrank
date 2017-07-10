#include <iostream>
#include <algorithm>
using namespace std;

string multiply(const string& a, const string& b) {
    int product[a.size() + b.size()];
    fill(product, product + a.size() + b.size(), 0);
    for(int i = a.size() - 1; i >= 0; i--) {
        for(int j = b.size() - 1; j >= 0; j--) {
            auto sum = (a[i] - '0') * (b[j] - '0') + product[i + j + 1];
            product[i + j] += sum / 10;
            product[i + j + 1] = sum % 10;
        }
    }
    for(auto i = 0; i < a.size() + b.size(); i++) {
        if(product[i] != 0) {
            string result;
            while(i < a.size() + b.size()) {
                result.push_back(product[i] + '0');
                i++;
            }
            return result;
        }
    }
    return "0";
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
