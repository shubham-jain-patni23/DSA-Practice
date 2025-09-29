#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }


    //approach 1  time complexity = O(n) ; space complexity = O(1);

    int low = -1;
    int high = n;

    int curr = 0;

    while(curr < high){
        if(arr[curr]==1){
            curr++;
        }
        else if(arr[curr]==0){
            low++;
            swap(arr[curr],arr[low]);
            curr++;
        }
        else{
            high--;
            swap(arr[curr],arr[high]);
        }
    }

    for(int i =0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;


    //approach 2;  time complexity = O(2n) = O(n) and space complexity = O(1)

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int i =0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }

    int i =0;

    while(cnt0--){
        arr[i] = 0;
        i++;
    }

    while(cnt1--){
        arr[i] = 1;
        i++;
    }

    while(cnt2--){
        arr[i] = 2;
        i++;
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //same as first approach just here we are considering 0's before the low and 2's after the high

    // int low = 0;
    // int high = n-1;
    // int curr = 0;

    // while(curr <= high){
    //     if(arr[curr]==1){
    //         curr++;
    //     }
    //     else if(arr[curr]==0){
    //         swap(arr[curr], arr[low]);
    //         low++;
    //         curr++;
    //     }
    //     else{
    //         swap(arr[curr],arr[high]);
    //         high--;
    //     }
    // }

    // for(int i = 0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

return 0 ;    
}