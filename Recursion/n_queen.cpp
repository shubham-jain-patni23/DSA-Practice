#include<iostream>
#include<string>
#include<vector>
using namespace std;

// approach 1; O(n^n) * O(n)  ; SC ---> O(n) + O(n)
// we want to place a queen in each row starting from first row, fun tries to place a row in a cell and checks if other rows can be placed or not

bool isTrue(int n, int row,int col ,vector<string> temp){
    for(int i = 0 ; i < row;i++){
        if(temp[i][col]=='Q'){
            return false;
        }
    }

    int i = row - 1, j = col - 1;
    while(i>=0 && j>=0){
        if(temp[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i = row -1, j = col + 1;
    while(i>=0 && j<n){
        if(temp[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
return true;
}

bool fun(int n,int row,vector<string>temp,vector<vector<string>> &ans){     //O(n) + O(n) + O(n) = O(3n) ; SC --->O(1)
    if(row==n){
        ans.push_back(temp);
        return true;
    }

    bool flag= false;

    for(int i =0 ;i<n;i++){
        if(isTrue(n,row,i,temp)){
            temp[row][i] = 'Q';
            bool x = fun(n, row+1, temp, ans);
            if(x==1){
                flag = true;
            }
            temp[row][i] = '.';
        }
    }
return flag;
}

int main(){

    int n;
    cin>>n;

    vector<vector<string>> ans;
    vector<string>temp(n);

    for(int i =0 ;i<n;i++){
        temp[i] = "";
        for(int j= 0 ;j<n;j++){
            temp[i]+='.';
        }
    }

    fun(n,0,temp,ans);
    
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<endl;
        }cout<<endl;
    }

return 0;
}