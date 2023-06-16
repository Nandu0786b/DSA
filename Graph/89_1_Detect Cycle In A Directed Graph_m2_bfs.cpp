// Detect Cycle In A Directed Graph
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626


//TLE for this question as bfs

//but approach is amazing
//we are counting the number of inorder for the every node
//and we will calculate the total number 

#include<bits/stdc++.h>
bool cyclebfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited){
    unordered_map<int,bool> parentdrill;
    parentdrill[node]=true;
    visited[node]=true;
    queue<int>track;
    track.push(node);
    while(!track.empty()){
        int front=track.front();
        track.pop();
        for(auto neighbour:adjList[front]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                parentdrill[neighbour]=true;
                track.push(neighbour);
            } else if (visited[neighbour] && parentdrill[neighbour]) {
              return true;
            }
        }
        
    }
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adjList;
  unordered_map<int,bool> visited;
  
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjList[u].push_back(v);//here we are pushing only u because this is the directed graph

  }
  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(cyclebfs(i,adjList,visited)){
        return true;
      }
    }
  }
  return false;
}