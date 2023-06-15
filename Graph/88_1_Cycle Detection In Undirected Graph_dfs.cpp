// Cycle Detection In Undirected Graph
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0

//we will traverse same as the dfs 
//but to detect cycle we have to track the parent 
//if node is already visited and it's not a parent of the current node it means there is one cycle is present


#include<unordered_map>
#include<queue>
#include<list>
bool isCycleDFS(int node,int parent,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> 
&visited){
    visited[node]=true;

    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
           bool cyccleDetect= isCycleDFS(neighbour,node,adjList,visited);
           if(cyccleDetect){
               return true;
           }
        }
        else if(visited[neighbour] && neighbour != parent){//it means cycle presnet hain
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    //create adj list
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    //we are running this for to handle disconnected fraph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCycleDFS(i,-1,adjList,visited);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";//till end cycle not found
}
