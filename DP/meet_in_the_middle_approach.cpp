#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

// We are given an arr and s, we need to find a subset which has maxi sum but not more than s 
// and return the sum of the subset

// approach 1; using recursion ; TC ---> O(2^n) ; SC ---> O(n)

int fun(int n,vector<int>&arr,int idx,int currsum,int s){

    if(idx==n){
        return currsum;
    }

    // if don't take arr[idx]; then what will be the maxi subset sum <= s
    int x = fun(n,arr,idx + 1, currsum, s);

    // if we take arr[idx]; then what will be the maxi subset sum <= s
    if(arr[idx] + currsum <= s){
        int y = fun(n,arr,idx + 1,currsum + arr[idx], s);
        x = max(x, y);
    }
return x;
}

// push the sum of all the subsets in temp starting from idx
void subsetSum(int n,vector<int>&arr,int idx,int currsum,vector<int>&temp){

    if(idx==n){
        temp.push_back(currsum);
        return ;
    }

    // if we take arr[idx]; then push the sum of subsets whichever all formed
    subsetSum(n,arr,idx + 1, currsum+arr[idx], temp);

    // if don't take arr[idx]; then push the sum of all subsets whichever all formed
    subsetSum(n,arr,idx + 1,currsum,temp);
 
}

int main(){

    int n;
    cin>>n;

    int s;
    cin>>s;

    vector<int> arr(n);  

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    // approach 1
    int ans = fun(n,arr,0,0,s);
    cout<<ans<<endl;

    // dp can't be applied 
    // here we need to work on two var ; idx and currsum
    // currsum can be -ve
    // so we can't have a dp table of size (n * s)

    // approach 2; TC ---> O(n/2) + O(n/2) + O(2^(n/2)) + O(2^(n/2)) + (2^(n/2) * (n/2)) + (2^(n/2) * (n/2)) ==> O(2^(n/2) *(n/2)); 
    // SC ---> O(n/2) + O(n/2) + O(n/2)(stack space) + O(2^(n/2)) + O(2^(n/2))
    // meet in the middle approach 
    // 2^n is very costly, so instead of finding the subsets for the complete arr 
    // we find for the two halves each will cost 2^(n/2) (2^(n/2) * 2^(n/2) == 2^n)
    // for each subset sum in first half, we will find the subset with maxi possible sum in second half such that sum of both doesn't exceed s
    // if we do it iteratively it will cose 2^(n/2) * 2^(n/2) == 2^n
    // so we will not do it iteratively 
    // as we need to search in second arr, so we will first sort the second half
    // after sorting the second half, we will search for the subset with sum <= (s - subsetSum_from_firstHalf)

    // Step 1: divide arr in two halves and find subset sum for both
    // Step 2: sort 2nd arr
    // Step 3: for each subset sum from first half find the subset sum from second arr using binary search 
    // Maintain a var ans initialized with INT_MIN, as s may be -ve so INT_MIN will be <= s initially


    // dividing the arr in two halves and storing the sum of all subsets for both the halves

    vector<int> first;
    vector<int> second;

    for(int i =0;i<=((n-1)/2);i++){             // O(n/2)
        first.push_back(arr[i]);
    }
    for(int i = ((n-1)/2) + 1;i<n;i++){         // O(n/2)
        second.push_back(arr[i]);
    }

    vector<int> sumfirst;
    vector<int> sumsecond;

    subsetSum((int)first.size(),first,0,0,sumfirst);        // O(2^(n/2))
    subsetSum((int)second.size(),second,0,0,sumsecond);     // O(2^(n/2))

    // sorting the subset sum arr of the second half

    sort(sumsecond.begin(),sumsecond.end());            // O(2^(n/2) * (n/2))

    // iterating over the subsetsums of first half and finding the maxi possible subset sum in the second half
    // such that sum of both <= 
    
    ans = INT_MIN;

    for(int i = 0;i<sumfirst.size();i++){       // O(2^(n/2) * (n/2))
        int x = sumfirst[i];
        if(x > s){
            continue;
        }
        int y = s - x;         // y is maxi possible subset sum allowed from second half
        int idx = lower_bound(sumsecond.begin(),sumsecond.end(),y) - sumsecond.begin();
        if(idx==sumsecond.size() || arr[idx] > y){
            idx--;
        }
        int curr = x;
        if(idx!=-1){
            curr+= arr[idx];
        }
        ans = max(ans, curr);
    }

    cout<<ans<<endl;
    
return 0;
}