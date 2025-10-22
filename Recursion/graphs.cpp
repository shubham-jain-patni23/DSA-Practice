#include<iostream>
#include<string>
#include<stack> 
#include<vector>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>> adj(n,vector<int>(n));

    int x, y;
    for(int i =0 ;i<m;i++){             
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    vector<vector<int>> adjlist(n);

    for(int i = 0;i<m;i++){
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    

return 0;
}