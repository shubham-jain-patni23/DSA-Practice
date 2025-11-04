#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int src,vector<vector<int>> &adjlist,vector<bool> &visited,vector<int> &dfsarr){
    dfsarr.push_back(src);
    visited[src] = 1;
    for(auto it : adjlist[src]){
        if(!visited[it]){
            dfs(it,adjlist,visited,dfsarr);
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjlist(n+1);   

    int u,v;
    for(int i =0;i<m;i++){
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    int st;
    cin>>st;

    // bfs

    // approach 1;  TC ---> O(n) + O(2*E) ===> O(v + e) or O(n + m); SC ---> O(3n) 
    // using queue

    queue<int> q;
    q.push(st);

    vector<bool> vis(n+1,0);
    vis[st] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        cout<<x<<" ";

        for(auto i: adjlist[x]){            // O(total degree sum)
            if(vis[i]==0){
                q.push(i);
                vis[i] =1 ;
            }
        }
    }
    cout<<endl;

    // dfs

    // approach 1; TC ---> O(v + 2e) ==> O(v + e) ===> O(n + m); SC ---> O(n)(auxiliary stack space) + O(n)(visited arr)
    // using recursion; 

    vector<int> dfsarr;
    vector<bool> visited(n+1,0);
    dfs(st,adjlist,visited,dfsarr);

    for(auto it : dfsarr){
        cout<<it<<" ";
    }

return 0;
}