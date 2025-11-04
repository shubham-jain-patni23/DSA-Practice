#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

bool dfs(int src,vector<vector<int>>&adj,vector<bool>&visited,int prev){
    visited[src] = 1;

    for(auto it : adj[src]){
        if(visited[it]==0){
            bool x = dfs(it,adj,visited,src);
            if(x==true){
                return true;
            }
        }
        else{
            if(it!=prev){
                return true;
            }
        }
    }
return false;
}

bool bfs(int src,vector<vector<int>> &adj,vector<bool> &vis){

    queue<pair<int,int>> q;
    vis[src] = 1;
    q.push({src,-1});

    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int prev = p.second;
        q.pop();

        for(auto it : adj[x]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,x});
            }
            else{
                if(it!=prev){
                    return true;
                }
            }
        }

    }
return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    // approach 1; TC ---> O(v + 2*e) + O(v); SC ---> O(n) + O(n)
    // is some node is already visited then it means that there was atleast one more path to visit that node
    // using dfs

    bool isCycle = false;
    vector<bool> visited(n,0);

    for(int i =0;i<n;i++){
        if(!visited[i]){
            bool ans = dfs(i,adj,visited,-1);
            if(ans==true){
                isCycle = true;
                break;
            }
        }
    }

    cout<<isCycle<<endl;

    // approach 2; TC ---> O(v + 2*e) + O(v); SC ---> O(n) + O(n)
    // using bfs

    isCycle = false;
    vector<bool> vis(n,0);

    for(int i =0;i<n;i++){
        if(!vis[i]){
            bool ans = bfs(i,adj,vis);
            if(ans==true){
                isCycle = true;
                break;
            }
        }
    }

    cout<<isCycle<<endl;

return 0;
}