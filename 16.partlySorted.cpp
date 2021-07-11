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

void unsortedArray(vector<int>& arr) {
  int n = arr.size();
  int start = 0;
  int end = n -1;
  int max = 0, min = 0;
  for(; start < n - 1; start++) {
    if(arr[start] > arr[start + 1]) {
      break;
    }
  }
  if(start == n-1) return;
  for(; end > 0; end--) {
    if(arr[end] < arr[end-1]) {
      break;
    }
  }
  max = arr[start]; 
  min = arr[start];
  for(int i = 0; i < start; i++) {
    if(arr[i] > min) {
      start = i;
      break;
    }
  }
  for(int i = n - 1; i >= end + 1; i--) {
    if(arr[i] < max) {
      end = i;
      break;
    }
  }
  for(auto itr = arr.begin() + start; itr <= arr.begin() + end; itr++) {
    cout << *itr << " ";
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
    unsortedArray(arr);
    return 0;
}