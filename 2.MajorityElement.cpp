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

int majorityElement(vector<int> arr) {
    // First pass of Moore's voting algorithm
    int maj = 0;
    int maj_count = 1;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] == arr[maj]) {
            maj_count++;
        } else {
            maj_count--;
            if(maj_count == 0) {
                maj = i;
                maj_count++;
            }
        }
    }
    // Second pass of Moore's voting algorithms to check whether it is majority
    maj_count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == arr[maj]) {
            maj_count++;
        }
    }
    if(maj_count > arr.size()/2) return arr[maj];
    return -1;
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
    cout << majorityElement(arr);
    return 0;
}