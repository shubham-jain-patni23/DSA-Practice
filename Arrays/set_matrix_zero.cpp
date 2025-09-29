#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<int> row,col;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==0){
                row.push_back(i);
                col.push_back(j);
            }
        }   
    }

    for(auto i : row){
        for(int j = 0;j<m;j++){
            arr[i][j] = 0; 
        }
    }

    for(auto j : col){
        for(int i =0;i<n;i++){
            arr[i][j] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}