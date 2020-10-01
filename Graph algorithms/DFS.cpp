#include<iostream>
#include<list>
using namespace std;

class Graph{
 int v;
 list<int> * adj;
 public:
  Graph(int);
  void addEdge(int,int);
  void dfsUtil(int ,bool *);
  void dfs(int);
};

Graph::Graph(int val){
 this->v=val;
 adj=new list<int>[v];
}
void Graph:: addEdge(int u,int v){
 adj[u].push_back(v);
}
void Graph:: dfsUtil(int v,bool * visited){
 cout<<v<<" ";
 visited[v]=true;
 list<int>:: iterator i;
 for(i=adj[v].begin();i!=adj[v].end();i++){
  if(visited[*i]==false)
   dfsUtil(*i,visited);
 }
}
void Graph:: dfs(int v){
 bool visited[v];
 for(int i=0;i<v;i++) visited[i]=false;
 dfsUtil(v,visited);
 return;
}
int main(){
 int n,e,i,u,v;
 cout<<"Enter total nodes in graph :";
 cin>>n;
 Graph g(n);
 cout<<"Enter total edges :";
 cin>>e;
 for(i=0;i<e;i++){
  cin>>u>>v;
  g.addEdge(u,v);
 }
 int s;
 cout<<"Enter starting vertex :" ;
 cin>>s;
 cout<<"Dfs traversal of graph is :";
 g.dfs(s);
 return 0;
} 
