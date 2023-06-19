// Prim's MST

// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?leftPanelTab=0

//Pick non visited minimum value
//Now updated in the mst that it's visited
//Now check it's adj neighbour and if they not visited and their weight is < key weight then update parent and weight
//In the end return parent list,key list and node in the form of vector and pair


//TC=O(n^2);
//Using priority queue(min heap) we can do TC near to O(N*log(N)),insertion and deletion ka liya TC O(log(n)) hain but min value access karna
//ka liya TC O(1) hogi 
//SC=O(V+E);

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;

        int w=g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1,INT_MAX);//graph weight,we are showing index with nodes so started from 1
    vector<bool>mst(n+1,false);//to track which is already visited
    vector<int>parent(n+1,-1);

    //let's start the algo
    key[1]=0;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        //find the min wali node
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];//this update will help to keep minimum value
            }
        }

        //mark mini as true

        mst[u]=true;

        //check it's adjacent nodes
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;

            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;

            }
        }
    }
    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <=n; i++) {//here we are starting from 2 because parent of 1 is -1
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return result;


}































