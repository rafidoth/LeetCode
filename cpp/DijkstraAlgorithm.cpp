#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


struct Edge{
  int node; 
  int weight;

  bool operator<(Edge const& other) const {
    return weight > other.weight;
  }
};

void findPath(int source, int dest, vector<int> parent, vector<int>& path){
  if(dest == source || parent[dest] == -1){
    path.push_back(dest);
    return;
  }

  findPath(source, parent[dest], parent, path);
  path.push_back(dest);
}

void dijkstra(int source, int dest, vector<vector<Edge>> G, int n){
  vector<int> dist(n, INT_MAX);
  vector<int> parent(n,-1);
  dist[source] = 0;

  priority_queue<Edge> pq;
  pq.push({source, 0});

  while(!pq.empty()){
    Edge curr = pq.top();
    pq.pop();

    int u = curr.node;
    int currDist = curr.weight;
    if(currDist >  dist[u]) continue;


    for(auto& neighbour : G[u]){
      int v = neighbour.node;
      int wt = neighbour.weight;
      if(dist[v] > dist[u] + wt){
        dist[v] = dist[u]+wt;
        pq.push({v,dist[v]});
        parent[v] = u;
      }
    }
  }
  
  /*vector<int> pathContainer;*/
  /*findPath(source, dest, parent, pathContainer);*/
  /*for(int x : pathContainer) cout << x << " ";*/
  /*cout << endl;*/
  cout  << "shortest path dist : "<< dist[dest] << endl;
}





int main(){
    freopen("GraphInput.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    for(int i =0; i<E; i++){
      int u,v,w;
      cin >> u >> v >> w;
      graph[u].push_back({v,w});
    }
     
    dijkstra(0,2,graph, V );

}
