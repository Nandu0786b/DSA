//91
//topological sort using the khan's algorithm
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938?leftPanelTab=1

//we will use bfs for this question

//step first: find a all 0 in degree node and insert in to the queue 
//now remove that node from the queue one by one and reduce their neighbour degree by one. now if neigbour indegree is zero then push in the
//queue and go ahead else left

//if we find element in the end which having still degree more then zero then return -1 because there is cycle present and we can not give topological sort
//in this we are not require any visited map to track
//TC=O(v+e),SC=O(v+e)


#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    //adajList
    unordered_map<int,list<int>> adjList;

    vector<int>indegree(v,0);//to track indegree, 0th index will tell about the indegree of the 0th index
    
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        indegree[v]++;
    }

    //filter all the node which have 0 indegree
    queue<int>q;
    
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //do bfs
    vector<int>ans;
    //now will not stop till our queue is become the empty
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour:adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}




// Kahn's algorithm is a method used to find a topological ordering of vertices in a directed acyclic graph (DAG). A topological order is an ordering of the vertices such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. This algorithm is commonly used in scheduling, dependency resolution, and task ordering problems.

// Here's a high-level overview of Khan's algorithm:

// Initialize an empty list or queue, which will store the topologically sorted vertices.

// Compute the in-degree (the number of incoming edges) for each vertex in the graph.

// Enqueue all vertices with an in-degree of 0 into the list or queue.

// While the list or queue is not empty:

// Dequeue a vertex, let's call it "current."
// Add "current" to the topological ordering list.
// Reduce the in-degree of all adjacent vertices of "current" by 1.
// If any adjacent vertex's in-degree becomes 0, enqueue it.
// If the topological ordering list contains all the vertices of the graph, it represents a valid topological ordering. Otherwise, the graph contains a cycle, and a topological ordering is not possible.

// Kahn's algorithm guarantees to find a valid topological ordering if the graph is a directed acyclic graph (DAG). If there are multiple valid topological orderings, the algorithm can produce any of them.