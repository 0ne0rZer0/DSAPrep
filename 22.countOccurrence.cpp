/*
Count the number of occurrences in a sorted array
Given a sorted array arr[] and a number x, 
write a function that counts the occurrences of x in arr[]. 
Expected time complexity is O(Logn)
*/

/*
Approach 2 (Count occurrences O(N)):
loop till you find the first and last occurrence of the number and return difference

Approach 1 (Best):
Binary Search Two passes : O(logn)
Space : O(1)
Find left most occurrence, right most occurrence and return the difference + 1
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

int firstOccurrenceRecursive(vector<int>& arr, int x, int start, int end) {
    if(end >= start) {
        int mid = start + (end - start)/2;
        if((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        else if(x > arr[mid])
            return firstOccurrenceRecursive(arr,x,mid+1,end);
        else 
            return firstOccurrenceRecursive(arr,x,start,mid-1);
    }
    return -1;
}
int firstOccurrence(vector<int>& arr, int x)  {
    int start = 0;
    int end = arr.size()-1;
    while(start <= end) {
            int mid = start + (end-start)/2;
            if((mid == 0 || x > arr[mid-1]) && arr[mid] == x) return mid;
            else if(x > arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
    }
    return -1;

}
int lastOccurrenceRecursive(vector<int>& arr, int x, int start, int end) {
    if(start <= end) {
        int mid = start + (end-start)/2;
        if((mid == arr.size()-1 || x < arr[mid+1]) && arr[mid] == x) {
            return mid;
        } else if(x < arr[mid]) {
            return lastOccurrenceRecursive(arr, x, start, (mid-1));
        } else {
            return lastOccurrenceRecursive(arr, x, mid+1, end);
        }
    }
    return -1;
}
int lastOccurrence(vector<int>& arr, int x) {
    int start = 0;
    int end = arr.size()-1;
    int n = end+1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if((mid == n-1 || x < arr[mid+1]) && arr[mid] == x) {
            return mid;
        } else if(x < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;
}
int countOccurrences(vector<int>& arr, int x) {
    int first = firstOccurrence(arr, x);
    if(first == -1)
        return 0;
    int last = lastOccurrence(arr, x);
    return last - first + 1;
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
    int x;
    cin >> x;
    cout << countOccurrences(arr, x);
    return 0;
}