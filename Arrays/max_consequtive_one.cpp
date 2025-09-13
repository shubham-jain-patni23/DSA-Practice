#include<iostream> 
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }

    //approach 1
    //Time complexity : O(n) but here comparisons(for max ans) will be = no of ones
    //Space complexity : O(1)

    int first = -1;
    int ans = 0;

    for(int i =0;i<n;i++){
        if(arr[i]==1){
            if(first==-1){
                first = i;
            }
            ans= max(ans , i - first + 1);
        }
        if(arr[i]==0){
            first = -1;
        }
    }

    cout<<ans<<endl;

    //or 
    ans = 0 ;
    int cnt = 0;

    for(int i = 0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            ans = max(ans, cnt);
        }
        else{
            cnt = 0;
        }
    }


    cout<<ans<<endl;

    //approach 2
    //Time complexity : O(n) but here comparison will be = no of groups of 1

    first = -1; 
    ans = 0;

    for(int i =0;i<n;i++){
        if(arr[i]==1){
            first = i;
            while(arr[i]==1 && i < n){
                i++;
            }
            ans = max(ans, i - first);
        }
    }

    cout<<ans<<endl;

return 0;
}