#include<iostream>
#include<vector>
#include<stack>
#include<queue>    
#include<utility>
using namespace std;  

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<int> ind(n,0);

    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            ind[it]++;
        }
    }

    queue<int> q;

    for(int i =0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int idx = q.front();
        ans.push_back(idx);
        q.pop();

        for(auto it : adj[idx]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
        }

    }

    if(ans.size()==n){
        for(auto it : ans){
            cout<<it<<" ";
        }cout<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
 
return 0;
}