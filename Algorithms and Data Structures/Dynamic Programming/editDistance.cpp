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
//Brute force
int recursiveBruteForce(string word1, string word2) {
  if(word1 == "") return word2.length();
  if(word2 == "") return word1.length();
  return recursiveBruteForce(word1, word2, 0,0);

}
int recursiveBruteForce(string word1, string word2, int i, int j) {
  if(word1.length() == i) {
    return word2.length() - j;
  }
  if(word2.length() == j) {
    return word1.length() - i;
  } 
  int res;
  if(word1[i] == word2[j]) {
    res = recursiveBruteForce(word1, word2, i+1, j+1);
  } else {
    // case 1 : Insert
    int insert = recursiveBruteForce(word1, word2, i, j+1);
    // case 2 : Delete 
    int del = recursiveBruteForce(word1, word2, i+1, j);
    // case 3 : Replace
    int replace = recursiveBruteForce(word1, word2, i+1, j+1);
    res = min(min(insert, del), replace) + 1;
  }
  return res;
}
int recursiveMemoization(string word1, string  word2) {
  if(word1 == "") return word2.length();
  if(word2 == "") return word1.length();
  vector<vector<int>> cache(word1.length(), vector<int>(word2.length(), -1));
  return recursiveMemoization(word1, word2, 0,0 ,cache);
}
int recursiveMemoization(string word1, string word2, int i, int j, vector<vector<int>>& cache) {
  if(word1.length() == i) {
    return word2.length() - j;
  }
  if(word2.length() == j) {
    return word1.length() - i;
  }
  if(cache[i][j] != -1) return cache[i][j];
  if(word1[i] == word2[j]) {
    cache[i][j] = recursiveMemoization(word1, word2, i+1,j+1, cache);
  } else {
    // case 1 : Insert
    int insert = recursiveMemoization(word1, word2, i,j+1, cache);
    // case 2 : Delete 
    int del = recursiveMemoization(word1, word2, i+1,j, cache);
    // case 3 : Replace
    int replace = recursiveMemoization(word1, word2, i+1, j+1, cache);
    cache[i][j] = min(min(insert,del),replace) + 1;
  }
  return cache[i][j];
}
int bottomUp(string word1, string word2) {
  if(word1 == "") return word2.length();
  if(word2 == "") return word1.length();
  vector<vector<int>> cache(word1.length()+1, vector<int>(word2.length()+1, -1));
  for(int i = 0; i <= word1.length(); i++) {
    cache[i][0] = i; 
  }
  for(int j = 0; j <= word2.length(); j++) {
    cache[0][j] = j;
  }
  for(int i = 1; i <= word1.length(); i++) {
    for(int j = 1; j <= word2.length(); j++) {
      if(word1[i-1] == word2[j-1]) {
        cache[i][j] = cache[i-1][j-1];
      } else {
        // order of insert, delete, replace
        cache[i][j] = min(min(cache[i][j-1], cache[i-1][j]), cache[i-1][j-1]) + 1;
      }
    }
  }
  return cache[word1.length()][word2.length()];
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
}\