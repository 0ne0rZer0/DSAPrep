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
#define spacing <<" "
bool threeSum(vector<int>& arr, int sum) {
  sort(arr.begin(), arr.end());
  int n = arr.size();
  for(int i = 0; i < n - 2; i++) {
    int left = i+1;
    int right = n-1;
    while(left < right) {
      if(arr[i] + arr[left] + arr[right] == sum) {
        cout << "Triplet is " << arr[i] spacing << arr[left] spacing << arr[right];
        return true;
      } else if(arr[i] + arr[left] + arr[right] > sum){
        right--;
      } else {
        left++;
      }
    }
  }
  return false;
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
    threeSum(arr, sum);
    return 0;
}