#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
 int v;
 list<int> * adj;
 public:
  Graph(int );
  void addEdge(int,int);
  void BfsUtil(int);
};

Graph:: Graph(int V){
 this->v=V;
 adj=new list<int>[V];
}
void Graph:: addEdge(int u,int v){
 adj[u].push_back(v);
}
void Graph:: BfsUtil(int v){
 list<int> q;
 bool * visited=new bool[this->v];
 for(int i=0;i<this->v;i++) visited[i]=false;
 visited[v]=true;
 q.push_back(v);
 while(!q.empty()){
  v=q.front();
  q.pop_front();
  cout<<v<<" ";
  list<int>::iterator i;
  for(i=adj[v].begin();i!=adj[v].end();i++){
   if(visited[*i]==false){
    visited[*i]=true;
    q.push_back(*i);
   }
  }
 }
}

int main(){
 int n,e,u,v,i;
 cout<<"Enter total nodes :";
 cin>>n;
 Graph g(n);
 cout<<"Enter total edges :";
 cin>>e;
 cout<<"Enter nodes :";
 for(i=0;i<e;i++){
  cin>>u>>v;
  g.addEdge(u,v);
 }
 g.BfsUtil(2);
 return 0;
}
