#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
using namespace std;

void dfs(int src,vector<vector<pair<int,int>>>&adj,vector<bool> &vis,stack<int>&st){

    vis[src] = 1;
    for(auto it : adj[src]){
        if(!vis[it.first]){
            dfs(it.first,adj,vis,st);
        }
    }

    st.push(src);

}

// topological sorting of DAG with given adj list
vector<int> toposort(vector<vector<pair<int,int>>> &adj){

    int n = adj.size();

    // find indeg of all nodes
    vector<int> indeg(n,0);
    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            indeg[it.first]++;
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
            indeg[it.first]--;
            if(indeg[it.first]==0){     // means all the nodes before it are already covered
                q.push(it.first);
            }
        }
    }
return ans;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i =0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }

    // approach 1; TC ---> O(v + e) + O(v^3); SC ---> O(n)
    // step 1; find toposort
    // step 2; nodes before src will not be reachable; dis -1
    // step 3; after src iterate over all the nodes to see mini dis

    int src = 0;

    // find toposort
    vector<int> topo = toposort(adj);   // O(v + e)
    
     
    vector<int> dis(n,-1);

    // before src all will have zero dis
    int i;
    for(i = 0;i<topo.size();i++){
        if(topo[i]==src){
            dis[topo[i]] = 0;
            break;
        }
    }

    // after src till there is no direct edge no connection
    // we will update all nodes for direct edge

    int flag = -1;
    for(; i< topo.size();i++){      // O(v*v)
        // checking if there is any direct edge
        for(auto it : adj[src]){
            if(it.first==topo[i]){
                dis[topo[i]] = it.second;
                if(flag==-1){
                    flag = i;
                }
                break;
            }
        }
    }

    // for every node we will check via all the nodes before it 
    if(flag!=-1){
        // updating dis of nodes from flag + 1 till end
        for(i = flag + 1;i<topo.size();i++){        // O(v*v*v)
            // checking via others
            for(int j = flag;j<i;j++){
                if(dis[topo[j]]!=-1){
                    // now check if there is some direct edge from topo[j] to topo[i]
                    for(auto it : adj[topo[j]]){
                        if(it.first==topo[i]){
                            if((dis[topo[i]]==-1) || (dis[topo[i]] > (dis[topo[j]] + it.second))){
                                dis[topo[i]] = dis[topo[j]] + it.second;
                            }
                        }
                    }
                }
            }
        }
    }

    for(auto it : dis){
        cout<<it<<" ";
    }cout<<endl;

    // approach 2; TC ---> O(v + e); SC ---> O(n) + O(n) + O(n) + O(n)
    // step 1; toposort using dfs
    // step 2; for every node from stack we are seeing the dis of its adj nodes via it

    stack<int> st;
    vector<bool>vis(n,0);

    // calling dfs for toposort
    dfs(src,adj,vis,st);        // O(v + e)

    // updating the dist
    vector<int> dist(n,-1);
    dist[src] = 0;

    while(!st.empty()){         // O(v + e)
        int node = st.top();
        st.pop();
        //if(dist[node]!=-1){ // no need for check 
            for(auto it: adj[node]){
                if((dist[it.first]==-1) || (dist[it.first] > dist[node] + it.second)){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        //}
    }

    for(auto it : dist){
        cout<<it<<" ";
    }cout<<endl;

return 0;
}