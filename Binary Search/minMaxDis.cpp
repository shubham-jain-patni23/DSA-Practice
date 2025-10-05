#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<queue>
using namespace std;

bool isTrue(int arr[],int n,int k,long double mid){

    int cnt = 0 ;

    for(int i = 1;i<n;i++){
        long double dis  = arr[i] - arr[i-1];
        int req = ceil(dis/ mid) ;
        req--;

        cnt+= req;
        if(cnt > k){
            return false;
        }
    }
return true;
}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];

    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
    }

    int maxi = 0;

    for(int i = 1;i<n;i++){
        maxi = max(maxi , arr[i] - arr[i-1]);
    }

    // approach 1;    TC ---> O(k * n) + O(n)    ; SC ---> O(n)
    // we can iterate over no of extra stations and place it where the section len is max

    //each sec len 
    vector<int> sec(n-1,0); 

    for(int i = 1;i<=k;i++){
        long double maxidx = -1;
        long double maxi = -1;

        for(int i = 0;i<n-1;i++){
            long double diff = (long double)arr[i+1] - (long double)arr[i];
            long double seclen  = diff / (sec[i] + 1);
            if(seclen > maxi){
                maxi = seclen;
                maxidx = i;
            }
        }
        if(maxidx >= 0){
            sec[maxidx]++;
        } 
    }

    long double ans = 0;

    for(int i = 0;i<n-1;i++){
        long double diff = (long double)arr[i+1] - (long double)arr[i];
        long double seclen  = diff / (sec[i] + 1);
        ans = max(ans, seclen);
    }

    ans = round(ans * 100.0) / 100.0;

    cout<<ans<<endl;

    // approach 2;          TC ---> O(nlog2n) + O(k * log2n)   ; SC ---> O(n-1)

    // in a I am pushing curr sec len, idx of the sec , and the extra stations used
    // and for every extra station I am popping the sec with the max len and updating its len after adding an extra startion

    priority_queue<vector<long double>> pq;
    for(int i = 0;i<n-1;i++){
        long double x = arr[i+1] - arr[i];
        pq.push({x,(long double)i,(long double)0});
    }

    for(int i = 1;i<=k;i++){
        if(pq.size() <= 0){
            break;
        }
        vector<long double> temp = pq.top();
        pq.pop();
        temp[2]++;
        int idx = temp[1];
        long double newdis = (long double)(arr[idx + 1] - arr[idx]) / (temp[2] + 1);

        pq.push({newdis, (long double)idx, temp[2]});
    }

    vector<long double> temp = pq.top();

    if(pq.size()>=1){
        ans = pq.top()[0];
    }
    else{
        ans = 0;
    }

    ans = round(ans * 100.0) / 100.0;

    cout<<ans<<endl;

    //approach 3; TC ---> O(maxi * n) ; if we iterate over the dis from 0 to maxi and check 

    // approach 4;  TC ---> O(log2(maxi) * n)    ; SC ---> O(1)
    // we min dis theoretically can be zero two stations and the max dis is what which is already there b/w the stations
    // so we can apply binary search over the range 0 to maxi and then check whether with k extra stations can the mini dis mid be achieved or not
    // if in this case instead of bs if we want to do linear search then we can iterate over 0 to maxi ; updating i by 10^-6

    long double low = 0 , high = maxi;
    long double x = 1e-9;

    while((high - low) >= x){
        long double mid = low + (high - low)/2;

        if(isTrue(arr,n,k,mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }    

    // round fun does round off to the nearest integer , in addition  round(1.5) will be 2;
    // so the num(pow of 10) which we multiply saves the deciplaces required and then the round fun does round off 
    // and then again div returns the no till the required precision
    low = round(low * 100.0) / 100.0;

    cout<<low<<endl;

return 0 ;
}