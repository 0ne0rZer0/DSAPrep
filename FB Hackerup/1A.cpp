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

int consistentString(string s) {
  unordered_map<char,int> vowels;
  vowels.insert({'A', 0});
  vowels.insert({'E', 0});
  vowels.insert({'I', 0});
  vowels.insert({'O', 0});
  vowels.insert({'U', 0});  
  unordered_map<char,int> consonant;
  int maxVowelMax = 0;
  int maxConstantMax = 0;
  int totalVowels = 0;
  int totalVowelsFrequency = 0;
  int totalConsonantFrequency = 0;
  for(auto i : s) {
    if(vowels.find(i) != vowels.end()) {
      if(vowels[i] == 0) {
        totalVowels++;
      }
      vowels[i]++;
      totalVowelsFrequency++;
      maxVowelMax = max(maxVowelMax, vowels[i]);
    } else {
      consonant[i]++;
      totalConsonantFrequency++;
      maxConstantMax = max(maxConstantMax, consonant[i]);
    }
  } 
  int totalConsonants = consonant.size();
  int ans1 = (totalVowelsFrequency - maxVowelMax)*2 + totalConsonantFrequency;
  int ans2 = (totalConsonantFrequency - maxConstantMax)*2 + totalVowelsFrequency;
  return min(ans1,ans2);
}

int main() {
    FIO
    OJ
    int testcases = 0;
    cin >> testcases;
    for(int i = 1; i <= testcases; i++) {
      string s;
      cin >> s; 
      cout << "Case #" << i << ": " << consistentString(s) << "\n";
    }
    return 0;
}