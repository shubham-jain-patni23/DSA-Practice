#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1 : here we are having a counter like where does the line ended last with a num.

    int cnt = 0;

    int last = -1;

    for(int i = 0;i<n;i++){             //O(n) + O(n) = O(2n) i.e O(n)
        if(arr[i]!=0){
            last++;
            arr[last] = arr[i];
        }
        else{
            cnt++;
        }
    }

    while(cnt--){
        last++;
        arr[last] = 0;
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    //approach 2; if we find any non-zero num after zero then we will shift it to the left and shift j by one 
    // as after j there can't be any no. as why would any no. be after zero as there is place and we have shifted them 

    int j = -1;

    for(int i =0;i<n;i++){
        if(arr[i]==0){      //O(j)
            j = i;
            break;
        }
    }

    if(j!=-1){
        for(int i = j + 1;i<n; i++){        //O(n - j) so; Time complexity  = O(n);
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

return 0;    
}