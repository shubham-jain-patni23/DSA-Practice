#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // appraoch 1; TC ---> O(nlog2n); SC ---> O(n)
    // to find longest bitcoinic subseq
    // first we can find longest inc subseq till idx i 
    // and then len of longest dec sub till from i + 1 till end if it exits 

    // i means we are considering lis till i then lds from i+ 1 till end

    int ans = 0;

    for(int i =0;i<n-1;i++){        // O(n*nlog2n)

        // considering arr was till idx i only 
        // so we are first finding the lis for arr(0 - i)

        // for every idx j we are finding how many ele can be before it
        vector<int> list;
        for(int j = 0;j<=i;j++){
            int idx = lower_bound(list.begin(),list.end(),arr[j]) - list.begin();

            if(idx==list.size()){
                list.push_back(arr[j]);
            }
            else{
                list[idx] = arr[j];
            }
        }

        int lislen = list.size();
        int lismaxi = list[list.size() -1];

        if(lislen==1){
            continue;
        }

        // now we need to find the lds 
        // lds is nothing but lis in rev direction
        // so now we need to find the lis from (n-1 till i+1);

        vector<int> list1;
        for(int j = n-1;j>=i+1;j--){
            int idx = lower_bound(list1.begin(),list1.end(),arr[j]) - list1.begin();
            if(idx==list1.size()){
                list1.push_back(arr[j]);
            }
            else{
                list1[idx] = arr[j];
            }
        }

        if(lislen >1 && list1[list1.size() -1] < lismaxi){
            ans = max(ans, lislen + (int)list1.size());
        }

    }

    cout<<ans<<endl;

    // approach 2; 
    // we can find the len of lis ending at idx i in O(n^2)
    // then find the len of lis in rev dir till idx i

    ans = 0;

    vector<int> dp1(n,1);
    vector<int> dp2(n,1);

    // finding the len of lis ending at idx i
    for(int i = 0;i<n;i++){
        for(int j =0 ;j<i;j++){
            if(arr[j] < arr[i] && (dp1[j] + 1 > dp1[i])){
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>i;j--){
            if(arr[j] < arr[i] && (dp2[j] + 1 > dp2[i])){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    // lis is ending at i
    for(int i = 0 ;i<n;i++){
        if(dp1[i]==1 || dp2[i]==1 ){
            continue;
        }
        ans = max(ans,  dp1[i] + dp2[i] -1);
    }

    if(ans==1 || ans ==2){
        ans = 0;
    }

    cout<<ans<<endl;

return 0;
}