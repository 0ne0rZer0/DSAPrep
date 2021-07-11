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


void dutchFlag(vector<int>& arr) {
  int low = 0;
  int mid = 0;
  int high = arr.size()-1;
  while(mid <= high) {
    switch (arr[mid])
    {
    case 0:
      swap(arr[low++], arr[mid++]);
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(arr[mid], arr[high--]);
      break;
    default:
      break;
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
    dutchFlag(arr);
    for(auto &it : arr) {
        cout << it << " ";
    }
    return 0;
}