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

void merge(vector<int>& arr, int start, int mid, int end) {
  vector<int> temp(end - start + 1, 0);
  int i = start, j = mid+1, k = 0;
  while(i <= mid && j <= end) {
    if(arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  } 
  while(i <= mid) {
    temp[k++] = arr[i++];
  }
  while(j <= end) {
    temp[k++] = arr[j++];
  }
  k = 0;
  for(int i = start; i <= end; i++) {
    arr[i] = temp[k++];
  }
}
void mergeSort(vector<int>& arr, int start, int end) {
  if(start < end) {
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
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
    mergeSort(arr, 0, size-1);
    for(int i : arr) {
      cout << i << " ";
    }
    return 0;
}