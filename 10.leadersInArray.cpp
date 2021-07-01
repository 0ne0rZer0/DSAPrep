/*
Leaders in an array
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost
element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.
*/
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

vector<int> leadersInArray(vector<int>& arr) {
  int n = arr.size();
  int maxFromRight = arr[n-1];
  vector<int> leaders;
  leaders.push_back(maxFromRight);
  for(int i = n - 2; i >= 0; i--) {
    if(arr[i] > maxFromRight) {
      leaders.push_back(arr[i]);
      maxFromRight = arr[i];
    }
  }
  return leaders;
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
    vector<int> leaders = leadersInArray(arr);
    for(int i : leaders) {
      cout << i << " ";
    }
    return 0;
}