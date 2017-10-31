#include <iostream>
#include <iterator>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << accumulate(istream_iterator<long long>(cin), istream_iterator<long long>(), 0ll);
    return 0;
}
