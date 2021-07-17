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


pair<int,int> subarrayWithSum(vector<int>& arr, int sum) {
  cout << "Sum to be found is " << sum << endl;
  int curr_sum = arr[0];
  int left = 0;
  int n = arr.size();
  int right = 1;
  for(; right <= n; right++) {
    while(curr_sum > sum && left < right - 1) {
      curr_sum = curr_sum - arr[left];
      left++;
    } 
    if(curr_sum == sum) {
      return make_pair(left, right-1);
      
    }
    if(right < n)
      curr_sum += arr[right];
  }
  return {};
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
    int sum;
    cin >> sum;
    pair<int,int> index = subarrayWithSum(arr,sum);
      cout << index.first << " to " << index.second;
    return 0;
}