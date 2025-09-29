#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int arr1[n+m] = {0};
    int arr2[m];
    
    int x;
    for(int i =0;i<n;i++){
        cin>>x;
        arr1[i] = x;
    }

    for(int j = 0;j<m;j++){
        cin>>arr2[j];
    }

    //approach 1; filled all the ele of arr2 in arr1 and sorted arr1   ; TC ---> O((n+m)log(n+m))   ; SC ---> O(1)

    // for(int i = n ; i< m + n;i++){
    //     arr1[i] = arr2[i - n];
    // }

    // sort(arr1, arr1+(m + n));

    // for(int i =0;i<(m + n);i++){
    //     cout<<arr1[i]<<" ";
    // }

    //approach 2, using 2 pointers comparing the greatest ele from last and putting in arr1  ; TC ---> O(n + m) ; SC ---> O(1)

    int i = n-1, j = m-1;
    int idx = (n + m) - 1;

    while(i >=0 && j>=0){
        if(arr1[i] >= arr2[j]){
            arr1[idx] = arr1[i];
            i--;
        }
        else{
            arr1[idx] = arr2[j];
            j--;
        }
        idx--;
    }

    while(j>=0){
        arr1[idx] = arr2[j];
        j--;
        idx--;
    }

    for(int i =0;i<(m + n);i++){
        cout<<arr1[i]<<" ";
    }

return 0 ;
}