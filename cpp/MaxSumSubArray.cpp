#include<bits/stdc++.h>
using namespace std;


int maxCrossSum (vector<int>& arr, int left, int mid, int right){
  int leftMax = INT_MIN;
  int leftSum = 0;
  for(int i = mid; i>= left; i--){
    leftSum += arr[i];
    leftMax = max(leftMax, leftSum);
  }

  int rightMax = INT_MIN;
  int rightSum = 0;
  for(int i = mid+1; i<= right; i++){
    rightSum += arr[i];
    rightMax = max(rightMax, rightSum);
  }
  return leftMax + rightMax;
}




int maxsumSubarray(vector<int>& arr, int left, int right){
  if(left == right){
    return arr[left];
  }
  int mid = (left + right)/2;
  int leftSum = maxsumSubarray(arr, left, mid);
  int rightSum = maxsumSubarray(arr, mid+1, right);
  int crossSum = maxCrossSum(arr, left, mid, right);
  return max({leftSum, rightSum, crossSum});
}


int main(){
  vector<int> arr = {2, -3, -4, 5, -7};
  cout << maxsumSubarray(arr, 0, arr.size()-1) << endl;
}
