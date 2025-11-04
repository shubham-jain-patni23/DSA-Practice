#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

bool dfs(int src,vector<vector<int>>&adj,vector<bool> &visited,vector<int>&path){
    visited[src] = true;
    path[src] = 1;

    for(auto it: adj[src]){
        if(visited[it]==0){
            bool x = dfs(it,adj,visited,path);
            if(x==true){
                return true;
            }
        }
        else{
            if(path[it]==1){
                return true;
            }
        }
    }
    path[src] = 0;
return false;
}

bool bfs(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<int> path){

    queue<pair<int,vector<int>>> q;

    visited[src] = 1;
    path[src] = 1;
    q.push({src,path});

    while(!q.empty()){

        pair<int,vector<int>> p = q.front();
        int idx = p.first;
        q.pop();

        for(auto it : adj[idx]){
            vector<int> v = p.second;
            if(visited[it]==0){
                v[it] = 1;
                visited[it] = 1;
                q.push({it,v});
            }
            else{
                if(v[it]==1){
                    return true;
                }
                v[it] =1 ;       
                q.push({it,v});     
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
    }
 
    // approach 1; TC ---> O(v + e) ; SC ---> O(n) + O(n)
    // while doing dfs we also store the path(using an boolean_arr)
    // in case we endup on a node of the same path then there is a cycle

    bool isCycle = false;
    vector<bool> visited(n,0);
    vector<int> path(n,0);

    for(int i =0;i<n;i++){
        if(!visited[i]){
            bool ans = dfs(i,adj,visited,path);
            if(ans==true){
                isCycle = true;
                break;
            }
        }
    }

    cout<<isCycle<<endl;


    // approach 2; TC ---> O(v + e); SC ---> O(n) + O(n)
    // using bfs

    vector<bool> vis(n,0);
    isCycle = false;
    vector<int> path1(n,0);

    for(int i =0;i<n;i++){
        if(!vis[i]){
            bool ans = bfs(i,adj,vis,path1);
            if(ans==true){
                isCycle = true;
                break;
            }
        }
    }

    cout<<isCycle<<endl;

    // approach 3; TC ---> O(e) + O(v) + O(v + e); SC ---> O(v) + O(v)
    // using bfs (using multisrc bfs)
    // we will put the nodes with 0 indegree in the queue
    // if there is a cycle then we will not be put all the nodes in the queue

    vector<int> ind(n,0);

    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            ind[it]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for(int i =0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()){
        int idx = q.front();
        ans.push_back(idx);
        q.pop();
        cnt++;

        for(auto it : adj[idx]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
        }

    }

    if(cnt==n){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
    }

return 0;
}