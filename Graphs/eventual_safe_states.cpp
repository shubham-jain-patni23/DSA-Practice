#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

bool dfs(int src,vector<vector<int>>&adj,vector<bool> &visited,vector<int>&path,vector<int> &safe){
    visited[src] = true;
    path[src] = 1;

    for(auto it: adj[src]){
        if(visited[it]==0){
            bool x = dfs(it,adj,visited,path,safe);
            if(x==true){
                safe[src] = 0;
                return true;
            }
        }
        else{
            if(path[it]==1 || safe[it]==0){
                safe[src] = 0;
                return true;
            }
        }
    }
    path[src] = 0;
return false;
}

bool dfs2(int src,vector<vector<int>>&adj,vector<bool> &visited,vector<int>&path){
    visited[src] = true;
    path[src] = 1;

    for(auto it: adj[src]){
        if(visited[it]==0){
            bool x = dfs2(it,adj,visited,path);
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
  

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
 
    // approach 1; TC ---> O(v + e) ; SC ---> O(n) + O(n) + O(n)
    // safe states are the states which do no come in the path of any cycle
    vector<bool> visited(n,0);
    vector<int> path(n,0);
    vector<int> safe(n,1);

    vector<int> ans;

    for(int i =0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,path,safe);
        }
    }

    for(int i =0;i<n;i++){
        if(safe[i]==1){
            ans.push_back(i);
        }
    }
    

    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;

    // approach 2; TC ---> O(v + e)  SC ---> O(n) + O(n)
    // using dfs but not using safe arr
    
    vector<int> path1(n,0);
    vector<bool> vis(n,0);
    vector<int> res;

    for(int i =0;i<n;i++){
        if(!vis[i]){
            dfs2(i,adj,vis,path1);
        }
    }

    // path1[i] = 1; means i in included in some path which leads to
    for(int i =0;i<n;i++){
        if(path1[i]==0){
            res.push_back(i);
        }
    }

    for(auto i : res){
        cout<<i<<" ";
    }cout<<endl;


    // approach 3; TC ---> O(v + e) + O(vlogv); SC ---> O(v + e) + O(n) + O(n)
    // using bfs 
    // find outdegree of every one
    // nodes with 0 outdeg put in queue 


    // outdegree
    vector<int> outdeg(n,0);
    for(int i =0;i<n;i++){
        outdeg[i] = adj[i].size();
    }

    // reverse adj; revadj[i] stores all the ele which have edge to i
    vector<vector<int>> revadj(n);
    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            revadj[it].push_back(i);
        }
    }

    queue<int> q;
    vector<int> ans2;

    for(int i =0;i<n;i++){
        if(outdeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int idx = q.front();
        ans2.push_back(idx);
        q.pop();

        for(auto it: revadj[idx]){
            outdeg[it]--;
            if(outdeg[it]==0){
                q.push(it);
            }
        }

    }

    sort(ans2.begin(),ans2.end());

    for(auto it : ans2){
        cout<<it<<" ";
    }cout<<endl;

return 0;
}