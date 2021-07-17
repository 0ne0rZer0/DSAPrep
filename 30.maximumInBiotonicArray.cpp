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

//Find the maximum element in an array which is first increasing and then decreasing
// O(n) is basically Linear Search
// O(logn) should be the aim through Binary Search
/* 
Binary Search
  if mid > left and mid > right return mid
  if mid < right go towards right
  if mid < left go towards left
*/
int maximumInBiotonicArray(vector<int>& arr, int low, int high) {
  if(low == high) 
    return arr[low];
  if(high == low + 1) {
    return arr[high] > arr[low] ? arr[high] : arr[low];
  }
  int mid = low + (high-low)/2;
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
    cout << maximumInBiotonicArray(arr, 0, arr.size()-1);
    return 0;
}