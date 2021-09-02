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
// Time complexity 2^(max(length)))
int recursiveBruteForce(string text1, string text2) {
  if(text1.length() == 0 || text2.length() == 0) return 0;
  return recursiveBruteForce(text1, text2, 0, 0);
}
int recursiveBruteForce(string text1, string text2, int i, int j) {
  if(text1.length() == i || text2.length() == j) {
    return 0;
  }
  if(text1[i] == text2[j]) {
    return 1 + recursiveBruteForce(text1, text2, i+1, j+1);
  } else {
    return max(recursiveBruteForce(text1, text2, i, j+1), recursiveBruteForce(text1, text2, i+1, j)) + 1;
  }
}

// Time complexity O()
int recursiveMemoization(string text1, string text2) {
  if(text1.length() == 0 || text2.length() == 0) return 0;
  vector<vector<int>> cache(text1.length(), vector<int>(text2.length(), -1));
  return recursiveMemoization(text1, text2, 0, 0, cache);
}
int recursiveMemoization(string text1, string text2, int i, int j, vector<vector<int>>& cache) {
  if(text1.length() == i || text2.length() == j) {
    return 0;
  }
  if(cache[i][j] != -1) return cache[i][j];
  if(text1[i] == text2[j]) {
    cache[i][j] = 1 + recursiveMemoization(text1, text2, i+1, j+1, cache);
  } else {
    cache[i][j] = max(recursiveMemoization(text1, text2, i, j+1, cache), recursiveMemoization(text1, text2, i+1, j, cache));
  }
  return cache[i][j];
}

int bottomUp(string text1, string text2) {
 if(text1.length() == 0 || text2.length() == 0) return 0;
      vector<vector<int>> cache(text1.length()+1, vector<int>(text2.length()+1, 0));
      int length1 = text1.length();
      int length2 = text2.length();
      for(int i = 1; i <= length1; i++) {
        for(int j = 1; j <= length2; j++) {
          if(text1[i-1] == text2[j-1]) {
            cache[i][j] = 1 + cache[i-1][j-1];
          } else {
            cache[i][j] = max(cache[i][j-1], cache[i-1][j]);
          }
        }
      }
      return cache[length1][length2];
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