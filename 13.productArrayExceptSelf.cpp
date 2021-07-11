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

vector<int> productArray(vector<int> arr) {
    vector<int> left(arr.size(),1);
    vector<int> right(arr.size(),1);
    vector<int> prod(arr.size(),1);
    int n = arr.size();
    left[0] = 1;
    right[n-1] = 1;
    
    for(int i = 1; i < n; i++) {
        left[i] = arr[i-1] * left[i-1];
    } 
    for(int i = arr.size()-2; i >= 0;i--) {
        right[i] = right[i+1] * arr[i+1];
    }
    int i = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        prod[i] = left[i] * right[i];
    }
    return prod;
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
    vector<int> prod = productArray(arr);
    for(int i : prod) {
        cout << i << " ";
    }
    return 0;
}