#include<iostream>
#include<math.h>

using namespace std;

//idea of shell sort : “First do a rough sorting using wide steps, then refine with smaller steps until the whole array is sorted.”
//shell sort ---> improved insertion sort


//this is just my current understanding and the shell_sort is implemented in some way like insertion sort
void shell_sort(int arr[],int n){

    int gap = ceil((float)n/2);
    int cnt = 2;

    while(gap >= 1){
        int first = 0; 
        int second = gap;

        while(second <= n){
            if(arr[first] > arr[second]){
                swap(arr[first], arr[second]);
            }
            first++;
            second++;
        }

        if(gap==1 && cnt==0){
            break;
        }
        else{
            cnt--;
        }

        gap = ceil((float)gap/2);

    }

}

int main(){

    int n,m;
    cin>>n>>m;

    int arr1[n];
    int arr2[m];

    for(int i = 0;i<n;i++){
        cin>>arr1[i];
    }

    for(int i =0;i<m;i++){
        cin>>arr2[i];
    }

    shell_sort(arr1,n);

    for(int i =0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

return 0;
}