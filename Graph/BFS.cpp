// Breadth first search (BFS)
//In this we will traverse adj Node first

//we need a map to track the visited nodes
//we will store nodes in queue so we can traverse levelvise
//we will do till queue not become empty
//TC=o(N+E),SC=o(N+E)

#include <bits/stdc++.h> 
void prepareAdjlist(vector<pair<int, int>> edges,unordered_map<int,set<int>> &adjList){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);


    }
}

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int>&ans
,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int front=q.front();
        q.pop();

        //store front node in the ans
        ans.push_back(front);

        //traverse all neighbours of frontnode

        for(auto i:adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
        
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{   
    unordered_map<int,set<int>> adjList;//We are using here set to return answer in the sorted manner
    vector<int>ans;
    unordered_map<int,bool> visited;

    prepareAdjlist(edges,adjList);

    //Traverse all componenet of the graph

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;

}



























// BFS (Breadth-First Search) is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order. It starts at a given source vertex, visits all its neighbors, then visits the neighbors' neighbors, and so on. BFS visits vertices in levels, where the vertices at the same level are visited before moving to the next level.

// g.addEdge(0, 1);
// g.addEdge(0, 2);
// g.addEdge(1, 2);
// g.addEdge(2, 0);
// g.addEdge(2, 3);
// g.addEdge(3, 3);



// BFS traversal starting from vertex 2: 2 0 3 1

