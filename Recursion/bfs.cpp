#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(n+1,0));

    int x, y;
    for(int i =0 ;i<m;i++){             
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    queue<int> q;

    q.push(1);
    vector<int> ans;
    vector<bool> visited(n+1,0);
    visited[1] = 1;

    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(int i = 0 ; i<=n;i++){
            if(adj[x][i]==1 && visited[i]==0){
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;

return 0;
}