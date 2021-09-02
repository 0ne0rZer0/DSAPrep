#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define spacing << " " 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int knapsackRecursiveMemoization(vector<int>& value, vector<int>& weight, int index, int limitOfBag, vector<vector<int>>& cache) {
  if(index >= value.size() || limitOfBag <= 0) return 0;
  int including = 0;
  if(cache[index][limitOfBag] != -1) return cache[index][limitOfBag];
  if(weight[index] <= limitOfBag) {
    including = knapsackRecursiveMemoization(value, weight, index+1, limitOfBag - weight[index], cache) + value[index];
  }
  int excluding = knapsackRecursiveMemoization(value, weight, index+1, limitOfBag, cache);
  cache[index][limitOfBag] = max(including, excluding);
  return cache[index][limitOfBag];
}

int knapsackBottomUp(vector<int>& value, vector<int>& weight, int limitOfBag) {
  vector<vector<int>> dp(value.size(),vector<int>(limitOfBag+1, 0));
  for(int i = 0; i < value.size(); i++) {
    dp[i][0] = 0;
  }
  for(int i = 1; i <= limitOfBag; i++) { 
    if(i >= weight[0])
      dp[0][i] = value[0];
  }
  for(int i = 1; i < value.size(); i++) {
    for(int w = 1; w <= limitOfBag; w++) {
      int include = 0;
      int exclude = dp[i-1][w];
      if(w >= weight[i]) {
        include = value[i] + dp[i-1][w - weight[i]];
      }
      dp[i][w] = max(include, exclude);
    }
  }
  return dp[value.size()-1][limitOfBag];
}
int main() {
    FIO
    OJ
    int size;
    cin >> size;
    vector<int> arr(size);  
    for(auto &it : arr) {
        cin >> it;
    }
    vector<int> weight(size);  
    for(auto &it : weight) {
        cin >> it;
    }
    int limit = 0;
    cin >> limit;
    vector<vector<int>> cache(arr.size(), vector<int>(limit+1,-1));
    for(int i = 0; i < arr.size(); i++) {
      cache[i][0] = 0;
    }
    // cout << knapsackRecursiveMemoization(arr, weight, 0, limit, cache);
    cout << knapsackBottomUp(arr, weight, limit);
    return 0;
}