// AA LAB:03
// CE128-Varija Shah

// Write a  program to  find the Max flow from the given flow network using Ford-Fulkerson algorithm

#include <iostream>
#include<queue>
#include<string.h>
#include<limits.h>

using namespace std;
#define n 6

bool bfs(int rGraph[n][n], int s, int t, int parent[])
{
   
	bool visited[n];
	memset(visited, 0, sizeof(visited));
 

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
 
	// standard bfs only with addition of condition rGraph[u][v] to stop when bottleneck capacity is zero ie. path is blocked
	while (!q.empty()) {
    	int u = q.front();
    	q.pop();
 
    	for (int v = 0; v < n; v++) {
        	if (visited[v] == false && rGraph[u][v] > 0) {
       	 
            	if (v == t) {
                	parent[v] = u;
                	return true;
            	}
            	q.push(v);
            	parent[v] = u;
            	visited[v] = true;
        	}
    	}
	}
}

int fordFulkerson(int graph[n][n], int s, int t)
{
	int u, v;
 
	// creating residual graph by copying the original one
	int rGraph[n][n];
	for (u = 0; u < n; u++)
    	for (v = 0; v < n; v++)
        	rGraph[u][v] = graph[u][v];
 
	int parent[n];
	int max_flow = 0;
 	// finding augmenting path by finding parent using bfs
 	// could use dfs but it has space complexity problem
	while (bfs(rGraph, s, t, parent)) {
 
    	int path_flow = INT_MAX;
    	for (v = t; v != s; v = parent[v]) {
        	u = parent[v];
        	path_flow = min(path_flow, rGraph[u][v]);
    	}
 
    	// updating graph
    	for (v = t; v != s; v = parent[v]) {
        	u = parent[v];
        	rGraph[u][v] -= path_flow;
        	rGraph[v][u] += path_flow;
    	}
 
 	max_flow += path_flow;
	}
 

	return max_flow;
}

int main() {
   int G[n][n]={ {0,16,13,0,0,0},
             	{0,0,10,12,0,0},
             	{0,4,0,0,14,0},
             	{0,0,9,0,0,20},
             	{0,0,0,7,0,4},
             	{0,0,0,0,0,0}
            	};
 	cout << "Maximum Flow is:" << fordFulkerson(G,0,5);

	return 0;
}
