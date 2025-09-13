#include<iostream> 
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    //approach 1
    int fre[n+1] = {0};

    for(int i =0;i<n;i++){
        cin>>arr[i];
        fre[arr[i]]++;
    }

    for(int i =0;i<=n;i++){         //Time complexity : O(n) 
        if(fre[i]==0){              //Space complexity : O(n)
            cout<<i<<endl;
            break;
        }
    }

    //approach 2 

    int sum = 0;
    for(int i = 0;i<n;i++){         //Time complexity : O(n)
        sum+=arr[i];                //Space complexity : O(1)
    }
  
    int total = (n * (n + 1)) / 2;          
    cout<<(total - sum) <<endl;


    //approach 3

    int xorr = 0 ;
    total = 0;

    for(int i = 0;i<n;i++){
        xorr = xorr ^ arr[i];
        total = total ^ (i + 1);
    }

    

    cout<<(total ^ xorr)<<endl;

return 0;
}