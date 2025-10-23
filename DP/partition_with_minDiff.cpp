#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

// approach 1; using recursion ; TC ---> O(2^n) ; SC ---> O(n)
// what is the mini abs diff if we take arr[idx] and if we not take arr[idx] in the first arr
// so we only need to decide which one to take in first

int fun(int n,vector<int> &arr,int idx,int cnt,int first,int total){

    if(cnt==(n/2)){
        int second = total - first;
        return abs(first - second);
    }

    // cnt < n/2
    if(idx==n){
        return INT_MAX;
    }

    // if we take arr[idx] in first; what will be the mini abs diff
    int x = fun(n,arr,idx + 1, cnt+1,first + arr[idx], total);

    // if we don't take arr[idx] in first; what will be the mini abs diff
    int y = fun(n,arr,idx + 1,cnt,first,total);


return min(x,y);
}

int fundp(int n,vector<int>&arr,int idx,int cnt,int first,int total,map<vector<int>,int>&dp){

    if(cnt==(n/2)){
        int second = total - first;
        return abs(first - second);
    }

    if(idx==n){
        return INT_MAX;
    }

    vector<int> temp = {idx , cnt, first};
    if(dp.find(temp) != dp.end()){
        return dp[temp];
    }

    int x = fundp(n,arr,idx+1,cnt+1,first+arr[idx],total,dp);
    int y = fundp(n,arr,idx+1,cnt,first,total,dp);

return dp[temp] = min(x,y);
}

int fundp2(int n,vector<int>&arr,int idx,int cnt,int first,int total,vector<vector<vector<int>>>&dp,int neg){
    if(cnt==(n/2)){
        int second = total - first;
        return abs(first - second);
    }
    if(idx == n){
        return INT_MAX;
    }

    if(dp[idx][cnt][first + neg]!=-1){
        return dp[idx][cnt][first+neg];
    }

    int x = fundp2(n,arr,idx+1,cnt+1,first+arr[idx],total,dp,neg);
    int y = fundp2(n,arr,idx+1,cnt,first,total,dp,neg);

return dp[idx][cnt][first + neg] = min(x,y);
}

bool isTrue(int n,vector<int>&arr,int idx,int cnt,int first,int total,int mid){

    if(cnt==(n/2)){
        int second = total - first;
        if(abs(first - second) <= mid){
            return true;
        }
    return false;
    }

    // cnt < n/2
    if(idx==n){
        return false;
    }

    bool x = isTrue(n,arr,idx + 1,cnt+1,first + arr[idx],total,mid);
    bool y = isTrue(n,arr,idx + 1,cnt,first,total,mid);

return (x||y);
}

// push the sum of all the subsets in temp starting from idx
void subsetSum(int n,vector<int>&arr,int idx,int currsum,vector<int>&temp,int cnt,int eleNeed){

    if(idx==n){
        if(cnt==eleNeed){
            temp.push_back(currsum);
        }
        return ;
    }

    // if we take arr[idx]; then push the sum of subsets whichever all formed
    subsetSum(n,arr,idx + 1, currsum+arr[idx], temp,cnt+1,eleNeed);

    // if don't take arr[idx]; then push the sum of all subsets whichever all formed
    subsetSum(n,arr,idx + 1,currsum,temp,cnt,eleNeed);
 
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);  

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    // not correct approach ; as abs(a1 - b1) + abs(a2 - b2) != abs((a1 + a2) - (b1 + b2))
    // sort(arr.begin(),arr.end());

    // int first = 0, second =0 ;
    // bool flag = true;

    // for(int i =0;i<n;i++){
    //     if(flag){
    //         first+=arr[i];
    //     }
    //     else{
    //         second+=arr[i];
    //     }
    //     flag = !flag;
    // }

    // int ans = abs(first - second);
    // cout<<ans<<endl;

    int total = 0 ;
    int pos = 0;
    int neg = 0;

    for(int i =0;i<n;i++){
        total += arr[i];
        if(arr[i]>=0){
            pos+=arr[i];
        }
        else{
            neg+=arr[i];
        }
    }

    // approach 1 

    int ans = fun(n,arr,0,0,0,total);
    cout<<ans<<endl;

    // approach 2; using dp(memoization) ; TC ---> O(n*cnt*total log2(n*cnt*total)) ; SC --->O(n*cnt*total) + O(n)
    // used map to memoize

    map<vector<int>,int> dpp;
    
    ans = fundp(n,arr,0,0,0,total,dpp);
    cout<<ans<<endl;

    // approach 3; using dp(memoization); TC ---> O(n*cnt*(pos + abs(neg))) ; SC ---> O(n*cnt*(pos + abs(neg))) + O(n)

    neg = abs(neg);

    int x = (pos + 1) + neg;
    int cnt = n/2;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(cnt+1, vector<int>(x+1,-1)));
    ans = fundp2(n,arr,0,0,0,total,dp,neg);

    cout<<ans<<endl;

    // approach 4; using recursion and binary serach ; TC ---> O(2^n * log2(pos + abs(neg))) ; SC ---> O(n)
    // mini abs diff can be 0 and maxi can be pos + abs(neg)
    // maxi abs diff is obtained when one goes maxi in +ve dir and other in -ve dif
    // so we can apply binary search on this range [0,pos + abs(neg)] 
    // for any mid we will find whether this abs diff is possible or not
    // so mid will be like target we will find n ele such that sum of n i.e. first and rem i.e second will be like 
    // abs(first - second)==mid

    int low = 0 , high = x;
    ans = x; 

    while(low<=high){
        int mid = low + (high - low)/2;
        if(isTrue(n,arr,0,0,0,total,mid)){
            
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    // approach 2; meet in the middle approach ; TC ---> O(n/2 * (2^(n/2) * n/2)) ; SC ---> O(n/2) + O(n/2) + O(n/2) + O(2^(n/2)) + O(2^(n/2))
    // to minimize the abs diff the subset sum of first arr should be maxi val which is <= total / 2
    // we also need to make sure that we take atleast n ele
    // so we will iterate from 0 to n/2; i.e 0 ele from 1 half and (n/2) from second half

    // dividing the arr in two halves and storing the sum of all subsets for both the halves

    int s = total / 2;

    vector<int> first;
    vector<int> second;

    for(int i =0;i<=((n-1)/2);i++){             // O(n/2)
        first.push_back(arr[i]);
    }
    for(int i = ((n-1)/2) + 1;i<n;i++){         // O(n/2)
        second.push_back(arr[i]);
    }

    ans = INT_MIN;

    // loop signifies i ele from first half and (n/2) - i from the second half
    for(int k = 0;k<=(n/2);k++){

        vector<int> sumfirst;
        vector<int> sumsecond;

        subsetSum((int)first.size(),first,0,0,sumfirst,0,k);        // O(2^(n/2))
        subsetSum((int)second.size(),second,0,0,sumsecond,0,(n/2) - k);     // O(2^(n/2))

        sort(sumsecond.begin(),sumsecond.end());            // O(2^(n/2) * (n/2))

        for(int i = 0;i<sumfirst.size();i++){       // O(2^(n/2) * (n/2))
    
            int x = sumfirst[i];
            int y = s - x;         // y is maxi possible subset sum allowed from second half

            int idx = lower_bound(sumsecond.begin(),sumsecond.end(),y) - sumsecond.begin();

            if(idx==sumsecond.size() || sumsecond[idx] > y){
                idx--;
            }

            if(idx==-1){
                continue;
            }

            int curr = x + sumsecond[idx];
            ans = max(ans, curr);
        }
        sumfirst.clear();
        sumsecond.clear();
    }

    int second_part = total - ans;
    ans = abs(ans - second_part);

    cout<<ans<<endl;

return 0;
}