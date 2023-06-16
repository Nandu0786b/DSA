// Detect Cycle In A Directed Graph using bfs Khan's algo-rithm
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626
// https://leetcode.com/problems/course-schedule-ii/description/

// Same khan algorithm apply kiya hain bus is ma answer return karna ki bajay ya check kar liya ki number node which have 0 indgree if equal 
//to the number of node it means there is no cycle present else present
//insetead of count variable you can do one thing that traverse inorderdegree vector and if you find any node which is having degree greater then zero
//it means cycle is present and return true else when loop complete return false

//TC and SC is same as the bfs 

#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  //adajList
    unordered_map<int,list<int>> adjList;

    vector<int>indegree(n,0);//to track indegree, 0th index will tell about the indegree of the 0th index
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;//in this we are using -1 because our node is starting from the one insted of zero
        int v=edges[i].second-1;

        adjList[u].push_back(v);
        indegree[v]++;
    }

    //filter all the node which have 0 indegree
    queue<int>q;
    
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //do bfs
    int count=0;
    //now will not stop till our queue is become the empty
    while(!q.empty()){
        int front=q.front();
        q.pop();
        //increment the count
        count++;
        for(auto neighbour:adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(count==n){
      return false;
    }
    return true;
}




