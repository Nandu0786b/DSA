// Prim's MST

// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?leftPanelTab=0

//Pick non visited minimum value
//Now updated in the mst that it's visited
//Now check it's adj neighbour and if they not visited and their weight is < key weight then update parent and weight
//In the end return parent list,key list and node in the form of vector and pair


//TC= O(N*log(N))
//SC=O(V+E);

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX); // Graph weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> haji;
    vector<bool> mst(n + 1, false); // To track which nodes are already visited
    vector<int> parent(n + 1, -1);

    // Let's start the algorithm
    haji.push(make_pair(0, 1)); // First is weight and second is node number
    key[1] = 0; // Starting from node 1
    while (!haji.empty()) {
        // Find the node with minimum weight
        pair<int, int> p = haji.top();//TC O(1)
        int mini = p.first;
        int u = p.second;
        haji.pop();

        // Mark the node as visited
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                haji.push(make_pair(w, v));
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return result;
}