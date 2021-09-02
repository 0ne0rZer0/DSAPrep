v#include<bits/stdc++.h>
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

int findInSortedArray(vector<int>& arr, int target) {
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    while(low < high) {
        int mid = (low + high)/2;
        if(arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    int rotation = low;
    low = 0;
    high = size - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int realMid = (mid + rotation) % size;
        if(arr[realMid] == target) return realMid;
        if(arr[realMid] < target) low = mid + 1;
        else  high = mid -1;
    } 
    return -1;
}

int findInSortedArrayOnePass(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(arr[mid] == target) return mid;
        // left size sorted
        if(arr[left] <= arr[mid]) {
            if(arr[left] <= target && target <= arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else { 
            // if left is not sorted then right MUST be sorted 
            // there is only one point of rotation which can be either left (0 - mid) or right (mid +1 - end)
            if(target >= arr[mid] && target <= arr[right]) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
    }
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
    int target;
    cin >> target;
    
    cout << findInSortedArray(arr, target) << endl;
    cout << findInSortedArrayOnePass(arr, target) << endl;
    return 0;
}