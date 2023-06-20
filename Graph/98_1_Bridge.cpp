// Bridge

// https://www.codingninjas.com/studio/problems/bridges-in-graph_893026?leftPanelTab=1

//We will use four data structer for this question.
//one to track visited, to track parent,
// to track discovery time, to track earliest possible time
//if there is any cycle present then it's called backEdge and we also can reach there before the time so we will update min of earliest time of node and discovery time of the neighbour
//back Edge=>on which next node is already visited it meaans there is cycle is present
//if neighbour is parent then ignore it
//if earliest time of node > discovery time of neighbour it means this is a bridge
//because this node is reachable only from the one node and if we disconnect this then this will create new graph
//but if any path exist to reach this then above condition will not fullfil


#include<bits/stdc++.h>
void dfs(int node,int parent,int timer,vector<int>&disc,vector<int>&low,vector<vector<int>>
 &result,unordered_map<int,list<int>> &adj,unordered_map<int, bool> &vis){
    vis[node]=true;

    disc[node]=low[node]=timer++;

    for(auto neighbour:adj[node]){
    if(neighbour==parent){
    continue;
    }
    if(!vis[neighbour]){
        //do the continue call for the dfs
        dfs(neighbour,node,timer,disc,low,result,adj,vis);
        low[node]=min(low[node],low[neighbour]);//may be your child find as back edge
        if(low[neighbour]>disc[node]){
            vector<int> ans;
            ans.push_back(node);
            ans.push_back(neighbour);
            result.push_back(ans);
        }
    } else {
    // back edge
    low[node]=min(low[node],disc[neighbour]);
    }
    }

 }
vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int e) {
    // adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    //data strcture which we need
    int timer=0;
    vector<int>disc(n,-1);
    vector<int>low(n,-1);
    int parent=-1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < n; ++i) {
        vis[i] = false; // Initialize all values to false
    }

    //start the dfs
    
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }



    return result;

}

