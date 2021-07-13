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

int minimumDistanceBetweenTwoNumbers(vector<int>& arr, int x, int y) {
  int lastX = -1;
  int lastY = -1;
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    if(lastX != -1 && lastY != -1) break;
    if(arr[i] == x && lastX == -1) {
      lastX = i;
    } else if(arr[i] == y && lastY == -1) {
      lastY = i;
    } 
  }
  if(lastX == -1 || lastY == -1) return -1;
  int minDifference = abs(lastX - lastY);
  int i = min(lastX, lastY);
  i++;
  while(i < n) {
    if(arr[i] == x) {
      lastX = i;
      minDifference = min(abs(lastX - lastY), minDifference);  
    }
    if(arr[i] == y) {
      lastY = i;
      minDifference = min(abs(lastX - lastY), minDifference);  
    }
    i++;
  }
  return minDifference;
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
    int x, y;
    cin >> x >> y;
    cout << minimumDistanceBetweenTwoNumbers(arr, x, y);
    return 0;
}