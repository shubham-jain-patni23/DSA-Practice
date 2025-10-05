#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // approach 1;  TC ---> O(log2col * row)    ; SC ---> O(1)
    // matrix is sorted col-wise , we can apply binary search over cols and check whether in that row 1 exists or not

    int low = 0 , high = m -1 ;
    vector<int> ans  = {0, 0};

    while(low <= high){
        int mid = low + (high - low)/2;

        bool found = false;

        for(int i =0;i<n;i++){
            if(arr[i][mid]==1){
                ans[0] = i;
                ans[1] = m - mid;
                found = true;
                break;
            }
        }

        if(found){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans[0]<<" "<<ans[1]<<endl;


    // same approach but using inbuilt lower_bound()
    int res = -1;
    int curr = 0;

    for(int i =0;i<n;i++){
        int temp = lower_bound(arr[i], arr[i] + m , 1) - arr[i] ; 
        temp = m - temp; ; 
        if(temp > curr){
            curr = temp;
            res = i;
        }
    }

    cout<<res<<" "<<curr<<endl;

return 0 ;
}