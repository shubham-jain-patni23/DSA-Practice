#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }


    //approach1 ;          TC---> O(n)+O(n) = O(2n) ==> O(2n) ;           SC ---> O(n)

    vector<int> pos, neg;

    for(int i = 0;i<n;i++){         // O(n)
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    int k = 0;

    for(int i = 0;i<n;i+=2){   //O(n/2)
        arr[i] = pos[k++];
    }

    k = 0;

    for(int i = 1;i<n;i+=2){    //O(n/2)
        arr[i] = neg[k++];
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //approach 2         ; TC ---> O(n)    ; SC ---> O(n)
    //putting all the element to their correct pos in a new array

    vector<int> ans(n);

    int pos = 0, neg = 1;

    for(int i =0;i<n;i++){
        if(arr[i] > 0){
            ans[pos] = arr[i];
            pos+=2;
        }
        else{
            ans[neg] = arr[i];
            neg+=2;
        }
    }

    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


return 0;
}