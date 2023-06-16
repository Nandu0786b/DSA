// Topological sort

//We can apply only in the directed acyclic graph(means directed graph but there is no cycle)
//Linear ordering of vertices such that for every edge u-v, u always appear before v in that ordering

//we can not apply in cyclic graph because there is many case come where like one edge is present between a->b now think that 
//one cycle is also present from b to a then it will violate the property of the topological sort

//by this we also can do one thing that if in the graph we are not able to find topological sort it means there is may be cycle present


//in this approach we will use a stack and will push data in the stack using the dfs traversal
//and we will push data into stack when we return from the recursion call because when we return from the recursion call and push data in the stack
//then it will help when we will pop data to push in the ans vector in that case u->v, u will come always before the v

//below and this code is almost same in this we are using vector instead of unordered map to track visited list
//in adjlist if we use vector then it will be take less time


#include <bits/stdc++.h> 
void toposort(int node,vector<int> &visited,stack<int>&topo,unordered_map<int,list<int>>&adjList)
{
    visited[node]=true;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            toposort(neighbour,visited,topo,adjList);
        }
    }
    topo.push(node);//apan isko jatha time stack ma push kar raha hain because we want that when
    //we pop from stack and push in the vector then u should come before the v
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //adajList
    unordered_map<int,list<int>> adjList;
    vector<int> visited(v,0);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
    }
    //dfs to do topological sort
    stack<int>topo;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,topo,adjList);
        }
    }
    vector<int>ans;
    while(!topo.empty()){
        ans.push_back(topo.top());
        topo.pop();
    }
    return ans;
}

//********************* TLE ************************************
// in this tle come solution is ok

#include <bits/stdc++.h> 
void toposort(int node,unordered_map<int,bool> &visited,stack<int>&topo,unordered_map<int,list<int>>&adjList)
{
    visited[node]=true;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            toposort(neighbour,visited,topo,adjList);
        }
    }
    topo.push(node);//apan isko jatha time stack ma push kar raha hain because we want that when
    //we pop from stack and push in the vector then u should come before the v
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //adajList
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
    }
    //dfs to do topological sort
    stack<int>topo;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,topo,adjList);
        }
    }
    vector<int>ans;
    while(!topo.empty()){
        ans.push_back(topo.top());
        topo.pop();
    }
    return ans;
}

