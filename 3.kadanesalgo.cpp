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

int kadanesAlgorithm(vector<int> arr) {
    int max_upto_here = 0;
    int max_best = 0; 
    for(auto itr : arr) {
        max_upto_here += itr;
        if(max_upto_here < 0) {
            max_upto_here = 0;
        } else if(max_best < max_upto_here) {
            max_best = max_upto_here;
        }
    }
    return max_best;
}


int kadanesAlgorithmClean(vector<int> arr) {
    int curr = arr[0];
    int maxV = curr;
    for(int i = 1; i < arr.size(); i++) {
        curr = max(arr[i], arr[i] + curr);
        maxV = max(maxV, curr);
    }
    return maxV;
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
    cout << kadanesAlgorithm(arr);
    cout << kadanesAlgorithmClean(arr);
    return 0;
}