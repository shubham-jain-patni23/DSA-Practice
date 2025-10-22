#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
#include<climits>
using namespace std;



int main(){

    int n,m;
    cin>>n>>m;

    int src;
    cin>>src;

    vector<vector<int>> adj(m,vector<int>(3));

    for(int i =0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[i][0] = x;
        adj[i][1] = y;
        adj[i][2] = w;
    }

    vector<int> mindis(n,INT_MAX);
    mindis[src] = 0; 

    bool neg = false;

    for(int i = 1;i<=n;i++){
        for(auto it : adj){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(mindis[u]!=INT_MAX &&  mindis[u] + w < mindis[v]){
                if(i==n){
                    neg = true;
                    break;
                }
                mindis[v] = mindis[u] + w;
            }
        }
    }

    if(neg){
        cout<<"there is a negative cycle"<<endl;
        return 0 ; 
    }

    for(auto it : mindis){
        cout<<it<<" ";
    }
    cout<<endl;


return 0;
}