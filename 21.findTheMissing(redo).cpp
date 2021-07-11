/*
Find the smallest missing number
Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the
array. */
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

int findMissingNumberRecursive(vector<int>& arr, int start, int end) {
  if(start > end) {
    return end + 1;
  }
  if(start != arr[start]) {
    return start;
  }
  int mid = start + (end - start)/2;
  if(arr[mid] > mid) {
    return findMissingNumberRecursive(arr, start, mid);
  } else {
    return findMissingNumberRecursive(arr, mid+1, end);
  }
}

int findMissingNumber(vector<int>& arr) {
  int start = 0;
  int end = arr.size()-1;
  while(start <= end) {
    int mid = start + (end-start)/2;
    if(arr[start] != start) return start;    
    if(arr[mid] > mid) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return end+1;
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
    cout << findMissingNumber(arr) << endl;
    cout << findMissingNumberRecursive(arr, 0, arr.size()-1);
    return 0;
}