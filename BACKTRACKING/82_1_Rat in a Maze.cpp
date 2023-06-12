// Rat in a Maze
// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1


// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_758966  => solve this question during the revision
//TC=4^(n*n),SC=o(n*n)
#include <bits/stdc++.h> 
bool isSafe(int newx,int newy,vector<vector<bool>> &visited,vector < vector < int >> & arr,int n){
    if((newx>=0 && newx<n ) && (newy>=0 && newy<n ) && visited[newx][newy]==0 && arr[newx][newy]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string>&ans,
vector<vector<bool>> visited,string path ){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    //4 movement
    //D, L, R, U
    visited[x][y]=1;
    //Down movement
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path+"D");
    }

    //left movement
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x,y-1,arr,n,ans,visited,path+"L");
    }
    
    //RIGHT movement
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path+"R");
    }
    
    //UP movement
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path+"U");
    }
    // visited[x][y]=0;


}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    if(arr[0][0]==0)
        return ans;
    string path="";

    solve(0,0,arr,n,ans,visited,path);

    return ans;
}