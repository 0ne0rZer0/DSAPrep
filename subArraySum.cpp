#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

vector<vector<int>> createSumArray(vector<vector<int>>& arr) {
  int row = arr.size();
  int col = arr[0].size();
  vector<vector<int>> sumArray(row, vector<int>(col, 0));
  for(int i = 1; i < col; i++) {
    sumArray[0][i] += sumArray[0][i-1]; 
  }
  for(int i = 1; i < row; i++) {
    sumArray[i][0] += sumArray[i-1][0];
  }
  for(int i = 1; i < row; i++) {
    for(int j = 1; j < col; j++) {
      sumArray[i][j] += sumArray[i-1][j];    
    }
  }
  for(int i = 1; i < row; i++) {
    for(int j = 1; j < col; j++) {
      sumArray[i][j] += sumArray[i][j-1];   
    }
  }
  return sumArray;
}

double subArrayAverage(vector<vector<int>>& arr, int x1, int y1, int x2, int y2) {
  int row = arr.size();
  if(row == 0) return 0;
  int col = arr[0].size();
  if(col == 0) return 0;
  vector<vector<int>> sumArray = createSumArray(arr);
  // Add subtracted twice subarray
  long long sum = sumArray[x2][y2] - sumArray[x1-1][y2] - sumArray[x2][y1-1] + sumArray[x1-1][y1-1];
  int numberOfElements = (x2-x1+1) * (y2-y1+1);
  // Check for divide by zero
  if(numberOfElements == 0) return 0;
  return (sum/numberOfElements);
}

int main() {
    vector<vector<int>> arr(4,vector<int>(4,0));
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        cin >> arr[i][j];
      }
    }
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << subArrayAverage(arr, x1, y1, x2, y2);
    return 0;
}