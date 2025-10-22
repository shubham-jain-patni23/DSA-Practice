#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;

bool checkbit(int x,int pos){
    return x & (1<<pos);
}

int fun(int arr[],int n,int k,int sum){
    if(n==0){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    int x = fun(arr,n-1,k,sum  + arr[n-1]);     // if taking arr[n-1]
    int y  = fun(arr,n-1, k , sum);             // if not-taking arr[n-1]
return x + y;
}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }


    // appraoch 1 ; TC ---> O(n* 2^n)  ; SC ---> O(1)
    int cnt = 0;

    for(int i = 0 ;i<(1<<n) ;i++){
        int curr =0 ;

        for(int j =0;j<n;j++){
            if(checkbit(i,j)){
                curr+= arr[j];
            }
        }
        if(curr==k){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    // approach 2 ; O(2^n) ; O(n) because of using call stack 
    // using recursion considering the sum no. of sub and not considering no. of sub ; 

    cnt = fun(arr,n,k,0);
    cout<<cnt<<endl;


return 0;
}