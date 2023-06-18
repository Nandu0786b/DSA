// Dijkstra's shortest path

// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

//approach: first creat adjList
//create a set and a vector
//in vector set all nodes to INT_MAX and source node to the zero
//set will store pair in which first is weight and second is node
//in stack push the source node and it's weight will be zero
//Now run a while loop till set is not empty(set top will will return min value)
//Now remove top value and check it's neighbour if it's weight and neighbor distance is less then the previous distance then update new distance 
//and push this node in set with the updated distance and if same node is available in the set then remove max ditance node

//if we see then we asre storing the minimum values from the source node 

//TC=O(E*log(v)),E=edges,V=vertices

//SC=O(E+V)


#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // adjList
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adjList[u].push_back(make_pair(v,w));

        adjList[v].push_back(make_pair(u,w));
    }

    set<pair<int,int>> s;
    s.insert(make_pair(0,source));
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;

    while(!s.empty()){
        auto top=*(s.begin());//fetch top node
        int topn=top.second;
        int topd=top.first;
        s.erase(s.begin());//remove top node
        for(auto neighbour : adjList[topn]){
            if(dist[neighbour.first]>(neighbour.second+topd)){
                auto record=s.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record!=s.end()){//if record found then we have to delete the previous record
                    s.erase(record);
                }
                //insert in the stack
                s.insert(make_pair(neighbour.second+topd,neighbour.first));
                //distance update
                dist[neighbour.first]=neighbour.second+topd;
            }
        }
    }
    return dist;

}
