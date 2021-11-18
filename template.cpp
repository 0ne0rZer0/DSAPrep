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


int main() {
    FIO
    OJ
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      vector<char> arr(size);  
      for(auto &it : arr) {
          cin >> it;
      }
    }
    return 0;
}