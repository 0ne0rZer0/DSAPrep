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

// https://leetcode.com/problems/house-robber/
// brute top down
// int Fun(vector<int>& nums,int index){
//     if(index>=nums.size())return 0;
//     return max(nums[index]+Fun(nums,index+2),Fun(nums,index+1));
//     }
// int rob(vector<int>& nums) {
//     return Fun(nums,0);
// }

// Top down memoization
// int DP(vector<int>& nums,int index,vector<int>&dp){
//     if(index>=nums.size())return 0;
//     if(dp[index]!=-1)return dp[index];
//     return dp[index] = max(nums[index]+DP(nums,index+2,dp),DP(nums,index+1,dp));
// }
// int rob(vector<int>& nums) {
//     vector<int>dp(nums.size()+1,-1);
//     return DP(nums,0,dp);
// }

// Bottom up 
// int rob(vector<int>& nums) {
//     if (nums.empty()) return 0;
//     if (nums.size() == 1) return nums[0];

//     vector<int> dp[nums.size()];
//     dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
//     for (int i=2; i<nums.size(); i++)
//         dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
//     return dp[nums.size()-1];
// }

int rob(vector<int>& nums) { 
        // prev= n -2, curr = n-1, next = n
        int prev = 0;
        int curr = nums[0];
        int next = 0;
        for(int i = 1; i < nums.size(); i++) {
            next = max(curr, prev + nums[i]);
            prev = curr;
            curr = next;
        }
        return curr;
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
    return 0;
}