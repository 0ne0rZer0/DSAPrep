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
#define printValue(x) cout << x << " ";
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// Add new elements at the back, and keep only largest one and remove all the smaller ones
// the front element will ALWAYS be the largest cause
// it reached front by removing all weaker ones
// add front in each window/loop
vector<int> maximumOfAllSubarray(vector<int>& arr,int k) {
  deque<int> queue;
  vector<int> ans;
  int i = 0;
  int size = arr.size();
  // traversing K elements for filling the queue
  for(; i < k; i++) {
    // remove the weaklings
    while((!queue.empty()) && arr[i] >=(arr[queue.back()])) {
      queue.pop_back();
    }
    queue.push_back(i);
    
  }
  for(; i < size; i++) {
    // add the MAX to ans
    ans.push_back(arr[queue.front()]);

    // Remove out of window elements from front as they might be max but expired
    while((!queue.empty()) && queue.front() <= i - k) {
      queue.pop_front();
    }
    // Remove the weaklings even equal ones because latest is better  
    while((!queue.empty()) && (arr[i] >= arr[queue.back()])) {
      queue.pop_back();
    }
    queue.push_back(i);
  }
  ans.push_back(arr[queue.front()]);
  return ans;
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
    int k;
    cin >> k;
    vector<int> ans = maximumOfAllSubarray(arr, k);
    for(int i : ans) {
      debug(i);
    }
    return 0;
}