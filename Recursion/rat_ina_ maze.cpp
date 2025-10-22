#include<iostream>
#include<string>
#include<vector>
using namespace std;

// with the help of fun we are trying to reach from maze[row][col] to maze[n-1][n-1] by first checking  down then right
void fun(int n,vector<vector<int>> &maze,int row, int col, string temp, vector<string> &ans, vector<vector<int>> &mark){

    // lexicographically D L R U 

    if(row==n-1 && col==n-1){
        ans.push_back(temp);
        return;
    }
    if(row < n-1 && maze[row + 1][col]==1 && mark[row + 1][col]==0){
        temp+='D';
        mark[row + 1][col] = 1;
        fun(n,maze, row + 1, col, temp , ans, mark);
        mark[row + 1][col] = 0;
        temp.pop_back();
    }

    if(col > 0 && maze[row][col-1]==1 && mark[row][col-1]==0){
        temp+='L';
        mark[row][col - 1] = 1;
        fun(n, maze, row, col - 1, temp, ans, mark);
        temp.pop_back();
        mark[row][col - 1] = 0 ; 
    }

    if(col < n-1 && maze[row][col+1]==1 && mark[row][col+1]==0){
        temp+='R';
        mark[row][col + 1] = 1;
        fun(n, maze, row, col + 1, temp, ans, mark);
        temp.pop_back();
        mark[row][col + 1] = 0 ; 
    }

    if(row > 0 && maze[row - 1][col]==1 && mark[row - 1][col]==0){
        temp+='U';
        mark[row - 1][col] = 1;
        fun(n,maze, row - 1, col, temp , ans, mark);
        mark[row - 1][col] = 0;
        temp.pop_back();
    }

}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> maze(n,vector<int>(n));
    vector<vector<int>> mark(n,vector<int>(n,0));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>maze[i][j];
        }
    }

    vector<string> ans;

    string temp = "";
    mark[0][0] = 1;
    fun(n,maze,0, 0 , temp,ans,mark);

    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

return 0;
}