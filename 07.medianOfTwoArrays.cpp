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

int medianOfTwoArrays(vector<int>& arrX, vector<int>& arrY, int m, int n) {
    if(m > n) {
        return medianOfTwoArrays(arrY, arrX, n, m);
    }
    int low = 0;
    int high = m;
    while(low <= high) {
        int partitionX = (low + high)/2;
        int partitionY = (m + n + 1)/2 - partitionX;
        
        int maxLeftX = (partitionX == 0) ? INT_MIN : arrX[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : arrX[partitionX];
        
        int maxLeftY = (partitionY == 0) ? INT_MIN : arrY[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : arrY[partitionY];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m + n) % 2 == 0) {
                    return ((double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0);
            } else {
                    return ((double)max(maxLeftX, maxLeftY));   
            }
        }else if (maxLeftX > minRightX){
            high = partitionX - 1;
        }else {
            low = partitionX + 1;
        }
    }
    return -1;
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
    cout << medianOfTwoArrays(arrX, arrY, m, n);
    return 0;
}