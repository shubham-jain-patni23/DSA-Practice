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

    //approach1 ; TC ---> O(n*m) + O(n*m) = O(2n*m)     ; SC ---> O(n) + O(m) = O(n + m) if we are using row and col otherwise O(1)
    //vector<int> row(n,0), col(m,0);

    //instead of separately having row and col vectors we can marks the last ele of row or col

    //for first col we can have seperate var
    int col = -1;

    for(int i = 0;i<n;i++){         //O(n*m)
        for(int j = 0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
                if(j!=0){
                    arr[0][j] = 0;
                }
                else{
                    col = 0 ;
                }
            }
        }   
    }

    // for(auto i : row){                  //O(n*m)
    //     for(int j = 0;j<m;j++){
    //         arr[i][j] = 0; 
    //     }
    // }

    // for(auto j : col){              //O(n*m)
    //     for(int i =0;i<n;i++){
    //         arr[i][j] = 0;
    //     }
    // }

    //insead of doing for each row and col we can loop over ele 

    for(int i = n-1;i>=0;i--){              //O(n*m)
        for(int j = m-1;j>=0;j--){
            if(arr[i][0] ==0 ){
                arr[i][j] = 0;
            }
            else{
                if(j !=0){
                    if(arr[0][j]==0){
                        arr[i][j] = 0;
                    }
                }
                else{
                    if(col==0){
                        arr[i][j] = 0;
                    }
                }
            }
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