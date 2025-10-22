#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &adj,vector<bool> &visited,int idx,vector<int>&ans){
    ans.push_back(idx);
    for(auto it : adj[idx]){
        if(!visited[it]){
            visited[it] = 1;
            dfs(adj,visited,it,ans);
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    int x, y;
    for(int i =0 ;i<m;i++){             
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n+1,0);
    vector<int> ans;
    visited[1] = 1;
    dfs(adj,visited,1,ans);

    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;

return 0;
}