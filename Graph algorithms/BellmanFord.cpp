// Bellman Ford algorithm to find single source shortest path to all other vertices
// It is also used to detect negative weight cycle in a graph
#include<iostream>
using namespace std;

typedef struct Edge{
	int src;
	int dest;
	int weight;
}Edge;
typedef struct Graph{
	int v,e;
	Edge * edge;
}Graph;
Graph * createGraph(int V,int E){
	Graph *graph=new Graph;
	graph->v=V;
	graph->e=E;
	graph->edge=new Edge[E];
	return graph;
}
int Bellman(Graph *G,int src){
	int V=G->v;
	int E=G->e;
	int i;
	int d[V];
	for(i=0;i<V;i++) d[i]=INT_MAX;
	d[src]=0;
	for(i=0;i<V-1;i++){
		for(int j=0;j<E;j++){
			int u=G->edge[j].src;
			int v=G->edge[j].dest;
			if(d[u]!=INT_MAX && d[v]>d[u]+G->edge[j].weight){
				d[v]=d[u]+G->edge[j].weight;
			}
		}
	}
	for(i=0;i<E;i++){
		int u=G->edge[i].src;
		int v=G->edge[i].dest;
		if(d[u]!=INT_MAX && d[v]>d[u]+G->edge[i].weight){
			cout<<"Graph contains negative weight cycle .";
			return 1;
		}
	}
	cout<<"Vertex		Distance from Source vertex"<<endl;
	for(i=0;i<V;i++){
		cout<<i<<"			"<<d[i]<<endl;
	}
	return 0;
}
int main(){
	int i;
	int v=5,e=8;
//	cout<<"Enter total vertices in graph :";
//	cin>>v;
//	cout<<"Enter total edges in graph :";
//	cin>>e;
	Graph *graph=createGraph(v,e);
	 // add edge 0-1 (or A-B in above figure) 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    Bellman(graph, 0); 
	
	return 0;
}
