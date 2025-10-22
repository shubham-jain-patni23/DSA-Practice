#include<iostream>
#include<string>
#include<vector>
using namespace std;

// approach 1;  TC ---> O(n*m) * (4^n) where n = s.size()  ; SC ---> O(n*m) + O(L)
// starting from any idx where se get s[0] we check whether the rem str can be gen using fun

bool fun(vector<vector<char>> &board,string s,int row,int col,int idx,vector<vector<int>> &mark){
    if(idx==s.size()){
        return true;
    }
    bool up , down , left ,right;

    // checking if the rem word can be made by going upwards
    if((row >0) && (mark[row-1][col] == 0) && (board[row-1][col]==s[idx])){
        mark[row-1][col] = 1;
        up = fun(board,s, row-1, col , idx + 1, mark);
        if(up==true){
            return up;
        }
        mark[row-1][col] = 0 ;
    }

    // checking if the rem word can be made by going downwards
    if((row < (board.size()  - 1)) && (mark[row+1][col] == 0) && (board[row+1][col]==s[idx])){
        mark[row+1][col] = 1;
        down = fun(board,s,row+1, col , idx + 1, mark);
        if(down==true){
            return down;
        }
        mark[row+1][col] = 0 ;
    }

    // checking if the rem word can be made by going left
    if((col > 0) && (mark[row][col-1] == 0) && (board[row][col-1]==s[idx])){
        mark[row][col-1] = 1;
        left = fun(board,s,row, col-1, idx + 1, mark);
        if(left==true){
            return left;
        }
        mark[row][col-1] = 0 ;
    }

    // checking if the rem word can be made by going right
    if((col < (board[0].size()  - 1)) && (mark[row][col+1] == 0) && (board[row][col+1]==s[idx])){
        mark[row][col+1] = 1;
        right = fun(board,s,row, col+1 , idx + 1, mark);
        if(right==true){
            return right;
        }
        mark[row][col+1] = 0 ;
    }
return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> board(n,vector<char>(m));
    vector<vector<int>> mark(n,vector<int>(m,0));

    for(int i =0 ;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }

    string s;
    cin>>s;

    bool ans = false;

    for(int i =0 ;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board[i][j]==s[0]){
                mark[i][j] = 1;
                ans = fun(board, s, i, j ,1, mark);
                if(ans == true){
                    break;
                }
                mark[i][j] = 0;

            }
        }
        if(ans==true){
            break;
        }
    }

    cout<<ans<<endl;

return 0;
}