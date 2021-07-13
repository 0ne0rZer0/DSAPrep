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

// Find the pivot index i.e in a sorted array find the arr[i] == i
int fixedPoint(vector<int>& arr) {
  int start = 0;
  int end = arr.size()-1;
  while(start <= end) {
    int mid = start + (end - start)/2;
    if(arr[mid] == mid) {
      return mid;
    } else if(arr[mid] > mid) {
      end = mid - 1;
    } else if(arr[mid] < mid) {
      start = mid + 1;
    }
  }
  return -1;
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
    cout << fixedPoint(arr);
    return 0;
}