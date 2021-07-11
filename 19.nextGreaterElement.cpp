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

vector<int> nextGreaterElement(vector<int>& arr) {
  vector<int> nextGreater;
  stack<int> stck;
  unordered_map<int,int> nextGreaterOf;
  stck.push(arr[0]);
  for(int i = 1; i < arr.size(); i++) {
      int next = arr[i];
      while(!stck.empty() && stck.top() < next) {
          nextGreaterOf[stck.top()] = next;
          stck.pop();
      }
      stck.push(next);
  }
  while(!stck.empty()) {
      nextGreaterOf[stck.top()] = -1;
      stck.pop();
  }
  for(int i : arr) {
      nextGreater.push_back(nextGreaterOf[i]);
  }
  return nextGreater;
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
    vector<int> nextGreater = nextGreaterElement(arr);
    for(auto &it : nextGreater) {
        cout << it << " ";
    }
    return 0;
}