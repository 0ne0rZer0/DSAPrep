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


vector<int> unionArraySorted(vector<int>& arr1, vector<int>& arr2) {
  vector<int> arrUnion;
  int i = 0;
  int j = 0;
  while(i < arr1.size() && j < arr2.size()) {
    if(arr1[i] <= arr2[j]) {
      arrUnion.push_back(arr1[i++]);
    } else {
      arrUnion.push_back(arr2[j++]);
    }
  }
  while(i < arr1.size()) {
    arrUnion.push_back(arr1[i++]);
  }
  while(j < arr2.size()) {
    arrUnion.push_back(arr2[j++]);
  }
  return arrUnion;
}

vector<int> intersectionArraySorted(vector<int>& arr1, vector<int>& arr2) {
  vector<int> arrIntersection;
  int i = 0;
  int j = 0;
  while( i < arr1.size() && j < arr2.size()) {
    if(arr1[i] == arr2[j]) {
      arrIntersection.push_back(arr1[i]++);
      i++;
      j++;
    } else if(arr1[i] < arr2[j]) {
      i++;
    } else {
      j++;
    }
  }
  return arrIntersection;
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

    int size2;
    cin >> size2;
    vector<int> arr2(size);  
    for(auto &it : arr2) {
        cin >> it;
    }
    vector<int> arrUnion = unionArraySorted(arr, arr2);
    vector<int> arrIntersection = intersectionArraySorted(arr, arr2);
    
    cout << "Union of an array " << ": ";
    for(auto itr : arrUnion) {
      cout << itr << " ";
    }
    cout << endl;
    cout << "Intersection of an array " << ": ";
    for(auto itr : arrIntersection) {
      cout << itr << " ";
    }
    return 0;
}