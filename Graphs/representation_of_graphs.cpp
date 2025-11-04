#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    // approach 1; adjacency matrix; 
    vector<vector<int>> adj(n+1,vector<int>(n+1,0)); // Space ---> O(n*n)

    for(int i= 0;i<m;i++){      
        int u,v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // approach 2; adjacency list
    vector<vector<int>> adjlist(n+1);   // Space ---> O(2*m)

    int u,v;
    for(int i =0;i<m;i++){
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    

return 0;
}