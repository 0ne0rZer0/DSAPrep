#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define ll long long
#define MOD 1000000007
#define x first
#define y second
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define spacing << " " 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double distance(pii A, pii B) {
  return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}
int orientation(pii p, pii q, pii r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
double solve(vector<pii> whiteStars, pii blueStar) {
  return 0;
}
int main() {
    FIO
    OJ
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
      int whiteStars;
      cin >> whiteStars;
      vector<pair<int,int>> arr(whiteStars);
      pair<int,int> blueStar;
      for(auto &it : arr) {
          cin >> it.first;
          cin >> it.second;
      }
      cin >> blueStar.first;
      cin >> blueStar.second;
      cout << "Case #" << i+1 << ": " << solve(arr,blueStar) << endl;
    }
    return 0;
}