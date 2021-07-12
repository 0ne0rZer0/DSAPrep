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
// Find bionic point in an array which has the maximum array of length: 
// bionic point: a point in an array where left <= point >= right

// Solution 
/*
  create an increasing array (stores length upto i of increasing array)
  create a decreasing array  (stores length upto i from right of decreasing array)
*/


int bionicLength(vector<int>& arr) {
    vector<int> inc(arr.size(), 1);
    vector<int> dec(arr.size(), 1);
    int n = arr.size();
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > arr[i-1]) {
            inc[i] += inc[i-1];
        }
        cout << inc[i] << " ";
    }
    cout << endl;
    for(int i=n-2; i >= 0; i--) {
        if(arr[i] > arr[i+1]) {
            dec[i] += dec[i+1];
        }
        cout << dec[i] << " ";
    }
    cout << endl;
    int maxLength = inc[0] + dec[0] - 1;
    for(int i = 1; i < n; i++) {
        maxLength = max(inc[i] + dec[i]-1, maxLength);
    }
    return maxLength;
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
    cout << bionicLength(arr);
    return 0;
}