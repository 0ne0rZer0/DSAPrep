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
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
vector<int> intervalScheduling(vector<pair<int,int>> intervals) {
  sort(intervals.begin(), intervals.end(), sortbysec);
  vector<int> ans;
  int visit = intervals[0].second;
  int i = 1;
  ans.emplace_back(visit);
  while(i < intervals.size()) {
    if(intervals[i].first > visit) {
      visit = intervals[i].second;
      ans.emplace_back(visit);
    }
    i++;
  }
  return ans;
}
int main() {
    FIO
    OJ
    int size;
    cin >> size;
    vector<pair<int,int>> arr(size);  
    for(auto &it : arr) {
      cin >> it.first;
      cin >> it.second;
    }
    vector<int> ans = intervalScheduling(arr);
    for(int i : ans) {
      cout << i << " ";
    }
    return 0;
}