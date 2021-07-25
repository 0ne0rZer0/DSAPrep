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

void longestSubarrayWithEqualZerosOnes(vector<int>& arr) {
  int sum = 0;
  int n = arr.size();
  unordered_map<int,int> map;
  int longestSize = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i] == 0 ? -1 : 1;
    if(sum == 0) {
      longestSize = max(longestSize, i+1);
    } else {
      auto it = map.find(sum);
      if(it != map.end()) {
        longestSize = max(longestSize, i - it->second);
      } else {
        map.insert({sum,i});
      }
    }
  }
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
    longestSubarrayWithEqualZerosOnes(arr);
    return 0;
}