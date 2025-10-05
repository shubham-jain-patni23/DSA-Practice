#include<iostream>
using namespace std;

//approach 1; if the ele is not found than high always points to the smaller ele while doing binary search ; TC ---> O(log2n)  ; SC ---> O(1)
//return the ele if exists otherwise the smaller ele than it if that exists otherwise -1
int floor(int arr[],int n,int x){

    int low = 0 , high = n -1 ;

    while(low <= high){
        int mid = low + (high - low) /2;
        if(arr[mid]==x){
            high = mid;
            break;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
return high;
}

//approach2 ; we will move to the right
int ffloor(int arr[],int n,int x){
    int ans = -1;
    int low = 0 , high = n -1 ;

    while(low <= high){
        int mid = low + (high - low) /2;
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
return ans;
}

//approach 3; using lower_bound and giving the ele before it 

int floor2(int arr[],int n,int x){
    int ans = lower_bound(arr, arr + n, x) - arr;
    
    ans--;
    if(ans==-1){
        return ans;
    }

return arr[ans];
}

//approach ; using ceil ; TC ---> O(log2n)   ; SC ---> O(1)
//return the ele if exists otherwise the greater ele than it if that exists otherwise -1
int ceil(int arr[],int n,int x){            
    return lower_bound(arr,arr + n, x) - arr;
}

int main(){

    int n;
    cin>>n;

    int x;
    cin>>x;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
   
    int ans = ceil(arr,n,x);
    if(ans==n){
        cout<<"ceil "<<-1<<endl;
    }
    else{
        cout<<"ceil "<<arr[ans]<<endl;
    }
    ans = floor(arr,n,x);

    if(ans != -1){
        cout<<"floor "<<arr[ans]<<endl;
    }
    else{
        cout<<"floor "<<-1<<endl;
    }

    ans = floor2(arr,n,x);

    cout<<"floor "<<ans<<endl;

    ans = ffloor(arr,n,x);
    cout<<"floor "<<ans<<endl;

return 0;
}