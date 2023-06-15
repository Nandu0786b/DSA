// Cycle Detection In Undirected Graph
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0

//we will traverse same as the bfs 
//but to detect cycle we have to track the parent 
//if node is already visited and it's not a parent of the current node it means there is one cycle is present

//TC is same as the BFS

#include<unordered_map>
#include<queue>
#include<list>
bool isCycleBFS(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> 
&visited){
    unordered_map<int,int>parent;
    parent[node]=-1;
    visited[node]=true;
    queue<int> track;
    track.push(node);

    while(!track.empty()){
        int front=track.front();
        track.pop();

        for(auto neighbour:adjList[front]){
            if(visited[neighbour] && neighbour !=parent[front]){//case when node is already visited and not a parent
                return true;//case when cycle found
            }
            else if(!visited[neighbour]){
                track.push(neighbour);
                parent[neighbour]=front;
                visited[neighbour]=true;
            }

        }
    }
    return false;//all visited but cycle not detected

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
    for(int i=0;i<n;i++){//agar connected hain tho phale node sa sara ka sara visit ho jayenga but connected nahi hain tho yaha sa baki disconnected garph ka liya bhi call jayegi
        if(!visited[i]){
            bool ans=isCycleBFS(i,adjList,visited);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";//till end cycle not found
}
