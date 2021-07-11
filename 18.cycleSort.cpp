#include<bits/stdc++.h>
// Least MEMORY SWAPS! 
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

void cycleSort(vector<int>& arr) {
  // total memory writes
  int writes = 0;
  int n = arr.size();
  for(int cycle_start = 0; cycle_start <= n-2; cycle_start++) {
    int item = arr[cycle_start];
    int pos = cycle_start;
    for(int i = cycle_start + 1; i < n; i++) {
      if(arr[i] < item) {
        pos++;
      }
    }
    if(pos == cycle_start) {
      continue;
    }
    while(item == arr[pos]) {
      pos += 1;
    }
    if(pos != cycle_start) {
      swap(item, arr[pos]);
      writes++;
    }
    while (pos != cycle_start) {
      pos = cycle_start;

      // Find position where we put the element
      for (int i = cycle_start + 1; i < n; i++)
          if (arr[i] < item)
              pos += 1;

      // ignore all duplicate  elements
      while (item == arr[pos])
          pos += 1;

      // put the item to it's right position
      if (item != arr[pos]) {
          swap(item, arr[pos]);
          writes++;
      }
    }
  }
  cout << "Writes : " << writes << "\n";
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
    cycleSort(arr);
    for(auto &it : arr) {
        cout << it << " ";
    }
    return 0;
}