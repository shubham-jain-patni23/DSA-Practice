#include<iostream>
using namespace std;


//approach 1;       TC ---> O(n^2 * logn)  ; although from brute force we can do it in O(n^2)  SC ---> O(n) ; 

int merge1(int arr[],int low ,int mid , int high){               //O(n^2)

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
            if(a[i] < 0 && b[j] < 0){
                for(int x = j; x < n2;x++){
                    if(a[i] > (2 * b[x])){
                        inv++;
                    }
                }
            }
            i++;
        }
        else{       //here a[i] is greater than b[j]
            arr[k] = b[j];
            for(int x = i;x<n1;x++){
                if(a[x] > (2 * b[j])){
                    inv++;
                }
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


//approach2   ; TC --> O(2n * logn)

int merge2(int arr[],int low ,int mid , int high){               //O(n) + O(n)

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

    int j = n2- 1;

    for(int i = n1 -1 ; i>=0 ;i--){                         //O(n)
        if(j<0){
            break;
        }
        while(j>=0 && a[i] <= (2 * b[j])){
            j--;
        }
        if(j>=0){
            inv+= (j + 1);
        }
    }

    int i = 0;
    j = 0;
    int k = low;

    while(i <n1 && j < n2){             //O(n)
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{       //here b[j] is smaller than a[i]
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j< n2){
        arr[k] = b[j];
        j++;
        k++;
    }

return inv;
}

//approach 3 ; TC ===> slightly more than O(nlogn)          ---> SC ---> O(n)

int merge3(int arr[],int low ,int mid , int high){               //O(n) + O(n)

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

    int i = n1 -1, j = n2- 1, k = high;
    int ptr = n2-1;
   
    while(i >= 0 && j >= 0){             //O(n)
        if(a[i] >= b[j]){
            arr[k] = a[i];
            while(ptr>=0 && a[i] <= (2 * b[ptr])){
                ptr--;
            }
            inv+= (ptr + 1);
            i--;
        }
        else{       //here b[j] is greater than  a[i]
            arr[k] = b[j];
            j--;
        }
        k--;
    }

    while(i >= 0){
        arr[k] = a[i];
        while(ptr>=0 && a[i] <= (2 * b[ptr])){
            ptr--;
        }
        inv+= (ptr + 1);
        i--;
        k--;
    }

    while(j >= 0){
        arr[k] = b[j];
        j--;
        k--;
    }

return inv;
}

int merge4(int arr[],int low ,int mid , int high){               //O(n) + O(n)

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

    int i = 0, j = 0, k = low;
    int ptr = 0;
   
    while(i < n1 && j < n2){             //O(n)
        if(a[i] <= b[j]){
            arr[k] = a[i];
            while(ptr < n2 && a[i] > 2 * b[ptr]){
                ptr++;
            } 
            inv+= (ptr);
            i++;
        }
        else{       //here b[j] is greater than  a[i]
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = a[i];
        while(ptr < n2 && a[i] > 2 * b[ptr]){
                ptr++;
            } 
            inv+= (ptr);
        i++;
        k++;
    }

    while(j < n2){
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
        inv += merge3(arr,low,mid,high);
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
