#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define ll long long
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define spacing << " " 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int solve(vector<char> arr) {
  vector<int> distance(arr.size(), INT_MAX);
  int closest1 = INT_MAX;
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] != '1') {
      distance[i] = min(distance[i], abs(closest1 - i));
    } else {
      closest1 = i;
      distance[i] = 0;
    }
  }
  closest1 = INT_MAX;
  int ans = 0;
  for(int i = arr.size()-1; i>=0; i--) {
    if(arr[i] != '1') {
      distance[i] = min(distance[i], abs(closest1 - i));
      ans += distance[i];
    } else {
      closest1 = i;
      distance[i] = 0;
    }
  }
  return ans;
}

int main() {
    FIO
    OJ
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      cout << endl;
      vector<char> arr(size);  
      for(auto &it : arr) {
          cin >> it;
      }
      cout << "Case #" << i+1 << ": " << solve(arr);
    }
    return 0;
}