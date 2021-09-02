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

// Each worker gets two jobs, the max time = longest time for a worker
int maxTimeForJobsToFinish(vector<int> jobs) {
  sort(jobs.begin(), jobs.end());
  int left = 0; 
  int right = jobs.size()-1;
  int max_time = jobs[left] + jobs[right];
  while(left < right) {
    max_time = max(max_time, jobs[left] + jobs[right]);
    left++; right--;
  }
  return max_time;
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
    cout << maxTimeForJobsToFinish(arr);
    return 0;
}