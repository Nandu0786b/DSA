// Online C++ compiler to run C++ program online

// the adjacency list is stored in an unordered map, the space complexity is O(V + E), where V is the number of nodes and E is the number of edges in the graph.

// Creating the graph by adding edges takes O(m) time, where m is the number of edges.
// Printing the adjacency list takes O(V + E) time since we iterate over all nodes and their respective adjacency lists.


#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>

class graph{
  public:
    unordered_map<int,list<int>>adj;
    void adEdge(int u, int v, bool direction){
        //direction=0->uni direction, we have to create relation between the both u an v
        //if direction is one then we have to create link between the one u to v
        adj[u].push_back(v);
        if (direction==0){
            adj[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<" Is connected To THe :=> ";
            for(auto j:i.second ){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    // Write C++ code here
    cout << "Hello world!"<<endl;
    int n;
    cout<<"enter the Number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<endl<<"enter the Number of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        // bool direction;
        cin>>u;
        cin>>v;
        // cin>>direction;
        g.adEdge(u,v,0);

    }
    g.printadjlist();



    return 0;
}



//****************************************************************


#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " is connected to: ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "Hello world!" << endl;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;
}

