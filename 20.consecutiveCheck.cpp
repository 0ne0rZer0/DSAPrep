/*
  Consequitive array or not
*/
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

/*
Important check required is that all elements are distinct, now if all elements are positive we con do this in O(1) space
by using negative sign as a visited using index reference
but if not positive we will have to use O(n) space regardless
Method 1 : Max-min+1
Method 2 : AP
*/ 
bool checkDistinctPositiveOnly(vector<int>& arr, int minV) {
  for(int i : arr) {  
    if(arr[i - minV] < 0) return false;
    arr[i - minV] = arr[i-minV] * -1;
  }
}
bool convertArrayToPositive(vector<int>& arr, int min) {
  int shift = abs(min);
  for(int i = 0; i < arr.size(); i++) {
    arr[i] = arr[i] + shift;
  }
}

bool checkConsequitive(vector<int>& arr) {
  int maxV = INT_MIN;
  int minV = INT_MAX;
  for(int i : arr) {
    maxV = max(i, maxV);
    minV = min(i, minV);
  }
  int n = maxV - minV + 1;
  if(n == arr.size()) {
    convertArrayToPositive(arr, minV);
    bool distinct = checkDistinctPositiveOnly(arr, minV);
    if(distinct) {
      return true;
    }
  } 
  return false;
}

bool checkConsequitiveAP(vector<int>& arr) {

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
