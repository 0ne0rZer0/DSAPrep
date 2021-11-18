#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int minCostRecursive(vector<int>& stairs, int n) {
  if(n < 0) return 0;
  if(n < 2) return stairs[n];
  return stairs[n] + min(minCostRecursive(stairs, n-1), minCostRecursive(stairs, n-2));
}

int minCostRecursiveMemoization(vector<int>& stairs, vector<int>& memo, int n) {
  if(n < 0) return 0;
  if(n < 2) return stairs[n];
  if(memo[n] != -1) return memo[n];
  return stairs[n] + min(minCostRecursive(stairs, n-1), minCostRecursive(stairs, n-2));
}

int minCostBottomUp(vector<int>& stairs, int n) {
  vector<int> memo(n+1,0);
  memo[0] = stairs[0];
  memo[1] = stairs[1];
  for(int i = 2; i <= n; i++) {
    memo[i] = stairs[i] + min(memo[i-1], memo[i-2]);
  }
  return min(memo[n-1], memo[n-2]);
}

int minCostBottomUpV2(vector<int>& stairs, int n) {

}