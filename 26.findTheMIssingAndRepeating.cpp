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

void findTheMissingAndRemaining(vector<int>& arr) {
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    int index = abs(arr[i])-1;
    if(arr[index] > 0) {
      arr[index] = -1 * arr[index];
    } else {
      cout << arr[i] << " is repeating" << endl;
      break;
    }
  }
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] > 0) {
      cout << i+1 << " is missing" << endl;
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
    findTheMissingAndRemaining(arr);
    return 0;
}