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

void mergeTwoArrays(vector<int>& arr1, vector<int> arr2, int m, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n -1;
    while(i >= 0 && j >= 0) {
        if(arr2[j] > arr1[i]) {
            arr1[k--] = arr2[j--];
        } else {
            arr1[k--] = arr1[i--];
        }
    }
    while(i >= 0) {
        arr1[k--] = arr1[i--];    
    } 
    while(j >= 0) {
        arr1[k--] = arr2[j--];
    }
}
int main() {
    FIO
    OJ
    int m;
    cin >> m;
    vector<int> arrX(m);  
    for(auto &it : arrX) {
        cin >> it;
    }
    int n;
    cin >> n;
    vector<int> arrY(n);  
    for(auto &it : arrY) {
        cin >> it;
    }
    mergeTwoArrays(arrX, arrY, m, n);
}