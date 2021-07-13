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

int maxDifference(vector<int>& arr) {
  int size = arr.size();
  vector<int> leftArray(arr.size(), 0);
  vector<int> rightArray(arr.size(), 0);
  leftArray[0] = arr[0];
  rightArray[size-1] = arr[size-1];
  for(int i = 1; i < arr.size(); i++) {
    leftArray[i] = min(arr[i], leftArray[i-1]);
  }
  for(int i = arr.size()-2; i >=0 ; i--) {
    rightArray[i] = max(rightArray[i+1], arr[i]);
  }
  int maxDifference = -1;
  int i = 0;
  int j = 0;  
  while(i < size && j < size) {
    if(leftArray[i] < rightArray[j]) {
      maxDifference = max(maxDifference, j - i);
      j++;
    } else {
      i++;
    }
  }

  return maxDifference;
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
    cout << maxDifference(arr);   
    return 0;
}