#include<iostream> 
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1
    int currsum ;
    int ans = 0;

    for(int i =0;i<n;i++){         //Time complexity : O(n^2) 
        currsum = 0;               //Space complexity : O(1)
        for(int j = i;j<n;j++){
            currsum+= arr[j];
            if(currsum == k){
                ans = max(ans , j - i + 1);
                break;
            }
            else if(currsum > k ){
                break;
            }
        }
    }

    cout<<ans<<endl;


    //approach 2
    ans = 0 ;
    currsum = 0;

    int i = 0; 
    int j  = 0;

    while(j < n){                       //Time complexity : O(2n) = O(n)
        currsum+=arr[j];                //Space complexity : O(1)
        if(currsum > k){
            while(i<=j && currsum > k){
                currsum-= arr[i];
                i++;
            }
        }
        if(currsum==k){
            ans = max(ans, j - i + 1);
        }
        j++;
    }

    cout<<ans<<endl;

    //for array including -ve numbers 

    //approach 1
    ans = 0;
    currsum ;

    for(int i = 0;i<n;i++){                         //Time complexity : O(n^2)
        currsum = 0;                                //Space complexity : O(1) 
        for(int j = i;j<n;j++){
            currsum+=arr[j];
            if(currsum==k){
                ans = max(ans , j - i + 1);
            }
        }
    }

    cout<<ans<<endl;

    //approach 2

    cout<<endl;
    cout<<endl;

    ans = 0;

    // int pre[n + 1];
    // pre[0] = 0;

    // for(int i = 1;i<=n;i++){
    //     pre[i] = pre[i-1] + arr[i-1];
    // }

    //is correct only for +ve integers as there can be same prefix sum at multiple indices if there are zeros or -ve integers if 
    //map is updates for the same prefix sums that comes afterwards

    map<long long,int> mp;
    currsum = 0 ;

    for(int i = 0;i<n;i++){         
        currsum+=arr[i];
        if(currsum==k){
            ans = max(ans , i + 1);
        }
        long long rem = currsum - k ; 

        if(mp.find(rem)!=mp.end()){             
            int len = i - mp[rem];
            ans = max(ans , len);
        }
        
        if(mp.find(currsum)==mp.end()){         //it is the condition to store the leftmost indices in case of duplicate prefix sums
            mp[currsum] = i;
        }

    }

    cout<<ans<<endl;

    ans = 0;

    map<int,int> mpp;

    currsum = 0;

    for(int i = 0 ;i<=n;i++){
        currsum+=arr[i];
        if(currsum==k){
            ans = max(ans, i + 1);
        }
        else{
            int x = currsum - k ;
            if(mpp.find(x)!=mpp.end()){
                ans = max(ans, i - mpp[x]);
            }
        }
        if(mpp.find(currsum)==mpp.end()){
            mpp[currsum] = i;
        }
    }

    cout<<ans<<endl;

    //if we want something that start with a particular idx;

    currsum = 0;
    ans = 0;

    map<int,int> m;

    for(int i = n-1;i>=0;i--){
        currsum+=arr[i];
        if(currsum==k){
            ans = max(ans , n - i);
        }
        else{
            int x = currsum - k;
            if(m.find(x)!=m.end()){
                ans = max(ans, m[x] - i);
            }
        }
        if(m.find(currsum)==m.end()){
            m[currsum] = i;
        }
    }
  
    cout<<ans<<endl;

return 0;
}