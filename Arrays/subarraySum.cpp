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

    //approach 1, checking all the subarrays   ; TC ---> O(n^2)   ; SC ---> O(1)

    int cnt = 0;
    
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum+= arr[j];
            if(sum==k){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;


    //approach2 , using prefix array and maps ; TC ---> O(nlogn) ; SC --->O(n)

    map<int,int> mp;

    int sum = 0;
    cnt = 0;

    mp[0]++;

    for(int i =0;i<n;i++){
        sum+= arr[i];
        int temp = sum - k;

        // if(mp.find(temp)!=mp.end()){
        //     cnt+= mp[temp];
        // }
        // it can also update cnt directly
        cnt+= mp[temp];
        mp[sum]++;
    }

    cout<<cnt<<endl;

return 0;
}