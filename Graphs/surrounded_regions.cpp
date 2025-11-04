#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

// marking all the zeros connected to zero at (row,col) as vis
void dfs(int row,int col,vector<vector<char>>&arr,vector<vector<bool>> &visited){

    int n = arr.size();
    int m = arr[0].size();

    visited[row][col] = 1;

    // checking upwards
    if(row > 0 && arr[row-1][col]=='O' && visited[row-1][col]==0){
        dfs(row-1,col,arr,visited);
    }

    // checking downwards
    if(row < n-1 && arr[row+1][col]=='O' && visited[row+1][col]==0){
        dfs(row+1,col,arr,visited);
    }


    // checking left
    if(col > 0 && arr[row][col-1]=='O' && visited[row][col-1]==0){
        dfs(row,col-1,arr,visited);
    }

    // checking right
    if(col<m-1 && arr[row][col+1]=='O' && visited[row][col+1]==0){
        dfs(row,col+1,arr,visited);
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>>arr(n,vector<char>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // appraoch 1; using dfs; O(n + n*m*4); SC ---> O(n*m) + O(n*m)
    // for all the zeros at the boundary
    // we make a dfs call to vis all the zeroes connected to them 
    // at the end zeros which won't be visited won't be included
    // in the region of zeroes at the boundary
    
    vector<vector<bool>> visited(n,vector<bool>(m,0));

    // calling dfs for zeros at starting row
    for(int i =0;i<m;i++){
        if(arr[0][i]=='O' && visited[0][i]==0){
            dfs(0,i,arr,visited);
        }
    }

    // calling dfs for zeros at ending row
    for(int i =0;i<m;i++){
        if(arr[n-1][i]=='O' && visited[n-1][i]==0){
            dfs(n-1,i,arr,visited);
        }
    }

    // calling dfs for zeros at starting col
    for(int i =0;i<n;i++){
        if(arr[i][0]=='O' && visited[i][0]==0){
            dfs(i,0,arr,visited);
        }
    }

    // calling dfs for zeros at ending col
    for(int i =0;i<n;i++){
        if(arr[i][m-1]=='O' && visited[i][m-1]==0){
            dfs(i,m-1,arr,visited);
        }
    }

    for(int i =0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(arr[i][j]=='O' && visited[i][j]==0){
                arr[i][j] = 'X';
            }
        }
    }

    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }


return 0;
}