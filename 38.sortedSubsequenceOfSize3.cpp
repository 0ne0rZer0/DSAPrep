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


void find3Numbers(vector<int>& arr) {
    int n = arr.size();
    int max = n-1;
    int min = 0;
    vector<int> smaller(n,0);
    smaller[0] = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] <= arr[min]) {
            min = i;
            smaller[i] = -1;
        } else {
            smaller[i] = min;
        }
    }
    vector<int> greater(n,0);
    for(int i = n -2; i>=0; i--) {
        if(arr[i] >= arr[max]) {
            max = i; 
            greater[i] = -1;
        } else {
            greater[i] = max;
        }
    }
    for(int i = 0; i < n; i++) {
        if(smaller[i] != -1 && greater[i] != -1) {
            cout << arr[smaller[i]] spacing << arr[i] spacing << arr[greater[i]];
            return;
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
    find3Numbers(arr);
    return 0;
}