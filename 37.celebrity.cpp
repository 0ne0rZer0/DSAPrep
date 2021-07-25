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

int findCelebrity(vector<vector<int>>& arr) {
  int n = arr.size();
  int left = 0;
  int right = n-1;
  // Single out the possible candidate
  while(left < right) {
    if(arr[left][right]  == 1) {
      left++;
    } else {
      right--;
    }
  } 
  // Check if this is really the candidate
  int candidate = right;
  for(int i = 0; i < n; i++) {
    if(i != candidate && (arr[i][candidate] == 0  || arr[candidate][i] == 1)) {
      return -1;
    }
  }
  return candidate;
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
    return 0;
}