#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// recursion
int fibonacci(int n) {
  if(n <= 2) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
} 

// memoization
int memoizationForFibonacci(int n, vector<int>& memoization) {
  if(n <= 2) return 1;
  if(memoization[n] != -1) return memoization[n];
  memoization[n] = memoizationForFibonacci(n-1, memoization) + memoizationForFibonacci(n-2, memoization);
  return memoization[n];
}

// bottom up
int bottomUpFibonacci(int n) {
  vector<int> arr(n+1, 0);
  arr[0] = 0;
  arr[1] = 1;
  for(int i = 2; i <= n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }
  return arr[n];
}

// bottom up with less space
int bottomUpFibonacci2(int n) {
  int curr = 1;
  int prev = 1;
  int prevprev = 0;
  for(int i = 2; i <= n; i++) {
    curr = prev + prevprev;
    int temp = prev;
    prev = curr;
    prevprev = temp;
  }
  return curr;
}

int main() {
    OJ
    int n;
    cin >> n;
    vector<int> memoization(n+1, -1);
    memoization[0] = 0;
    memoization[1] = 1;
    // cout << fibonacci(n) << endl;
    cout << memoizationForFibonacci(n, memoization) << endl;
    cout << bottomUpFibonacci(n) << endl;
    cout << bottomUpFibonacci2(n) << endl;

    return 0;
}






