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

    vector<vector<vector<int>>> adj(n);

    for(int i =0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }

    vector<int> mindis(n,INT_MAX);
    mindis[src] = 0; 

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 

    pq.push({0,src});

    while(!pq.empty()){
        int x = pq.top()[1];
        int disx = mindis[x];
        pq.pop();

        for(auto it : adj[x]){
            int disitx = it[1];
            int mindisit = mindis[it[0]];
            if(mindisit > disx + disitx){
                mindis[it[0]] = disx + disitx;
                pq.push({mindis[it[0]], it[0]});
            }
        }

    }

    for(auto it : mindis){
        cout<<it<<" ";
    }
    cout<<endl;


return 0;
}