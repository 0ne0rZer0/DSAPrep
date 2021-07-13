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
// Running number so need an offset on either heaps;
class Median {
    // MaxHeap for left side : gives rightmost element on the left side (sorted)
priority_queue<int> first;
    // MinHeap for right side : gives leftmost element on the right side (sorted)
priority_queue<int, vector<int>, greater<int>> second;
public:
void addNum(int num) {
    // Add num to the respective half of the array
    if(first.empty() || first.top() > num) {
        first.push(num);
    } else {
        second.push(num);
    }
    // balance the heap with a difference of not more than 1 (odd array)
    if(first.size() > 1 + second.size()) {
        second.push(first.top());
        first.pop();
    } else if(second.size() > 1 + first.size()) {
        first.push(second.top());
        second.pop();
    }

}

double findMedian() {
    // Even array, if empty return 0 else return middle elements avg
    if(first.size() == second.size()) {
        return first.empty() ? 0 : ((first.top() + second.top())/2.0);
    } else {
        // Odd array, return the bigger heap as it has the extra element in the middle
        return first.size() > second.size() ? first.top() : second.top();
    }
}

};
// Time complexity should be O(Nlogn)



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