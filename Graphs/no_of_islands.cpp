#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void dfs(int src,vector<vector<int>> &adj,vector<bool> &visited){
    visited[src] = 1;
    for(auto it : adj[src]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

void dfsarr(int row,int col,vector<vector<int>> &arr,vector<vector<int>>&vis){
    int n = arr.size();
    int m = arr[0].size();
    vis[row][col] = 1;

    // checking upwards
    if(row > 0 && arr[row-1][col]==1 && vis[row-1][col]==0){
        dfsarr(row-1,col,arr,vis);
    }

    // checking downwards
    if(row<n-1 && arr[row+1][col]==1 && vis[row+1][col]==0){
        dfsarr(row +1,col,arr,vis);
    } 

    // checking left
    if(col > 0 && arr[row][col-1]==1 && vis[row][col-1]==0){
        dfsarr(row,col-1,arr,vis);
    }

    // checking right
    if(col < m-1 && arr[row][col+1]==1 && vis[row][col+1]==0){
        dfsarr(row,col+1,arr,vis);
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // approach 1; TC ---> O(n*m); SC ---> O(n*m) + O(n*m)
    // first converted the matrix into adj list of n*m nodes
    
    // if we consider every cell as an node
    // then total no. of islands will be the total no. of connected components
    // so total nodes will be (n*m) from 0 to (n*m) -1
    // for the nodes with val 0; we will consider them already vis

    // making adj list
    vector<vector<int>> adj(n*m);

    // if arr[i][j]==0; we will mark it visited already
    vector<bool> visited(n*m,0);

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]==1){
                // check upwards
                if(i>0 && arr[i-1][j]==1){
                    adj[i*m + j].push_back((i-1)*m + j);
                }

                // check downwards
                if(i<n-1 && arr[i+1][j]==1){
                    adj[i*m + j].push_back((i+1)*m + j);
                }

                // check left
                if(j>0 && arr[i][j-1]==1){
                    adj[i*m + j].push_back(i*m + (j-1));
                }

                // check right
                if(j<m-1 && arr[i][j+1]==1){
                    adj[i*m + j].push_back(i*m + (j+1));
                }
            }
            else{
                visited[i*m + j] = 1;
            }
        }
    }

    int cnt = 0;

    for(int i =0;i<n*m;i++){
        if(!visited[i]){
            cnt++;
            dfs(i,adj,visited);
        }
    }

    cout<<cnt<<endl;

    // approach 2; TC ---> O(n*m); SC ---> O(n*m) + O(n*m)
    // without making an adj list

    vector<vector<int>> vis(n,vector<int>(m,0));

    cnt = 0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && vis[i][j]==0){
                cnt++;
                dfsarr(i,j,arr,vis);
            }
        }
    }
    cout<<cnt<<endl;

    // appraoch 3; TC ---> O(n*m); SC ---> O(n*m)
    // using bfs 

    vector<vector<bool>> v(n,vector<bool>(m,0));
    cnt = 0;

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1 && v[i][j]==0){

                // new connected component
                cnt++; 
                queue<pair<int,int>> q;
                v[i][j] = 1;
                q.push({i,j});

                while(!q.empty()){
                    pair<int,int> x = q.front();
                    int row = x.first;
                    int col = x.second;
                    q.pop();

                    // pushing the neighbours into the queue
                    // checking upwards
                    if(row>0 && arr[row-1][col]==1 && v[row-1][col]==0){
                        v[row-1][col] = 1;
                        q.push({row-1,col});
                    }

                    // checking downwards
                    if(row<n-1 && arr[row+1][col]==1 && v[row+1][col]==0){
                        v[row+1][col] = 1;
                        q.push({row+1,col});
                    }

                    // checking left
                    if(col>0 && arr[row][col-1]==1 && v[row][col-1]==0){
                        v[row][col-1] =1;
                        q.push({row,col-1});
                    }

                    // checking right
                    if(col<m-1 && arr[row][col+1]==1 && v[row][col+1]==0){
                        v[row][col+1] = 1;
                        q.push({row,col+1});
                    }

                }

            }
        }
    }

    cout<<cnt<<endl;

return 0;
}