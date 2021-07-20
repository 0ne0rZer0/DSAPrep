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

// Method 1 : O(N^2) : check the best possible path after current or else set 1
int longestIncreasingSubsequence(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, 1);
  for(int i = n-2; i >= 0; i--) {
    int j = i+1;
    int mx = 0;
    while(j < n) {
      if(arr[j] > arr[i]) {
        mx = max(dp[j], mx);
      }
      j++;
    }
    dp[i] += mx;
  }
  return dp[0];
}
// Method 2 : O(NlogN) : Binary search instead of linear everytime
int longestIncreasingSubsequenceFast(vector<int>& arr) {
    if(arr.empty()) { return 0; }
    vector<int> tail;
    tail.push_back(arr[0]);
    for(auto n : arr) {
      if(n <= tail[0]) {
        tail[0] = n;
      } else if (n > tail.back()) {
        tail.push_back(n);
      } else {
        int left = 0;
        int right = tail.size()-1;
        int res = left;
        while(left <= right) {
          int mid = left + (right-left)/2;
          if (tail[mid] >= n) {
            res = mid;
            right = mid-1;
          } else { // tail[mid] < n
            left = mid+1;
          }
        }
        tail[res] = n;
      }
    }
    return tail.size();
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
    cout << longestIncreasingSubsequence(arr);
    return 0;
}