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

int merge(vector<int>& arr, int start, int mid, int end) {
  vector<int> temp(end-start+1, 0);
  int i,j,k;
  i = start;
  j = mid;
  k = start;
  int inv_count = 0;
  while((i <= mid-1) && (j <= end)) {
    if(arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while(i < mid) {
    temp[k++] = arr[i++];
  }
  while(j <= end) {
    temp[k++] = arr[j++];
  }

  for(i = start; i <= end; i++) {
    arr[i] = temp[i];
  }
  return inv_count;
}

int mergeSortInversions(vector<int>& arr, int start, int end) {
  if(start < end) {
    int mid = (end+start)/2;
    int left = mergeSortInversions(arr, start, mid);
    int right = mergeSortInversions(arr, mid+1, end);
    int inversions = merge(arr, start, mid, end);
    return left + right + inversions;
  }
  return 0;
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
    int inversions = mergeSortInversions(arr, 0, arr.size()-1);
    cout << inversions << endl;
    return 0;
}