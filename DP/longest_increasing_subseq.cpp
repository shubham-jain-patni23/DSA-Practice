#include<iostream>
#include<climits>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

// approach 1; TC ---> O(2^n); SC ---> O(n)

// fun(i,prev) means what is the maxi len inc subseq which we can get 
// starting from idx i 
// when the previous ele was prev
int fun2(int idx,vector<int> &arr,int prev){

    if(idx==arr.size()){
        return 0;
    }

    // don't take it 
    int x = fun2(idx + 1, arr, prev);

    // take it
    if(arr[idx] > prev){
        int y = 1 + fun2(idx + 1, arr, arr[idx]);
        x = max(x,y);
    }
return x;
}

int fundp2(int idx,vector<int> &arr,int prev,map<pair<int,int>,int> &mp){

    if(idx==arr.size()){
        return 0;
    }

    if(mp.find({idx,prev})!=mp.end()){
        return mp[{idx,prev}];
    }


    // don't take it 
    int x = fundp2(idx + 1, arr, prev,mp);

    // take it
    if(arr[idx] > prev){
        int y = 1 + fundp2(idx + 1, arr, arr[idx],mp);
        x = max(x,y);
    }
return mp[{idx,prev}] = x;
}

int fun(int idx,vector<int>&arr,int previdx){
    if(idx==arr.size()){
        return 0;
    }
    if(previdx > idx){
        return 0;
    }
    // don't take it 
    int x = fun(idx + 1, arr, previdx);

    // take it
    if(previdx==-1 || arr[idx] > arr[previdx]){
        int y = 1 + fun(idx + 1, arr, idx);
        x = max(x, y);
    }
return x;
}

int fundp(int idx,vector<int>&arr,int previdx,vector<vector<int>>&dp){
    if(idx > arr.size()){
        return 0;
    }

    if(previdx >= idx){
        return 0;
    }

    if(dp[idx][previdx]!=-1){
        return dp[idx][previdx];
    }

    // don't take it 
    int x = fundp(idx + 1, arr, previdx,dp);

    // take it
    if(previdx== 0 || arr[idx -1] > arr[previdx-1]){
        int y = 1 + fundp(idx + 1, arr,idx,dp);
        x = max(x, y);
    }
return dp[idx][previdx] = x;
}

int funidx(vector<set<int>> &v, int ele){       // O(log2n)

    int low = 0, high = v.size() -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int x = *(v[mid].begin());      // O(1)
        
        if(x==ele){
            return mid;
        }
        else if(x < ele){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
return low;
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1
    int ans = fun(0,arr,-1);
    cout<<ans<<endl;

    // appraoch 2; using dp(memoiztion); O(n*nlogn); SC ---> O(n*nlogn) + O(n)
    // memoizing using map

    map<pair<int,int>,int> mp;
    ans = fundp2(0,arr,INT_MIN,mp);
    cout<<ans<<endl;

    // approach 3; using dp(memoization); TC ---> O(n^2); SC ---> O(n^2) + O(n)
    // instead of storing prev ele we can store its idx,
    vector<vector<int>> dpp(n+1,vector<int>(n+1,-1));
    ans = fundp(1,arr,0,dpp);
    cout<<ans<<endl;

    // approach 4; using dp(tabulation); TC ---> O(n*n); SC ---> O(n*n)
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    dp[n][0] = 1;
    for(int i = 1;i<n;i++){
        if(arr[i-1] < arr[n-1]){
            dp[n][i] = 1;
        }
    }

    // dp[i][j] means what is maxi len inc subseq that we can get from idx i if prev ele was j
    for(int i = n-1;i>0;i--){
        for(int j = 0;j<i;j++){
            // don't take it
            int x = dp[i+1][j];
            // take it
            if(j==0 || arr[j-1] < arr[i-1]){
                int y = 1 + dp[i+1][i];
                x = max(x,y);
            }
            dp[i][j] = x;
        }
    }

    cout<<dp[1][0]<<endl;

    for(auto i : dp){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    // approach 5; space optimization; TC ---> O(n*n); SC ---> O(n)

    vector<int> curr(n+1,0);
    curr[0]  = 1;
    for(int i = 1;i<n;i++){
        if(arr[i-1] < arr[n-1]){
            curr[i] = 1;
        }
    }

    for(int i = n-1;i>0;i--){
        for(int j = 0;j<=n;j++){
            if(j>=i){
                curr[j] = 0;
            }
            else{
                // don't take it
                int x = curr[j];
                // take it
                if(j==0 || arr[j-1] < arr[i-1]){
                    int y = 1 + curr[i];
                    x = max(x,y);
                }
                curr[j] = x;
            }  
        }
    }
    cout<<curr[0]<<endl;

    
    // approach 6; using set and binary search; TC ---> O(nlog2n); SC ---> O(n)
    // every idx of vector v is denoting a pos
    // ele at any idx i tells that there can be i ele before me
    // before me means (which are smaller and which came earlier in arr)
    // for all ele at idx i in vector v there will be i ele which came earlier than that ele and which are also smaller
    // there will be an ele which will have maxi ele before that
    // so idx of that maxi ele + 1 will maxi len of increasing subseq
    // we are using set because at each idx i.e. pos we will check whether 
    // curr ele is greater than mini ele of that pos
    // if greater than it can come at greater pos
    // curr ele is smaller than mini ele of that pos
    // than curr ele have to come at some smaller pos
    // if curr ele is eq to mini ele of that pos 
    // that curr ele will also come at that pos
    // to search the correct pos of any ele 
    // we can use binary serach over the idices of the vector v
    // so for every ele we are finding the longest increasing subseq ending at that ele

    vector<set<int>> v;
    
    for(int i = 0;i<n;i++){             // O(n*(log2n + log2n)) = O(2nlog2n) ==> O(nlog2n)
        int idx = funidx(v,arr[i]); // O(log2n)

        if(idx == v.size()){        // O(log2n)
            set<int> temp;
            temp.insert(arr[i]);   // O(log2n)
            v.push_back(temp);  
        }
        else{
            v[idx].insert(arr[i]);  // O(log2n)
        }
    }

    ans = v.size();
    cout<<ans<<endl;

    // approach 7; if we don't use set or min_heap in approach 6; O(n^2) ; SC ---> O(n)
    // dp[i] means len of lis ending at arr[i]

    vector<int> dp2(n,1);
    ans = 1;

    for(int i= 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j] < arr[i]){
                dp2[i] = max(dp2[i] , 1 + dp2[j]);
            }
        }
        ans = max(ans,dp2[i]);
    }

    cout<<ans<<endl;

    // approach 8;  TC ---> O(nlog2n); SC ---> O(n)
    // we are having a sorted list, which ensures smallest possible tail at any moment
    // whenever an greater ele than last ele of list comes 
    // then the list grows
    // whenever smaller ele comes then it says
    // it can help make this much len
    // and some greater than me and smaller than you can help grow list even more
    // This ensures the smallest possible tail for subsequences of length idx + 1
    // and in the last sz of list will be the sz of lis

    vector<int> list;

    for(int i =0;i<n;i++){      // O(nlog2n)
        int idx = lower_bound(list.begin(),list.end(),arr[i]) - list.begin();    // O(log2n)
        if(idx==list.size()){
            list.push_back(arr[i]);
        }
        else{
            list[idx] = arr[i];
        }
    }

    cout<<list.size()<<endl;

return 0;
}