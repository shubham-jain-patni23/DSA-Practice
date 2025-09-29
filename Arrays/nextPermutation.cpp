#include<iostream>
#include<algorithm>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach1 : using inbuilt next_permutation function
    //next_permutation returns true and rearranges the array if permutation exists otherwise returns false and rearranges
    

    //it prints permutations starting the current seq till the last possible not necessarily covers all the permutations
    do{
        for(int i =0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(arr,arr+n));

    // //it rearranges the array to the next permutation
    next_permutation(arr,arr+n);            //TC   ---> O(n)        

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    //implementing next_permutation  ; TC ---> O(n) + O(n) + O(n) = O(3n) ===> O(n)   ; SC ---> O(1)

    //Step 1 : finding idx after which all ele are sorted in des order
    int idx = -1;         
    for(int i = n-2; i>=0 ;i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        int start = 0 , end = n-1;

        while(start < end){
            swap(arr,start,end);
            start++;
            end--;
        }
    }
    else{
        //Step 2 : swapping ele at idx with the greater ele than it 

        int maxi = n-1;
        while(arr[maxi] <= arr[idx]){
            maxi--;
        }
        
        swap(arr,idx,maxi);


        //Step 3 : rev the arr after idx using two points start and end
        int start = idx + 1, end = n-1;

        while(start < end){
            swap(arr,start,end);
            start++;
            end--;
        }
    }

    

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}