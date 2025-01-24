#include<bits/stdc++.h>
using namespace std;

struct Activity{
  int start;
  int finish;
};

bool cmpFn(Activity a, Activity b){
  return a.finish < b.finish;
}

int getMaxActivity(vector<Activity>& arr){
  int n = arr.size();
  sort(arr.begin(), arr.end(), cmpFn);
  int prevSelected = -1;
  int count = 0;
  vector<Activity> selected;
  for(Activity x : arr){
    if(x.start > prevSelected){
      prevSelected = x.finish;
      count++;
      selected.push_back(x);
    }
  }
  for(Activity x : selected){
    cout << x.start << " " << x.finish << endl;
  }
  return count ;
}

int main(){
  vector<Activity> arr =  { 
      { 5, 9 }, 
      { 1, 2 }, 
      { 3, 4 },
      { 0, 6 }, 
      { 5, 7 }, 
      { 8, 9 } 
    };
  cout << getMaxActivity(arr) << endl;
}
