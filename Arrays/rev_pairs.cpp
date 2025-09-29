#include<iostream>
using namespace std;

int merge(int arr[],int low ,int mid , int high){

    int inv = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int a[n1], b[n2];

    for(int i = 0;i<n1;i++){
        a[i] = arr[low + i];
    }

    for(int i = 0;i<n2;i++){
        b[i] = arr[mid +1+ i];
    }

    int i = 0, j = 0 , k = low;

    while(i < n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            if(a[i] > (2* b[j])){
                inv+= (j + 1);
            }
            j++;
            
        }
        k++;
    }

    while(i< n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }

return inv;
}

int rev_pair(int arr[],int low,int high){
    int inv = 0;
    if(low < high){
        int mid = (low + high)/2;
        inv += rev_pair(arr,low,mid);
        inv += rev_pair(arr,mid+1,high);
        inv += merge(arr,low,mid,high);
    }
return inv;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int ans = rev_pair(arr,0,n-1);

    cout<<ans<<endl;

return 0;
}
