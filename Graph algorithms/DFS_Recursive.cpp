// Dfs traversal of a graph
// finding dfs of all disconnected graph
#include<iostream>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int);
		void addEdge(int ,int);
		void dfsUtil(int ,bool *);
		void DFS(int );
};
Graph:: Graph(int v){
	this->V=v;
	adj=new list<int>[v];
//	cout<<"Graph constructor called\n";
}
void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
} 
void Graph::dfsUtil(int v,bool *visited){
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(visited[*i]==false){
			dfsUtil(*i,visited);
		}
	}
}
void Graph::DFS(int n){
	int i;
	bool visited[V];
	for(i=0;i<n;i++){
		visited[i]=false;
	}
	dfsUtil(2,visited);
	
} 
int main(){
	int n,i,e,u,v;
	cout<<"Enter number of vertices :";
	cin>>n;
	Graph g(n);
	cout<<"Enter total number of edges :";
	cin>>e;
	cout<<"Enter edges :";
/*	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  */
	for(i=0;i<e;i++){
		cin>>u>>v;
		g.addEdge(u,v);
	}
	
	cout<<"Dfs traversal of above graph is : ";
	g.DFS(n);
	return 0;
}
