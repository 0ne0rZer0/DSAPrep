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

int recursiveBruteForce(string s) {
  return recursiveBruteForce(0, s.length()-1, s);
}
int recursiveBruteForce(int left, int right, string s) {
  if(left == right) return 1;
  if(left > right) return 0;
  return s[left] == s[right] ? 2 + recursiveBruteForce(left+1,right-1,s) : max(recursiveBruteForce(left+1,right,s), recursiveBruteForce(left, right-1,s));
}

int recursiveMemoization(string s) {
  int n = s.length();
  vector<vector<int>> cache(n, vector<int>(n,0));
  return recursiveMemoization(0, s.length()-1, s, cache);
}
int recursiveMemoization(int left, int right, string s, vector<vector<int>>& cache) {
  if(left == right) return 1;
  if(left > right) return 0;
  if(cache[left][right] != -1) return cache[left][right];
  return cache[left][right] = s[left]==s[right] ? 2 + recursiveMemoization(left+1, right-1, s, cache) : max(recursiveMemoization(left+1, right, s, cache), recursiveMemoization(left, right-1, s, cache));  
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
    return 0;
}