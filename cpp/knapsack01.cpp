#include<bits/stdc++.h>
using namespace std;

int main(){
  int k = 50;
  vector<int> w = {15,5,5,10,5,10,10};
  vector<int> v = {800, 200, 500, 300, 600, 700, 400};
  int n = w.size();
  vector<vector<int>> dp(n+1, vector<int>(k+1,0));
  for(int i = 0; i<= n; i++){
    for(int j = 0; j<=k;j++){
      if(i== 0 || j==0){
        dp[i][j] = 0;
      }else{
        if(w[i-1] <= j){
          dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
        }else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  cout << "result "<< dp[n][k] << endl;
}
