#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

// this problem is similar to surrounded_regions
// we need to cnt 1's which are not connected to boundary regions 

// marking all the zeros connected to zero at (row,col) as vis
void dfs(int row,int col,vector<vector<int>>&arr,vector<vector<bool>> &visited){

    int n = arr.size();
    int m = arr[0].size();

    visited[row][col] = 1;

    // checking upwards
    if(row > 0 && arr[row-1][col]==1 && visited[row-1][col]==0){
        dfs(row-1,col,arr,visited);
    }

    // checking downwards
    if(row < n-1 && arr[row+1][col]==1 && visited[row+1][col]==0){
        dfs(row+1,col,arr,visited);
    }


    // checking left
    if(col > 0 && arr[row][col-1]==1 && visited[row][col-1]==0){
        dfs(row,col-1,arr,visited);
    }

    // checking right
    if(col<m-1 && arr[row][col+1]==1 && visited[row][col+1]==0){
        dfs(row,col+1,arr,visited);
    }
}

// when we do bfs what happens is instead of making a recursive call to the neighbour 
// we push the neighbour in the queue, which is then called later

void bfs(int i,int j,vector<vector<int>>&arr,vector<vector<bool>> &vis){

    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int,int>> q;
    vis[i][j] = 1;
    q.push({i,j});

    while(!q.empty()){
        pair<int,int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        // checking upwards
        if(row > 0 && arr[row-1][col]==1 && vis[row-1][col]==0){
            vis[row-1][col] = 1;
            q.push({row-1,col});
        }

        // checking downwards
        if(row < n-1 && arr[row+1][col]==1 && vis[row+1][col]==0){
            vis[row+1][col] =1 ;
            q.push({row+1,col});
        }


        // checking left
        if(col > 0 && arr[row][col-1]==1 && vis[row][col-1]==0){
            vis[row][col-1] = 1;
            q.push({row,col-1});
        }

        // checking right
        if(col<m-1 && arr[row][col+1]==1 && vis[row][col+1]==0){
            vis[row][col+1] = 1;
            q.push({row,col+1});
        }

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

    // appraoch 1; using dfs; O(n + n*m*4); SC ---> O(n*m) + O(n*m)
    // for all the one's at the boundary
    // we make a dfs call to vis all the one's connected to them 
    // at the end one's which won't be visited won't be included
    // in the region of one's at the boundary
    
    vector<vector<bool>> visited(n,vector<bool>(m,0));

    // calling dfs for ones at starting row
    for(int i =0;i<m;i++){
        if(arr[0][i]== 1 && visited[0][i]==0){
            dfs(0,i,arr,visited);
        }
    }

    // calling dfs for zeros at ending row
    for(int i =0;i<m;i++){
        if(arr[n-1][i]==1 && visited[n-1][i]==0){
            dfs(n-1,i,arr,visited);
        }
    }

    // calling dfs for zeros at starting col
    for(int i =0;i<n;i++){
        if(arr[i][0]==1 && visited[i][0]==0){
            dfs(i,0,arr,visited);
        }
    }

    // calling dfs for zeros at ending col
    for(int i =0;i<n;i++){
        if(arr[i][m-1]==1 && visited[i][m-1]==0){
            dfs(i,m-1,arr,visited);
        }
    }

    int cnt = 0;

    for(int i =0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]==1 && visited[i][j]==0){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;


    // approach 2; using bfs
    vector<vector<bool>> vis(n,vector<bool>(m,0));

    // calling bfs for ones at starting row
    for(int i =0;i<m;i++){
        if(arr[0][i]== 1 && vis[0][i]==0){
            bfs(0,i,arr,vis);
        }
    }

    // calling bfs for zeros at ending row
    for(int i =0;i<m;i++){
        if(arr[n-1][i]==1 && vis[n-1][i]==0){
            bfs(n-1,i,arr,vis);
        }
    }

    // calling bfs for zeros at starting col
    for(int i =0;i<n;i++){
        if(arr[i][0]==1 && vis[i][0]==0){
            bfs(i,0,arr,vis);
        }
    }

    // calling bfs for zeros at ending col
    for(int i =0;i<n;i++){
        if(arr[i][m-1]==1 && vis[i][m-1]==0){
            bfs(i,m-1,arr,vis);
        }
    }

    cnt = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(vis[i][j]==0 && arr[i][j]==1){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    // approach 3; O(4n) + O(n*m*4); SC ---> O(n*m) + O(n*m)
    // multisource bfs
    // we first put all the boundary 1's into the arr 

    queue<pair<int,int>> q;

    vector<vector<bool> visi(n,vector<bool>(m,0));

    // calling bfs for zeros at starting row
    for(int i =0;i<m;i++){
        if(arr[0][i]== 1 && visi[0][i]==0){
            visi[0][i] = 1;
            q.push({0,i});
        }
    }

    // calling bfs for zeros at ending row
    for(int i =0;i<m;i++){
        if(arr[n-1][i]==1 && visi[n-1][i]==0){
            visi[n-1][i] = 1;
            q.push({n-1,i});
        }
    }

    // calling bfs for zeros at starting col
    for(int i =0;i<n;i++){
        if(arr[i][0]==1 && visi[i][0]==0){
            visi[i][0] = 1;
            q.push({i,0});
        }
    }

    // calling bfs for zeros at ending col
    for(int i =0;i<n;i++){
        if(arr[i][m-1]==1 && visi[i][m-1]==0){
            visi[i][m-1] = 1;
            q.push({i,m-1});
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        // checking upwards
        if(row > 0 && arr[row-1][col]==1 && visi[row-1][col]==0){
            visi[row-1][col] = 1;
            q.push({row-1,col});
        }

        // checking downwards
        if(row < n-1 && arr[row+1][col]==1 && visi[row+1][col]==0){
            visi[row+1][col] =1 ;
            q.push({row+1,col});
        }


        // checking left
        if(col > 0 && arr[row][col-1]==1 && visi[row][col-1]==0){
            visi[row][col-1] = 1;
            q.push({row,col-1});
        }

        // checking right
        if(col<m-1 && arr[row][col+1]==1 && visi[row][col+1]==0){
            visi[row][col+1] = 1;
            q.push({row,col+1});
        }
    }

    cnt = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1 && visi[i][j]==0){
                cnt++;
            }
        }
    }

return 0;
}