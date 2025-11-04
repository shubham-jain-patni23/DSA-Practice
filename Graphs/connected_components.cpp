#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<int>&temp){
    visited[src] = 1;
    temp.push_back(src);
    for(auto it : adj[src]){
        if(!visited[it]){
            dfs(it,adj,visited,temp);
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);   

    int u,v;
    for(int i =0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    // approach 1;  TC ---> O(n) + O(n + 2E)  ===> O(v) + O(v + e) or O(n) + O(n + m); SC ---> O(n) + O(n) 
    // using bfs

    vector<bool> vis(n+1,0);
    vector<vector<int>> comp;
    
    for(int i =1;i<=n;i++){
        if(vis[i]==1){
            continue;
        }
        queue<int> q;
        vis[i] =1;
        vector<int> temp;
        q.push(i);

        while(!q.empty()){
            int x = q.front();
            temp.push_back(x);
            q.pop();
            for(auto it : adj[x]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        comp.push_back(temp);
    }

    for(auto it : comp){
        for(auto i : it){
            cout<<i<<" ";
        }cout<<endl;
    }

    // dfs

    // approach 2; TC --->O(v)  + O(v + 2e) ==> O(v) + O(v + e) ===>O(n) +  O(n + m); SC ---> O(n)(auxiliary stack space) + O(n)(visited arr)
    // using dfs; 


    vector<bool> visited(n+1,0);
    vector<vector<int>> ans;
    
    for(int i =1 ;i<=n;i++){
        if(visited[i]==0){
            vector<int> temp;
            dfs(i,adj,visited,temp);
            ans.push_back(temp);
        }
    }

    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }cout<<endl;
    }

return 0;
}