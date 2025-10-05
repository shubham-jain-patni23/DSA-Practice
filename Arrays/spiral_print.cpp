#include<iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int row_min = 0, row_max = n-1;
    int col_min = 0, col_max = m-1;

    while(row_min<= row_max && col_min<=col_max){           //TC ---> O(n*m)   //SC ---> O(1)

        //printing top row
        for(int i = col_min; i <= col_max;i++){
            cout<<arr[row_min][i]<<" ";
        }
        row_min++;
        
        //printing last col
        for(int i = row_min;i<=row_max;i++){
            cout<<arr[i][col_max]<<" ";
        }
        col_max--;

        if(row_min<=row_max){
            //printing last row
            for(int i = col_max;i>=col_min;i--){
                cout<<arr[row_max][i]<<" ";
            }
            row_max--;
        }

        if(col_min<=col_max){
            //printing first col
            for(int i = row_max;i>=row_min;i--){
                cout<<arr[i][col_min]<<" ";
            }
            col_min++;
        }
    }



return 0;
}