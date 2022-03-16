#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> getBfs(int v, vector<int> adj[]){
	vector<int> bfs;
	vector<int> vis(v+1,0); // Mark all the vertices as not visited

	//We run the following for loop to cover all components of a graph incase it is a disconnected graph with multiple components
	for(int i=1;i<=v;i++){
		if(!vis[i]){
			queue<int> q; // Create a queue for BFS
			q.push(i); 
			vis[i]=1; // Mark the current node as visited and enqueue it
			while(!q.empty()){
				int node=q.front(); 
				q.pop();
				bfs.push_back(node); // Dequeue a vertex from queue and add it to bfs vector to be printed later
				// Get all adjacent vertices of the dequeued vertex 
                // If a adjacent has not been visited, then mark it visited and enqueue it
				for(auto n: adj[node]){
					if(!vis[n]){
						q.push(n);
						vis[n]=1;
					}
				}
			}
		}
	}
	return bfs;
}
int main()
{
	int n,m; //n is the number of nodes/vertices and m is the number of edges
	cin>>n>>m;
	vector<int> adj[n+1]; //Considering the nodes to be indexed from 1 to n
	for(int i=0;i<m;i++){
		int u,v; //Ends of the edge
		cin>>u>>v; 
		adj[u].push_back(v);
		adj[v].push_back(u); // Considering the graph is unidirected, the node should be added to adjacency list of both end nodes of the edge
	}
	vector<int> bfs=getBfs(n,adj);
	for(int i=0;i<bfs.size();i++){
		cout<<bfs[i]<<" ";
	}
	cout<<endl;
	return 0;
}

// Time Complexity: O(V+E) where V is the time taken to visit all nodes of the graph and E is the time taken to travel through all the adjacent nodes in the graph. 
// Space complexity: O(V)+O(V)~O(V), space taken by visited array and queue