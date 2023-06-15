// Detect Cycle In A Directed Graph
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

//almost same as the previous cycle detection but here we are also using the extra data strcture to detect cycle in 
//if the visited is true in dfs and this is also in the call stack it means there is cycle present in the graph because 
//it comes again on the same node which is already in the dfs recursion call stack


//TC is the same as dfs

#include<bits/stdc++.h> //after including this we are not require to include all data strctue 
bool cycleDfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool>
&dfscall){
  visited[node]=true;
  dfscall[node]=true;//to track call in the call stack
  for(auto neighbour:adjList[node]){
    if(!visited[neighbour]){
      if(cycleDfs(neighbour,adjList,visited,dfscall )){
        return true;
      }
         }
    else if(visited[neighbour] && dfscall[neighbour]){
      return true;
    }
  }
  dfscall[node]=false;//back tracking
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adjList;
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsCall;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjList[u].push_back(v);//here we are pushing only u because this is the directed graph

  }
  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(cycleDfs(i,adjList,visited,dfsCall )){
        return true;
      }
    }
  }
  return false;
}

