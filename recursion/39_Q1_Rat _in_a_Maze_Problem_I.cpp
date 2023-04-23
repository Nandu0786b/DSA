// Rat in a Maze Problem - I
// MediumAccuracy: 35.75%Submissions: 173K+Points: 4



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> m){
        if ((x<n && x>=0) && (y<n && y>=0) && visited[x][y]==0 && m[x][y]==1) return true;
        return false;
    }
    void solve(vector<vector<int>> m,int n,int x ,int y,vector<string>& ans,vector<vector<int>> visited,string path){
        if (x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        if (issafe(x+1,y,n,visited,m)){
            path.push_back('D');
            solve(m,n,x+1,y,ans,visited,path);
            path.pop_back();
            
        }
        if (issafe(x,y-1,n,visited,m)){
            path.push_back('L');
            solve(m,n,x,y-1,ans,visited,path);
            path.pop_back();
            
        }
        if (issafe(x-1,y,n,visited,m)){
            path.push_back('U');
            solve(m,n,x-1,y,ans,visited,path);
            path.pop_back();
            
        }
        if (issafe(x,y+1,n,visited,m)){
            path.push_back('R');
            solve(m,n,x,y+1,ans,visited,path);
            path.pop_back();
            
        }
        
        
        
        
        
        // visited[x][y]=1; //without this is also running so we don't required this
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        int x=0;
        int y=0;
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        string path ="";
        solve(m,n,x,y,ans,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends







































// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1