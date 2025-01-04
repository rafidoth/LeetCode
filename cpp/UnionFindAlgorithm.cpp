#include <bits/stdc++.h>
using namespace std;



struct UF{
  // This UF algorithm will take N^2 for all the N edges
  //  each edge union takes O(n)
  vector<int> id;
  int compCount; 

  UF(int n){ id.resize(n,0);
    compCount = n;
    for(int i = 0; i<n; i++)
      id[i] = i;
  }
  
  int count(){
    return compCount;
  }

  int find(int p){
    return id[p];
  }

  void u(int p, int q){
    int pId = id[p];
    int qId = id[q];
    if(pId == qId) return;
    for(int i = 0; i<(int)id.size(); i++)
      if(id[i] == pId) id[i] = qId;
    compCount--;
  }

  bool connected(int p, int q){
    return find(p)== find(q);
  }
  
  void display(){
    for(int i = 0; i<(int)id.size(); i++){
      cout << id[i] << ' ';
    }
    cout << endl;
  }

};


struct UF2{
  /*
   Actually it takes more time in some cases 
   to find the parent 
          suppose the tree becomes linear shaped
             1
              \ 
               4
                \
                 5
                  \
                   3
          in these type of cases to find parent we have to
          go in linear time here comes path compression where
          we'll keep saving the path while climbing to the 
          parent (UF3)
  */ 
  vector<int> id;
  int compCount; 

  UF2(int n){
    id.resize(n,0);
    compCount = n;
    for(int i = 0; i<n; i++)
      id[i] = i;
  }
  
  int count(){
    return compCount;
  }

  int find(int p){
    if(id[p]== p) return p;
    return find(id[p]);
  }

  void u(int p, int q){
    int parentP = find(p); 
    int parentQ = find(q);
    if(parentP == parentQ) return;
    id[parentQ] = parentP;
    compCount--;
  }

  bool connected(int p, int q){
    return find(p)== find(q);
  }
  
  void display(){
    for(int i = 0; i<(int)id.size(); i++){
      cout << id[i] << ' ';
    }
    cout << endl;
  }
};

struct UF3{
  /*
   * O(logn) wihtout proof
  
  for UF3 
  UF3 uf= UF2(8); 
  uf.u(1,2);
  uf.u(2,3);
  uf.u(4,5);
  uf.u(6,7);
  uf.u(5,6);
  uf.u(2,6);
  uf.display(); -> { 0 1 1 1 1 4 4 6 }
  
  here for 7 currently parent is 6
  since path compression aplied and now we do
  uf.find(7) -> it will take normal time 
  uf.display() -> { 0 1 1 1 1 4 1 1 } 
                  while finding 7's parent it updated 
                  actual parent of all the nodes in its
                  path and finally also updated own actual
                  parent.
  
  now if we want to know the parent of 6 then we 
  kinda getting it in constant time
  uf.find(6) -> 1

  */ 
  vector<int> id;
  int compCount; 

  UF3(int n){
    id.resize(n,0);
    compCount = n;
    for(int i = 0; i<n; i++)
      id[i] = i;
  }
  
  int count(){
    return compCount;
  }

  int find(int p){
    if(id[p]== p) return p;
    return id[p] = find(id[p]);
  }

  void u(int p, int q){
    int parentP = find(p); 
    int parentQ = find(q);
    if(parentP == parentQ) return;
    id[parentQ] = parentP;
    compCount--;
  }

  bool connected(int p, int q){
    return find(p)== find(q);
  }
  
  void display(){
    for(int i = 0; i<(int)id.size(); i++){
      cout << id[i] << ' ';
    }
    cout << endl;
  }
};

struct UF4{
  /*
   * Tree size as rank
   * smaller tree should be attached as child
   * to the bigger tree
  */ 
  vector<int> id;
  int compCount; 
  vector<int> treeSize;

  UF4(int n){
    id.resize(n,0);
    treeSize.resize(n,1);
    compCount = n;
    for(int i = 0; i<n; i++)
      id[i] = i;
  }
  
  int count(){
    return compCount;
  }

  int find(int p){
    if(id[p]== p) return p;
    return id[p] = find(id[p]);
  }

  void u(int p, int q){
    int parentP = find(p); 
    int parentQ = find(q);
    if(parentP == parentQ) return;
    
    if(treeSize[parentP] < treeSize[parentQ]){
      swap(parentP, parentQ);
    }

    id[parentQ] = parentP;
    treeSize[parentP] += treeSize[parentQ];
    compCount--;
  }

  bool connected(int p, int q){
    return find(p)== find(q);
  }
  
  void display(){
    for(int i = 0; i<(int)id.size(); i++){
      cout << id[i] << ' ';
    }
    cout << endl;
  }
};

int main(){
  UF3 uf= UF3(8); 
  uf.u(1,2);
  uf.u(2,3);
  uf.u(4,5);
  uf.u(6,7);
  uf.u(5,6);
  uf.u(2,6);
  uf.display();
  cout << uf.find(7) << endl;  
  uf.display();
}
