#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int target;
    cin>>target;

    int arr[n][m];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // approach 1;       TC ---> O(n + m)  ; SC ---> O(1)
    // starting from the end of first row traversing the arr

    int i = 0, j = m- 1;

    bool ans = false;

    while(i<n && j>=0){
        int curr = arr[i][j];
        if(curr == target){
            ans = true;
            break;
        }
        else if(curr > target){
            j--;
        }
        else{
            i++;
        }
    }

    cout<<ans<<endl;

    // approach 2;   TC ---> O(log2n) + O(log2m)  ===> O(log2n*m)    ; SC ---> O(1)
    // first find row using binary search and then in that row find the ele again using the binary search 
    // it work only when the first ele of any row is greater than the last ele of prev row

    ans = false;

    if(target < arr[0][0] && target > arr[n-1][m-1]){
        
    }
    else{

        //applying bs over rows 

        int low = 0, high = n-1;
        int row = -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(target >= arr[mid][0] && target<= arr[mid][m-1]){
                row = mid;
                low = mid + 1;
            }
            else if(target < arr[mid][0]){
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }

        if(row == -1){
        }
        else{
            //applying bs int a row
            low = 0 , high = m -1 ;

            while(low<=high){
                int mid = low + (high - low)/2;
                if(target==arr[row][mid]){
                    ans =true;
                    break;
                }
                else if(target > arr[row][mid]){
                    low =mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
        }
    }

    cout<<ans<<endl;

    // approach 3; 
    // we can imagine 2d array as an 1d (row - major); 
    // it will be like a 1d array of size n*m 
    // apply bs over it to search the ele, but it work only when the first ele of any row is greater than the last ele of prev row

    int low = 0 , high = n*m;
    ans = false;

    if(n==0){
        high  = m;
    }
    if(m==0){
        high = n;
    }

    while(low<=high){
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;

        if(arr[row][col]==target){
            ans =true;
            break;
        }
        else if(arr[row][col] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0 ;
}