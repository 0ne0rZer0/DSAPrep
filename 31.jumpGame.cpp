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
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// Method 1 O(n^2) using Dynamic programming
int minimumJumpsDynamic(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, INT_MAX);
  dp[n-1] =  0;
  for(int i = n - 2; i >= 0; i--) {
    for(int j = 1; i+j < n && j <= arr[i]; j++)  {
      dp[i] = min(dp[i], 1 + dp[i+j]);
    }
  }
  return dp[0];
}

// Method 2 O(n) using Greedy Paradigm
int minimumJumpGreedy(vector<int>& arr) {
  int i = 0;
  if(arr[0] == 0) return -1;
  int n = arr.size();
  int count = 0;
  while(i < n-1) {
    int maxNeighbour = 0;
    int maxIndex = i;
    for(int j = 1; j + i < n && j <= arr[i]; j++) {
      if(arr[i+j] + i+j  >= maxNeighbour) {
        maxNeighbour = arr[i+j] + i+j ;
        maxIndex = i+j;
        if(maxIndex == n-1) return count+1;
      }
    }
    i = maxIndex;
    count++;
  }
  return count;
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
    cout << minimumJumpsDynamic(arr) << endl;
    cout << minimumJumpGreedy(arr) << endl;
    return 0;
}