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

// X is the distance which is possible
bool checkIfPossible(int x, vector<int>& arr, int C, int N) {
  int cows_placed = 1, last_pos = arr[0];
  for(int i = 1; i < N; i++) {
    if((arr[i] - last_pos) >= x) {
      if(++cows_placed == C) {
        return true;
      }
      last_pos = arr[i];
    }
  }
  return false;
}
int aggressiveCows(vector<int>& arr, int C, int N) {
  sort(arr.begin(), arr.end());
  long long low = 0, high = arr[N-1] - arr[0], mid, ans = 0;
  
  while(high >= low) {
    mid = low + (high-low)/2;
    if(checkIfPossible(mid, arr, C, N)) {
      low = mid+1;
      ans = mid;
    } else {
      high = mid-1;
    }
  }
  return ans;
}

int main() {
    FIO
    OJ
    int testCases = 0;
    cin >> testCases;
    while(testCases-- > 0) {
      int size, C;
      cin >> size >> C;
      vector<int> arr(size);  
      for(auto &it : arr) {
          cin >> it;
      }
      cout << aggressiveCows(arr, C, size) << " ";
    } 
    return 0;
}