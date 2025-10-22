#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
using namespace std;

bool fun(vector<vector<int>> &adj,vector<bool> &visited,int idx,int prev){
    bool ans;
    for(auto it : adj[idx]){
        if(!visited[it]){
            visited[it] = 1;
            ans = fun(adj,visited,it,idx);
            if(ans==true){
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


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    int x, y;
    for(int i =0 ;i<m;i++){             
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n,0);
    
    int prev = -1;
    visited[1] = 1;
    bool ans = fun(adj,visited,1,prev);
    cout<<ans<<endl;

return 0;
}