#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& A) {
        unordered_map<int, int> count;
        unordered_map<int, int> index;
        //Frequency
        for (int a: A)
            count[a]++;
    
        // First occurrence
        for(int i = 0; i < A.size(); i++) {
            if(index.find(A[i]) == index.end()) {
                index[A[i]] = i;
            }
        }
    
        sort(begin(A), end(A), [&](int a, int b) {
            return count[a] == count[b] ? index[a] < index[b] : count[a] > count[b];
        });
    
        return A;
    }

};
    