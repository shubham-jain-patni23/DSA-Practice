#include<iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    //approach 1 ; iterating from 1 to m   ; TC ---> O(m * n)  ; SC ---> O(1)

    int ans = -1;
    
    for(int i =  1;i<=m;i++){
        int curr = 1;
        for(int j = 1;j<=n;j++){
            curr = curr * i;
        }
        if(curr==m){
            ans = i;
            break;
        }
        if(curr > m){
            break;
        }
    }

    cout<<ans<<endl;

    //approach 2 ; using binary search over range 1 to m;    TC ---> O(log2m * n)    ; SC ---> O(1)
    ans = -1;

    int low = 1, high = m;

    while(low<=high){
        int mid = low + (high - low)/2;
        long long curr = 1;
        for(int j = 1;j<=n;j++){        //instead of this loop we can also use inbuilt pow fun with theoretical TC O(1)
            curr =1LL * curr * mid;
        }
        if(curr == m){
            ans = mid;
            break;
        }
        else if(curr > m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;


return 0 ;
}