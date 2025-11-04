#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void bfs(int src,vector<vector<int>>&adj,vector<int> &vis){
        
    vis[src] = 0;
    queue<int>q;
    q.push(src);
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        
        for(auto it : adj[idx]){
            if(vis[it]==-1){
                vis[it] = 1 + vis[idx];
                q.push(it);
            }
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
 
    vector<int> vis(n,-1);
        
    bfs(src,adj,vis);

    for(auto it : bfs){
        cout<<it<<" ";
    }

return 0;
}