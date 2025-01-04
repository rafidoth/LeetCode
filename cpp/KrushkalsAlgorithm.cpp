#include<bits/stdc++.h>
using namespace std;



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


struct Edge{
  int node1;
  int node2;
  int weight;
  bool operator<(Edge const& other){
    return weight < other.weight;
  }
};

void Krushkal(vector<Edge> edges, int n){
  sort(edges.begin(), edges.end());
  DisjointSet disjoint = DisjointSet(n);

  int cost = 0;
  vector<Edge> mst;

  for(Edge edge : edges){
    if(!disjoint.existCycle(edge.node1, edge.node2)){
      cost+= edge.weight;
      mst.push_back(edge);
      disjoint.unionSet(edge.node1, edge.node2);
    }
  }
  
  cout << "minimum cost " << cost << endl;
  cout << " MST " << endl;
  for(Edge edge : mst){
    cout << edge.node1 << " " << edge.node2 << endl;
  }

}


int main(){
  vector<Edge> edges;    
  edges = {
    {0,1,2},
    {0,2,1},
    {1,2,1},
    {2,4,2},
    {2,3,2},
    {3,4,1}
  };
  Krushkal(edges, 5);
}
