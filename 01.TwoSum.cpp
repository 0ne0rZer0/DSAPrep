// 3 ways

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

bool twoSumHash(vector<int>& arr, int target) {
    unordered_set<int> hashmap;
    for(auto &it : arr) {
        if(hashmap.find(target - it) != hashmap.end()) {
            return true;
        } 
        hashmap.insert(it);
    }
    return false;
}


int main() {
    FIO
    OJ
    int size, target;
    cin >> size;
    vector<int> arr(size);  
    for(auto &it : arr) {
        cin >> it;
    }
    cin >> target;
    twoSumHash(arr, target) ? cout << "True" : cout << "False";
    return 0;
}


