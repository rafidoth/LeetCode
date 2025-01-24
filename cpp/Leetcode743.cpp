#include<bits/stdc++.h>
using namespace std;



/*
 
743 Network delay Time
------------------------

n nodes given 
leveled from 1 to n
times[] : travel times
  times[i] = (u,v,w) a directed edge
    u -> source 
    v -> target 
    w -> weight
*/



class Solution {
public:
    struct DisjointSet{
      vector<int> parent, rank;
      int vertexCount;

      DisjointSet(int n){
        parent.resize(n,0); 
        rank.resize(n,0);
        for(int i =0; i<n; i++){
          parent[i] = i;
        }
      }
      
      int findParent(int vertex){
        if(parent[vertex] == vertex)
          return vertex;

        return parent[vertex] = findParent(parent[vertex]);
      }


      void unionSet(int x, int y){
        int parentX = findParent(x);
        int parentY = findParent(y);


        if(parentX != parentY){
          if(rank[parentX] < rank[parentY])
            swap(parentX, parentY); 
          parent[parentY] = parentX;
          if(rank[parentX]== rank[parentY])
            rank[parentX] += 1;
        }
      }
      
      bool existCycle(int x, int y){
        return findParent(x) == findParent(y);
      }
    };
  
    bool cmp(vector<int> a, vector<int> b){
      return a[2] < b[2];
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      sort(times.begin(), times.end(), cmp);       
      for(int i =0; i< (int)times.size(); i++){
        cout << times[2] << endl;
      }
    }
};

int main(){
     
}
