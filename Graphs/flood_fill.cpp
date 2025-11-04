#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &arr,vector<vector<bool>> &visited,int color,int clr,vector<vector<int>>&newarr){

    int n = arr.size();
    int m = arr[0].size();

    visited[row][col] = 1;
    newarr[row][col] = color;


    // checking upwards
    if((row > 0) && (arr[row-1][col]==clr) && (visited[row-1][col]==0)){
        dfs(row-1,col,arr,visited,color,clr,newarr);
    }

    // checking downwards
    if((row<n-1) && (arr[row+1][col]==clr) && (visited[row+1][col]==0)){
        dfs(row+1,col,arr,visited,color,clr,newarr);
    } 

    // checking left
    if((col > 0) && (arr[row][col-1]==clr && (visited[row][col-1]==0))){
        dfs(row,col-1,arr,visited,color,clr,newarr);
    }

    // checking right
    if((col < m-1) && (arr[row][col+1]==clr) && (visited[row][col+1]==0)){
        dfs(row,col+1,arr,visited,color,clr,newarr);
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    int row,col,color;
    cin>>row>>col>>color;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // appraoch 1; TC ---> O(n*m) + O(n*m*4) ===>  O(n*m); SC ---> O(n*m) + O(n*m)
    // calling dfs for O(n*m) and in each call we are checking neighbourning 4 i.e. O(n*m*4)
    // using dfs

    int clr = arr[row][col];

    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<int>> newarr = arr;

    dfs(row,col,arr,visited,color,clr,newarr);

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<newarr[i][j]<<" ";
        }cout<<endl;
    }

return 0;
}