#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &arr,vector<vector<int>>&cost){
    int n = arr.size();
    int m = arr[0].size();

    // updating cost for frest oranges to rot 
    // only when either its curr cost is more or its cost is -1 i.e. till now it can't be rotten
    // checking upwards
    if((row > 0) && (arr[row-1][col]==1) && (cost[row-1][col]==-1 || (cost[row-1][col] > (1 + cost[row][col])))){
        cost[row-1][col] = 1 + cost[row][col];
        dfs(row-1,col,arr,cost);
    }

    // checking downwards
    if((row<n-1) && (arr[row+1][col]==1) && ((cost[row+1][col]==-1) || (cost[row+1][col] > (1 + cost[row][col])))){
        cost[row+1][col] = 1 + cost[row][col];
        dfs(row+1,col,arr,cost);
    } 

    // checking left
    if((col > 0) && (arr[row][col-1]==1) && ((cost[row][col-1]==-1) || (cost[row][col-1] > (1 + cost[row][col])))){
        cost[row][col-1] = 1 + cost[row][col];
        dfs(row,col-1,arr,cost);
    }

    // checking right
    if(col < m-1 && arr[row][col+1]==1 && (cost[row][col+1]==-1) || ((cost[row][col+1] > (1 + cost[row][col])))){
        cost[row][col+1] = 1 + cost[row][col];
        dfs(row,col+1,arr,cost);
    }
}

void bfs(int i,int j,vector<vector<int>>&arr, vector<vector<int>> &cost){

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
        if((row > 0) && (arr[row-1][col]==1) && (cost[row-1][col]==-1 || (cost[row-1][col] > (1 + cost[row][col])))){
            cost[row-1][col] = 1 + cost[row][col];
            q.push({row-1,col});
        }

        // checking downwards
        if((row<n-1) && (arr[row+1][col]==1) && ((cost[row+1][col]==-1) || (cost[row+1][col] > (1 + cost[row][col])))){
            cost[row+1][col] = 1 + cost[row][col];
            q.push({row+1,col});
        } 

        // checking left
        if((col > 0) && (arr[row][col-1]==1) && ((cost[row][col-1]==-1) || (cost[row][col-1] > (1 + cost[row][col])))){
            cost[row][col-1] = 1 + cost[row][col];
            q.push({row,col-1});
        }

        // checking right
        if(col < m-1 && arr[row][col+1]==1 && (cost[row][col+1]==-1) || ((cost[row][col+1] > (1 + cost[row][col])))){
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

    // approach 1; TC ---> O(n*m) + O(n*m) *4 ===> O(n*m); SC ---> O(n*m)
    // using dfs
    // cost is the time it will take to rot fresh oranges 
    // initially it is 0 for rotten oranges and -1 for fresh oranges

    vector<vector<int>> cost(n,vector<int>(m,0));
    
    for(int i =0;i<n;i++){          // O(n*m)
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1){
                cost[i][j] = -1;
            }
        }
    }

    // calling dfs when we got some rotten orange
    // we are calling dfs to find the mini cost to rot the fresh oranges
    // so we call dfs only for rotten oranges

    for(int i =0 ;i<n;i++){         // O(n*m)
        for(int j =0 ;j<m;j++){
            if(arr[i][j]==2){
                dfs(i,j,arr,cost);
            }
        }
    }

    int ans = 0;

    for(int i = 0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]==1){
                if(cost[i][j]==-1){
                    ans = -1;
                    break;
                }
                else{
                    ans = max(ans,cost[i][j]);
                }
            }
        }
        if(ans==-1){
            break;
        }
    }

    cout<<ans<<endl;

    // approach 2; using bfs; TC ---> O(n*m); SC ---> O(n*m)
    // like dfs here too
    // we push only the 2's in the queue initially, i.e. we call bfs only for 2

    vector<vector<int>> dis(n,vector<int>(m,0));

    for(int i =0;i<n;i++){          
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1){
                dis[i][j] = -1;
            }
        }
    }

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==2){
                bfs(i,j,arr,dis);
            }
        }
    }

    ans = 0;

    for(int i = 0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]==1){
                if(dis[i][j]==-1){
                    ans = -1;
                    break;
                }
                else{
                    ans = max(ans,dis[i][j]);
                }
            }
        }
        if(ans==-1){
            break;
        }
    }

    cout<<ans<<endl;

    // approach 3; TC ---> O(n*m); SC ---> O(n*m)
    // push all the rotten oranges in the start

    vector<vector<int>> time(n,vector<int>(m,0));

    // first we push all the rotten oranges, i.e. level 0
    queue<pair<int,int>> q;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1){
                time[i][j] = -1;
            }
            else if(arr[i][j]==2){
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front();
        int row = p.first;
        int col = p.second;
        q.pop();

        // we update the time of any fresh orange when it is not updated 
        // if it is already updated then we will not update it 
        // as it must have been updated by some rotten orange at lower level

        // checking upwards
        if((row > 0) && (arr[row-1][col]==1) && (time[row-1][col]==-1)){
            time[row-1][col] = 1 + time[row][col];
            q.push({row-1,col});
        }

        // checking downwards
        if((row<n-1) && (arr[row+1][col]==1) && ((time[row+1][col]==-1) || (time[row+1][col] > (1 + time[row][col])))){
            time[row+1][col] = 1 + time[row][col];
            q.push({row+1,col});
        } 

        // checking left
        if((col > 0) && (arr[row][col-1]==1) && (time[row][col-1]==-1)){
            time[row][col-1] = 1 + time[row][col];
            q.push({row,col-1});
        }

        // checking right
        if(col < m-1 && arr[row][col+1]==1 && (time[row][col+1]==-1)){
            time[row][col+1] = 1 + time[row][col];
            q.push({row,col+1});
        }

    }

    ans = 0 ;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]==1){
                if(time[i][j]==-1){
                    ans = -1;
                    break;
                }
                else{
                    ans = max(ans,time[i][j]);
                }
            }
        }
        if(ans==-1){
            break;
        }
    }

    cout<<ans<<endl;

return 0;
}