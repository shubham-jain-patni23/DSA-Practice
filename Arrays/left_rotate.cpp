#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int d; 
    cin>>d;

    int arr[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    int temp[d];                //Time complexity : O(d) + O(n - d) + O(d) = O(n + d)
    for(int i = 0;i<d;i++){     //Space complexity : O(d)
        temp[i] = arr[i];
    }

    for(int i = d;i<n;i++){
        arr[i - d] = arr[i];
    }
    //int k = 0;
    for(int i = n - d; i<n;i++){
        //arr[i] = temp[k++];
        arr[i] = temp[i - (n - d)];
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int prev = arr[0];

    for(int i=0;i<(n-1);i++){           //Time complexity : O(n) 
        arr[i] = arr[i+1];              //Space complexity : O(N) in the algorithm but the extra space is O(1)
    }
    arr[n-1] = prev;

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int tempp[n];

    for(int i =0;i<n;i++){              //Time complexity: O(n);
        int x = (i - d + n)  % n;       //Space Complexity : O(n)
        tempp[x] = arr[i];      
    }

    for(auto it  : tempp){
        cout<<it<<" ";
    }

    cout<<endl;

    reverse(arr, arr + d);              

    reverse(arr + d, arr + n);          

    reverse(arr, arr + n);              //Time complexity : O(2n) = O(n) and space complexity : O(1) 

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    //right rotation

    reverse(arr,arr + (n -d) );
    reverse(arr + (n  -d), arr + n);            //Time complexity : O(2n) i.e. O(n)
    reverse(arr, arr + n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}