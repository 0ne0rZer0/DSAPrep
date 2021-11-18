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
struct attr {
  long long rating;
  int start;
  int end;
  bool operator >(const attr& atr) const {
    return rating > atr.rating;
  }
};


long long solve(int days, int k, vector<attr> attractions) {
  sort(attractions.begin(), attractions.end(), greater<attr>());
  long long ans = 0;
  for(int i = 1; i <= days; i++) {
    long long total = 0;
    int j = 0;
    int traverse = 0;
    while(j < k && traverse < attractions.size()) {
      if(attractions[traverse].start <= i && attractions[traverse].end >= i) {
        total += attractions[traverse].rating;
        j++;
      }
      traverse++;
    }
    ans = max(total, ans);
  }
  return ans;
}
int main() {
    FIO
    OJ
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
      int days;
      cin >> days;
      int attractions;
      cin >> attractions;
      int k;
      cin >> k;
      vector<attr> arr(attractions);  
      for(auto &it : arr) {
        cin >> it.rating;
        cin >> it.start;
        cin >> it.end;
      }
      cout << "Case #" << i+1 << ": " << solve(days, k, arr) << endl;
    }
    return 0;
}