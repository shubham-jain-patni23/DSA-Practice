#include<iostream>
#include<string>
#include<vector>
using namespace std;

// fun to check whether a particular char can be placed or not ; TC ---> O(9) + O(9) + O(9) = O(27);
bool isTrue(vector<vector<char>> &board,int row,int col,char ch){

    // check in row
    for(int i = 0 ;i<9;i++){
        if(board[row][i]==ch){
            return false;
        }
    }
    
    // check in col 
    for(int i = 0;i<9;i++){
        if(board[i][col]==ch){
            return false;
        }
    }

    // check in block
    int row_block = row/3;
    int col_block = col/3;

    for(int i = (row_block*3) ; i< ((row_block * 3) + 3);i++){
        for(int j = (col_block*3) ; j< ((col_block*3) + 3) ; j++){
            if(board[i][j]==ch){
                return false;
            }
        }
    }
return true;
}

// approach 1; TC ---> O(9^m) where m is the no. of empty cells  ; SC ---> O(m)
// fun is checking whether from the given cell we can fill the entire sudoku
bool fun(vector<vector<char>> &board,int row,int col){

    if(board[row][col]!='.'){
        if(col < 8){
            return fun(board,row,col+1);
        }
        else if(row < 8){
            return fun(board,row+1,0);
        }
        return true;
    }

    for(int i = 1;i<=9;i++){
        char ch = (char)('0' + i);

        if(isTrue(board,row,col, ch)){
            board[row][col] = ch;
        }
        else{
            continue;
        }
        bool x ; 
        if(col < 8){
            x = fun(board,row, col+1);
            if(x==true){
                return true;
            }
            board[row][col] = '.';
        }
        else if(row < 8){
            x = fun(board,row+1,0);
            if(x==true){
                return true;
            }
            board[row][col] = '.';
        }
        else {
            return true;
        }
    }

    // return false when either we can't put any digit or
    // after putting any valid digit we can't fill the rem sudoku

return false;
}

int main(){

    vector<vector<char>> board(9,vector<char>(9));

    for(int i =0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }

    bool ans = fun(board,0,0);

    for(auto i : board){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

return 0;
}