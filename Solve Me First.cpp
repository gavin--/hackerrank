// https://www.hackerrank.com/challenges/solve-me-first
#include <cstdio>
#include <iostream>
using namespace std;

int solveMeFirst(int a, int b) {
        return a + b;
}

int main() {
      int num1, num2;
      cin >> num1 >> num2;
      auto sum = solveMeFirst(num1,num2);
      cout << sum;
      return 0;
}
