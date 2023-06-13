// Creating and Printing

// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551


#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    // vector<int>ans[n];// arrar of n vectors 
    vector<vector<int>> ans(n);//vector which contains n vector
    //array and vector from the both we can solve this question

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){//in this we are pushing the same
        adj[i].push_back(i);
        // cout<<i<<" ";

        for(int j=0;j<ans[i].size();j++){
            // cout<<ans[i][j]<<" ";
            adj[i].push_back(ans[i][j]);
        }
        // cout<<endl;
    }
    


    return adj;
}