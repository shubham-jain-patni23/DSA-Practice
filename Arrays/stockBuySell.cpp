#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1 : if on a particular stocks price min till now then we will update our mini and if it is greater than mini than we 
    //will if are getting better profit

    int ans = 0;
    int mini = arr[0];

    for(int i = 1;i<n;i++){
        if(arr[i] < mini){          //aur bhi saste me mil rha hai
            mini = arr[i];
        }
        else{           
            ans = max(ans, arr[i] - mini);
        }
    }

    cout<<ans<<endl;

return 0;
}