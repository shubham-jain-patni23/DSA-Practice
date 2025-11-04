#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

// can we make some odd len cycle by connecting src to its adj node
// to cnt the len of the cycle we maintain the no. of node in visited arr
bool isOddcycle(int src,vector<vector<int>>&adj,vector<int>&vis,int prev){
    if(prev==-1){
        vis[src] = 1;
    }
    else{
        vis[src] = vis[prev] + 1;
    }
    for(auto it : adj[src]){
        if(vis[it] == 0){
            bool y = isOddcycle(it,adj,vis,src);
            if(y==true){
                return true;
            }
        }
        else{
            if(prev!=-1){
                if((it!=prev) && ((vis[src] - vis[it] + 1)%2==1)){
                    return true;
                }
            }
        }
    }
return false;
}

bool bfs(int src,vector<vector<int>>&adj,vector<int>&visited){

    queue<pair<int,int>> q;
    visited[src] = 1;
    q.push({src,-1});

    while(!q.empty()){

        pair<int,int> p = q.front();
        int idx = p.first;
        int prev  = p.second;
        q.pop();

        for(auto it : adj[idx]){
            if(visited[it]==0){
                visited[it] = 1 + visited[idx];
                q.push({it,idx});
            }
            else{
                if((it != prev) && (visited[it] + visited[idx] -1)%2==1){
                    return true;
                }
            }
        }
    }
return false;
}

bool bfscolor(int src,vector<vector<int>>&adj,vector<int>&color){
    queue<int> q;
    color[src] = 0;
    q.push(src);

    while(!q.empty()){
        int idx = q.front();
        q.pop();

        for(auto it : adj[idx]){
            if(color[it]==-1){
                color[it] = 1 - color[idx];
                q.push(it);
            }
            else{
                if(color[it]==color[idx]){
                    return false;
                }
            }
        }
    }
return true;
}

bool dfscolor(int src,vector<vector<int>> &adj,vector<int>&col,int prev){

    if(prev==-1){
        col[src] = 0;
    }
    else{
        col[src] = 1 - col[prev];
    }

    for(auto it : adj[src]){
        if(col[it]==-1){
            bool y = dfscolor(it,adj,col,src);
            if(y==false){
                return false;
            }
        }
        else{
            if(col[it]==col[src]){
                return false;
            }
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> adj(n);

    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        for(int j = 0;j<x;j++){
            int y;
            cin>>y;
            adj[i].push_back(y);
        }
    }

    // approach 1; TC ---> O(n + 2*e); SC ---> O(n) + O(n)
    // graph is bipartite if and only if there is odd len cycle 
    // checking odd len cycle using dfs

    bool oddcycle = false;
    vector<int> vis(n,0);

    for(int i = 0;i<n;i++){
        if(vis[i]==0){
            bool x= isOddcycle(i,adj,vis,-1);           
            if(x==true){
                oddcycle = true;
                break;
            }
        }
    }

    cout<<!oddcycle<<endl;

    // approach 2; TC ---> O(v + 2*e); SC ---> O(n) + O(n)
    // checking for odd len cycle using bfs

    oddcycle = false;
    vector<int> visited(n,0);

    for(int i =0;i<n;i++){
        if(visited[i]==0){
            bool x = bfs(i,adj,visited);
            if(x==true){
                oddcycle = true;
                break;
            }
        }
    }

    cout<<!oddcycle<<endl;

    // appraoch 3; TC ---> O(v + 2*e); SC ---> O(n) + O(n)
    // coloring the nodes and then checking whether two adj are having the same color

    vector<int> color(n,-1);
    bool cancolor =  true;

    for(int i = 0;i<n;i++){
        if(color[i]==-1){
           bool y = bfscolor(i,adj,color);
           if(y==false){
                cancolor = false;
                break;
           }
        }
    }

    cout<<cancolor<<endl;

    // approach 4; TC ---> O(v + 2*e); SC ---> O(n) + O(n)

    vector<int>col(n,-1);
    cancolor = true;

    for(int i =0;i<n;i++){
        if(col[i]==-1){
            bool y = dfscolor(i,adj,col,-1);
            if(y==false){
                cancolor = false;
                break;
            }
        }
    }

    cout<<cancolor<<endl;

return 0;
}