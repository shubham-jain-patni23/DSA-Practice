#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st,int idx){
    for(auto it : adj[idx]){
        if(!visited[it]){
            visited[it] = 1;
            dfs(adj,visited,st,it);
        }
    }
    st.push(idx);
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    int x, y;
    for(int i =0 ;i<m;i++){             
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<bool> visited(n,0);

    stack<int> st;

    for(int i = 0;i<n;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(adj,visited,st,i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

return 0;
}