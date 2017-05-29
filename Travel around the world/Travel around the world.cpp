#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    long long C;
    cin >> N >> C;
    int a[N + N], b[N + N];
    for(auto i = 0; i != N; i++) {
        cin >> a[i];
        if(a[i] > C) {
            a[i] = C;
        }
        a[i + N] = a[i];
    }
    for(auto i = 0; cin >> b[i]; i++) {
    	b[i + N] = b[i];
    }
    vector<bool> start(N, true);
    for(auto i = 2 * N - 1; i >= N; i--) {
    	if(!start[i - N]) {
    		continue;
    	}
    	if(b[i] > a[i]) {
    		start[i - N] = false;
    		auto need = b[i] - a[i];
    		for(auto j = i - 1; j >= 0 && need > 0; j--) {
    			need += b[j];
                if(need > C) {
                    cout << 0;
                    return 0;
                }
    			need -= a[j];
    			if(need > 0) {
    				start[j % N] = false;
    			}
    		}
    	}
    }
    for(auto i : start) {
    	if(i) {
    		result++;
    	}
    }
    cout << result;
    return 0;
}
