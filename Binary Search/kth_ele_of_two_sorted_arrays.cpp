#include<iostream>
#include<algorithm>
using namespace std;

//it returns the ele which have x lesser or equal ele than it from both a and b arr
int fun(int a[],int b[],int n1,int n2,int x){    

    //to check if the ele is found in the first arr

    int low = 0 , high = n1-1;

    while(low<=high){                       //log2n * logm
        int mid = low + (high - low)/2;

        int lb = (int)(lower_bound(b , b + n2, a[mid]) - b);        //log2m
        int up =  (int)(upper_bound(b , b + n2, a[mid]) - b);       //log2m

        int start = mid + lb;
        int end = mid + up;

        //x is req

        if(x>= start && x<= end){
            return a[mid];
        }
        else if(x < start){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    low = 0, high = n2 - 1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int lb = (int)(lower_bound(a , a + n1, b[mid]) - a);
        int up =  (int)(upper_bound(a , a + n1, b[mid]) - a);

        int start = mid + lb;
        int end = mid + up;

        //x is req

        if(x>= start && x<= end){
            return b[mid];
        }
        else if(x < start){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
return -1;
}

int main(){

    int n1;
    cin>>n1;

    int n2;
    cin>>n2;

    int k;
    cin>>k;

    int a[n1];
    int b[n2];

    for(int i = 0 ;i<n1;i++){
        cin>>a[i];
    }

    for(int i = 0;i<n2;i++){
        cin>>b[i];
    }

    // approach 1; TC ---> O(log2n * log2m)   ; SC ---> O(1)
    // approach 2; TC ---> O(log2 n * m) ; SC ---> O(1)
    // approach 3 ; Tc ---> O(log2 min(n1,n2)) ; SC ---> O(1)

    int ans = fun(a,b,n1,n2,k-1);
   
    cout<<ans<<endl;

return 0 ;
}