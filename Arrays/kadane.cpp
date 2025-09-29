#include<iostream>
#include<climits>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }

    //printing sum of all subarrays
    //approach1; brute force finding sum of all subarray ; TC --> O(n^2)    ;SC ---> O(1)

    int ans = arr[0];

    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+=arr[j];
            ans = max(ans, sum);
            //cout<<sum<<" ";
        }
        //cout<<endl;
    }
    cout<<"approach1 : "<<ans<<endl;


    //if all the +ve then the array itselft will be the subarray with max sum

    //approach2 ;   TC--> O(n)        ; SC --> O(1)

    //to get the max sum I will go adding the ele and if at any point sum becomes <0 I will make it zero, as now 
    //it will have no contribution to the sum to make it big as I am updaing the ans in every iteration


    //kadane's algorithm

    ans = INT_MIN;
    int curr = 0;

    int start = 0, end = 0;
    int currstart = 0;

    //currstart is always initialized when the sum is zero, as otherwise we will carry the previour subarray only 
    for(int i =0;i<n;i++){
        // if(curr==0){
        //     currstart = i;
        // }

        curr+= arr[i];

        if(curr > ans){
            start = currstart;
            end = i;
            ans = curr;
        }

        if(curr < 0){
            curr = 0;
            currstart = i + 1;              //also printing the subarray with max sum
        }

    }

    cout<<start<<" "<<end<<endl;   
    
    //printing subarray with max sum
    for(int i = start;i<= end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"approach2 : "<<ans<<endl;


return 0 ;
}