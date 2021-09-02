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
//Greedy solution which works with a GP of 4 members. 1, r, r^2, r^3

int changeMaking(vector<int>& arr, int coinAmount) {
  sort(arr.begin(), arr.end(), greater<int>());
  int numCoins = 0;
  for(int coin : arr) {
    // use the max coin amount and see how many coins of that denomination are required
    numCoins += coinAmount / coin;
    coinAmount = coinAmount % coin; 
  }
  return numCoins;
}
int main() {
    FIO
    OJ
    int coinAmount;
    cin >> coinAmount;
    int size;
    cin >> size;
    vector<int> arr(size);  
    for(auto &it : arr) {
        cin >> it;
    }
    cout << changeMaking(arr, coinAmount);
    return 0;
}