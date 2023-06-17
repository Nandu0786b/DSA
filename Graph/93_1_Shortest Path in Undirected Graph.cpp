//Shortest Path in Undirected Graph

// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1

//approach: basically we are simply doing bfs, but we also storing parent details 
//Now in the bfs we see that it's a level wise traversal means same level will be travers at the same time
//Now target element will be come first in the shortest path and it's will be market as the true 
//and it's will store his parent details once it's market visited true after this if longest path come to here then also it's parent element will be same
//Now when we start to extract from the target element to it's parent then it's map and it's will return path
//we will stop our parent extraction work till out current not become the start point
//in the end we have to reverse the path because we need source to target path

//TC=O(n+e),TC=O(n+e)

//in this instead os shortest path question also can ask number of node between the source and the target node

#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	//Create adjlist
	unordered_map<int,list<int>> adjList;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);

	}
	
	//do bfs
	unordered_map<int,bool> visited;
	unordered_map<int,int>parent;
	parent[s]=-1;
	queue<int>q;
	q.push(s);
	visited[s]=true;

	while(!q.empty()){
		int front =q.front();
		q.pop();

		for( auto neighbour:adjList[front]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
	}

	//prepare shortest path

	vector<int> ans;
	int cur=t;
	ans.push_back(t);
	while(cur!=s){
		cur=parent[cur];
		ans.push_back(cur);

	}
	reverse(ans.begin(),ans.end());
	return ans;
}
