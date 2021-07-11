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

vector<int> twoDuplicates(vector<int> arr) {
  int XOR = arr[0];
  int n = arr.size();
  for(int i = 1; i <= n-2; i++) {
    XOR ^= i;
  }
  for(int i = 0; i < n; i++) {
    XOR ^= arr[i];
  }
  int set_bit_no = XOR ^ ~(XOR-1);
  int x = 0,y = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] & set_bit_no) {
      x = x^arr[i];
    } else {
      y = y^arr[i];
    }
  }
  for(int i = 1; i <= n-2; i++) {
    if(i & set_bit_no) {
      x = x ^ i;
    } else {
      y = y ^ i;
    }
  }
  return {x, y};
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
    vector<int> inp = twoDuplicates(arr);
    for(auto itr : inp) {
      cout << itr << " ";
    }
    return 0;
}