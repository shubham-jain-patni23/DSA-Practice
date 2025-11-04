#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

// this problem is similar to rotton oranges 
// here we either have rotten oranges '0' or fresh oranges '1', but here we don't have empty cells

void dfs(int row,int col,vector<vector<int>>&arr,vector<vector<int>>&cost){
    int n = arr.size();
    int m = arr[0].size();

    // checking upwards 
    if((row > 0) && (arr[row-1][col]==1) && ((cost[row-1][col]==-1) || (cost[row-1][col] > 1 + cost[row][col]))){
        cost[row-1][col] = 1 + cost[row][col];
        dfs(row-1,col,arr,cost);
    }

    // checking downwards
    if((row < n-1) && (arr[row+1][col]==1) && ((cost[row+1][col]==-1) || (cost[row+1][col] > 1 + cost[row][col]))){
        cost[row+1][col] = 1 + cost[row][col];
        dfs(row+1,col,arr,cost);
    }

    // checking left 
    if((col > 0) && (arr[row][col-1]==1) && ((cost[row][col-1]==-1) || (cost[row][col-1] > 1 + cost[row][col]))){
        cost[row][col-1] = 1 + cost[row][col];
        dfs(row,col-1,arr,cost);
    }

    // checking right
    if((col < m-1) && (arr[row][col+1]==1) && ((cost[row][col+1]==-1) || (cost[row][col+1] > 1 + cost[row][col]))){
        cost[row][col+1] = 1 + cost[row][col];
        dfs(row,col+1,arr,cost);
    }
}

void bfs(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&cost){
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){

        pair<int,int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        // checking upwards 
        if((row > 0) && (arr[row-1][col]==1) && ((cost[row-1][col]==-1) || (cost[row-1][col] > 1 + cost[row][col]))){
            cost[row-1][col] = 1 + cost[row][col];
            q.push({row-1,col});
        }

        // checking downwards
        if((row < n-1) && (arr[row+1][col]==1) && ((cost[row+1][col]==-1) || (cost[row+1][col] > 1 + cost[row][col]))){
            cost[row+1][col] = 1 + cost[row][col];
            q.push({row+1,col});
        }

        // checking left 
        if((col > 0) && (arr[row][col-1]==1) && ((cost[row][col-1]==-1) || (cost[row][col-1] > 1 + cost[row][col]))){
            cost[row][col-1] = 1 + cost[row][col];
            q.push({row,col-1});
        }

        // checking right
        if((col < m-1) && (arr[row][col+1]==1) && ((cost[row][col+1]==-1) || (cost[row][col+1] > 1 + cost[row][col]))){
            cost[row][col+1] = 1 + cost[row][col];
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

    // approach 1; TC ---> O(n*m + n*m*4); SC ---> O(n*m) + O(n*m)
    // using dfs;
    // zero can update the dis of every 1
    // so we will call dfs only on zero

    vector<vector<int>> newarr(n,vector<int>(m,-1));

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==0){
                newarr[i][j] = 0;
                dfs(i,j,arr,newarr);
            }
        }
    }

    for(auto i : newarr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    // approach 2; TC ---> O(n*m + n*m*4); SC ---> O(n*m) + O(n*m)
    // using bfs;

    vector<vector<int>> cost(n,vector<int>(m,-1));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]==0){
                cost[i][j] = 0;
                bfs(i,j,arr,cost);
            }
        }
    }

    for(auto i: cost){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    // approach 3; TC ---> O(n*m + n*m*4); SC ---> O(n*m) + O(n*m)
    // using bfs but first pushing all the zeroes into the queue (multisource bfs)
    // first cost of all 1's at dis 1 will be updated, then 1's at dis 2 and similarly at diff levels

    queue<pair<int,int>> q;
    vector<vector<int>> dis(n,vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]==0){
                dis[i][j] = 0;
                q.push({i,j});
            }
            else{
                dis[i][j] = -1;
            }
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        // checking upwards 
        if((row > 0) && (arr[row-1][col]==1) && (dis[row-1][col]==-1)){
            dis[row-1][col] = 1 + dis[row][col];
            q.push({row-1,col});
        }

        // checking downwards
        if((row < n-1) && (arr[row+1][col]==1) && (dis[row+1][col]==-1)){
            dis[row+1][col] = 1 + dis[row][col];
            q.push({row+1,col});
        }

        // checking left
        if((col > 0) && (arr[row][col-1] == 1) && (dis[row][col-1]==-1)){
            dis[row][col-1] = 1 + dis[row][col];
            q.push({row,col-1});
        }

        // checking right
        if((col < m-1) && (arr[row][col+1]==1) && (dis[row][col+1]==-1)){
            dis[row][col+1] = 1 + dis[row][col];
            q.push({row,col+1});
        }
    }

    for(auto i : dis){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}