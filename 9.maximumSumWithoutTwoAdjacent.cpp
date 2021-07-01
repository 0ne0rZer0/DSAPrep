// Maximum sum such that no two elements are adjacent
// Question: Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence
// should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the
// question in most efficient way.

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


// Algorithm ? 
/*
 Keep calculating max sum with including previous element and excluding previous element
  return max between those;
*/
int maxSumBottomUpWithSpace(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, 0);
  dp[0] = arr[0];
  dp[1] = max(arr[0], arr[1]);
  for(int i = 2; i < n; i++) {
    dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
  }
  return dp[n-1];
}

int maxSumNoSpace(vector<int>& arr) {
  int n = arr.size();
  int first = arr[0];
  int second = max(arr[0], arr[1]);
  int curr = 0;
  for(int i = 2; i < n; i++) {
    curr = max(arr[i] + second, first);
    second = first;
    first = curr;
  }
  return curr;
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
    cout << maxSumBottomUpWithSpace(arr) << endl;
    cout << maxSumNoSpace(arr);
    return 0;
}