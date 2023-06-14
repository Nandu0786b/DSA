// dfs Depth-First Search
//phale gharai ma search kar ka avo

// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1

void dfs(int node,unordered_map<int,bool>&visited,
unordered_map<int,list<int>> &adjlist,vector<int> &component){
    component.push_back(node);
    visited[node]=true;

    //we will call recursively call for the every node

    for(auto i:adjlist[node]){
        if(!visited[i]){
            dfs(i,visited,adjlist,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int n, int E, vector<vector<int>> &edges)
{
    // create adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<vector<int>>ans;
    unordered_map<int,bool>visited;

    for(int i=0;i<n;i++){//This for loop is running if there is any dis connected node in the graph
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }
    return ans;

}
// DFS (Depth-First Search) is a graph traversal algorithm that explores all the vertices of a graph by going as deep as possible before backtracking. It starts at a given source vertex, visits one of its neighbors, and recursively explores further until there are no more unvisited neighbors. If there are no more unvisited neighbors, it backtracks to the previous vertex and explores another unvisited neighbor until all vertices are visited.


0 --- 1 --- 4
|\    |   / |
| \   |  /  |
|  \  | /   |
|   \ |/    |
2 --- 3     5


BFS traversal starting from vertex 0: 0 1 2 4 3 5

DFS traversal starting from vertex 0: 0 1 4 3 2 5