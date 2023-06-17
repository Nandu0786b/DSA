// Shortest Path in the Directed Acyclic Graph

//approach: First Do the Topological Sort
//after this cretae an array, size of the number of Node in starting all values will be intmax, and set source Node as zero
//Now Start  to pop data  from the stack
//if poped index from the stack in the array index is INT_MAX then ignore this but if  Not then start to extract it's neighbour and update min(old,weight from the current data)
//this array will give sortest path for the all nodes in the array for the source Node

// Online C++ compiler to run C++ program online

//TC=O(N+E),SC=O(N+E)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
  public:
  unordered_map<int,list<pair<int,int>>>adjList;
  
  void addEdge(int u, int v, int weight){
      pair<int,int> p=make_pair(v,weight);
      adjList[u].push_back(p);
  }
  
  void PrintAdj(){
      for(auto i:adjList){
          cout<<i.first<<" connected to : ";
          for(auto j:i.second){
              cout<<"("<<j.first<<" , "<<j.second<<")";
          }
          cout<<endl;
      }
  }
  void dfs(int node,unordered_map<int,bool>&visited,stack<int>&topo){
      visited[node]=true;
      for(auto neighbour:adjList[node]){
          if(!visited[neighbour.first]){
          dfs(neighbour.first, visited, topo);
          }
      }
      topo.push(node);
  }
  void getSortestPath(int src, vector<int> &dist, stack<int> &topo){
    dist[src]=0;
    while(!topo.empty()){
        int top =topo.top();
        topo.pop();
        
        if(dist[top]!=INT_MAX){
            for(auto neighbour:adjList[top]){
                if(dist[neighbour.first]>(neighbour.second+dist[top])){
                    dist[neighbour.first]=(neighbour.second+dist[top]);
                }
            }
        }
    }
  }
};
int main() {
    // Write C++ code here
    cout << "Hello world!";

    Graph g;

    cout<<endl;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.PrintAdj();
    
    //topological sort
    int n=6;//number of the node
    unordered_map<int,bool>visited;
    stack<int> topo;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,topo);
        }
    }
    int src=1;//source element where from we will calculate the minimum distance for the all element
    vector<int>dist(n,INT_MAX);
    g.getSortestPath(src,dist,topo);
    cout<<"answer is :";
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
    
}