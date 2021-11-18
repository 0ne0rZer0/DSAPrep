#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

typedef vector <int> vi;
typedef vector <char> vc;
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

ll minGoodString(vc arr, ll size, ll k) {
    ll left = 0;
    ll right = size-1;
    int score = 0;
    while(left < right) {
        if(arr[left] != arr[right]) {
            score++;
        }
        left++;
        right--;
    }
    return abs(score - k);
}
int main() {
    FIO
    OJ
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
      ll size;
      cin >> size;
      ll K;
      cin >> K;
      vector<char> arr(size);  
      for(auto &it : arr) {
          cin >> it;
      }
      cout << "Case #" << i+1 << ": " << minGoodString(arr,size,K);
    }
    return 0;
}