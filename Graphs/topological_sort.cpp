#include<iostream>
#include<vector>
#include<stack>
#include<queue>    
#include<utility>
using namespace std;  

void dfs(int src,vector<vector<int>>&adj,vector<bool>&visited,stack<int> &st){

    visited[src] = 1;

    for(auto it : adj[src]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        }
    }
    st.push(src);
}

// topological sorting of DAG with given adj list
vector<int> toposort(vector<vector<int>> &adj){

    int n = adj.size();

    // find indeg of all nodes
    vector<int> indeg(n,0);
    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            indeg[it]++;
        }
    }

    // push the nodes with 0 indeg in queue

    queue<int> q;
    for(int i =0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int idx = q.front();
        ans.push_back(idx);
        q.pop();

        for(auto it : adj[idx]){
            indeg[it]--;
            if(indeg[it]==0){     // means all the nodes before it are already covered
                q.push(it);
            }
        }
    }
return ans;
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

    // approach 1; TC ---> O(v + e) + O(v); SC ---> O(n) + O(n) + O(n)
    // using dfs and 1 stack 

    vector<bool> visited(n,0);
    stack<int>st;

    for(int i =0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    
    vector<int> toposrt;
    
    while(!st.empty()){
        toposrt.push_back(st.top());
        st.pop();
    }
    
    for(auto it : toposrt){
        cout<<it<<" ";
    }cout<<endl;

    // approach 2; TC ---> O(v + e);  SC ---> O(n) + O(n)
    // using multisrc bfs(Kahn's algorithm)
    // step 1; find indeg of all nodes 
    // step 2; do multisrc bfs
    // in queue there will be always those nodes before which either there are no nodes
    // or all the nodes before them are covered

    vector<int> ans = toposort(adj);

    for(auto it : ans){
        cout<<it<<" ";
    }
 
return 0;
}