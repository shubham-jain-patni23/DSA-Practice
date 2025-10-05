#include<iostream>
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

    //approach 1; checking every ele ;   TC---> O(n*m) ; SC ---> O(1)

    // approach 2;    TC ---> O((log2n) * m)   ; SC ---> O(1)
    // apply bs over the rows to sel a row and then in a row we will find the max ele
    // maxi ele in a row will be peak of that row now we will check up and down rows and we will move in that row
    // as for that row left , right and up/down will be lesser, we need to check only one 
    // if that is also lower then peak is found otherwise move further

    //first intuitive approach 
    vector<int> ans(2,-1);

    int low = 0 , high = n-1;

    bool up = false;
    bool down = false;
    bool found = false;

    while(low<=high){

        int mid = low + (high - low)/2;     //mid is the row no.

        for(int i = 0;i<m;i++){     //i is the col no.
            if(((i==0) || (arr[mid][i-1] < arr[mid][i])) && ((i==m-1) || (arr[mid][i+1] < arr[mid][i]))){

                //cout<<mid<<" "<<i<<" "<<arr[mid][i]<<endl;

                if(((mid==0) || (arr[mid-1][i] < arr[mid][i])) && ((mid==n-1) || (arr[mid+1][i] < arr[mid][i]))){
                    //cout<<mid<<" "<<i<<" "<<arr[mid][i]<<endl;
                    ans[0] = mid;
                    ans[1] = i;
                    found = true;
                    break;
                }
                else if((mid < n-1) && (arr[mid+1][i] > arr[mid][i])){
                    up = true;
                    down = false;
                }
                else{
                    down = true;
                    up  = false;
                }
            }
        }
        if(found){
            break;
        }
        else if(up){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }

    cout<<ans[0]<<" "<<ans[1]<<endl;

    //second approach  

    low = 0 , high = n-1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int maxidx = 0;
        int maxi = arr[mid][0];

        for(int i =0;i<m;i++){
            if(arr[mid][i] > maxi){
                maxi = arr[mid][i];
                maxidx = i;
            }
        }

        if(((mid==low) || (arr[mid-1][maxidx] < arr[mid][maxidx]))  && ((mid==high) || (arr[mid+1][maxidx] < arr[mid][maxidx]))){
            ans[0] = mid;
            ans[1] = maxidx;
            break;
        }

        if(mid < high && arr[mid + 1][maxidx] > arr[mid][maxidx]){
            low = mid + 1;
        }
        else{
            high = mid  - 1;
        }
    }

    cout<<ans[0]<<" "<<ans[1]<<endl;

return 0 ;
}