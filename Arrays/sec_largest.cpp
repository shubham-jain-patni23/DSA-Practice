#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }


    int first = arr[0];
    int second = arr[0];

    for(int i = 0;i<n;i++){
        if(arr[i] > first){
            second  = first;
            first = arr[i];
        }
        else if(arr[i] < first){
            if(arr[i] > second || first==second){
                second = arr[i];
            }
        }
    }

    cout<<first<<" "<<second<<endl;

    first = arr[0];
    second = arr[1];

    for(int i = 0 ; i< n-1;i+=2){
        int maxi = max(arr[i], arr[i+1]);
        int mini = min(arr[i], arr[i+1]);
        //we will update f only when maxi is > f

        if(maxi > first){          
            second = max(first, mini);
            first = maxi;           //in this case definetely f and s would be different
        }
        else if(maxi != first){
            if(maxi > second || first == second){
                second = maxi;
            }
        }
        else if(mini != first){
            if(mini > second || first==second){
                second = mini;
            }
        }
    }

    if(arr[n-1] > first){
        second = first;
        first = arr[n-1];
    }
    else if(arr[n-1]!=first){
        if(arr[n-1] > second || first==second){
            second = arr[n-1];
        }
    }

    cout<<first<<" "<<second<<endl;

    first = arr[0];
    second = arr[0];

    for(int i = 0;i<n;i++){
        first = max(first,arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(arr[i] != first){
            if(first==second || arr[i] > second){
                second = arr[i];
            }
        }
    }

    cout<<first<<" "<<second<<endl;

    //if array contains only +ve integers 
    first = arr[0];
    second = -1;

    // int x = INT_MAX;     // we can initialize second to INT_MIN here 
    // cout<<"x "<<x<<endl;

    for(int i = 0;i<n;i++){
        if(arr[i] > first){
            second  = first;
            first = arr[i];
        }
        else{
            if(arr[i] < first && arr[i] > second){
                second = arr[i];
            }
        }
    }

    cout<<first<<" "<<second<<endl;

    sort(arr, arr + n);         //O(Nlog2N)
    first = arr[n-1];
    second  = arr[n-2];
    for(int i = n-2 ;i>=0;i--){
        if(arr[i]!=arr[i+1]){
            second = arr[i-2];
            break;
        }
    }

    cout<<first<<" "<<second<<endl;

    int f= arr[0];    
    int s = INT_MAX;

    for(int  i = 0;i<n;i++){
        if(arr[i] < f){
            s = f;
            f = arr[i];
        }
        else if(arr[i] > f && arr[i] < s){
            s = arr[i];
        }
    }

    //second smallest

    cout<<f<<" "<<s<<endl;

    // unordered_set<int>s;

    // for(int i = 0;i<n;i++){
    //     s.insert(arr[i]);
    // }

    // if(s.size()==1){
    //     cout<<"does not exist"<<endl;
    // }
    // else{

    //     //sort and give the second_last idx : O(n);
    //     sort(arr, arr + n);
    //     int idx = n-2;

    //     for(int i = n - 2;i>=0;i--){
    //         if(arr[i]==arr[i+1]){
    //             idx--;
    //         }
    //     }

    //     if(idx==-1){
    //         cout<<"does not exist"<<endl;
    //     }
    //     else{
    //         cout<<arr[idx]<<endl;
    //     }

    //     //better approach comparing 1 ele at a time

    //     int f = -1;
    //     int sd = -1;

    //     for(auto it : s){
    //         if(it > f){
    //             sd = f;
    //             f = it;
    //         }
    //         else if(it > sd){
    //             sd = it;
    //         }
    //     }

    //     cout<<sd<<endl;

    //     int first = arr[0];
    //     int second = arr[1];

    //     for(int i = 0 ;i<n-1;i+=2){
    //         int maxi = max(arr[i],arr[i+1]);
    //         int mini = min(arr[i],arr[i+1]);

    //         if(maxi > first){
    //             second = max(first, mini);
    //             first = maxi ; 
    //         }
    //         else if(maxi > second){
    //             second = maxi;
    //         }

    //     }

    //     if(arr[n-1] > first ){
    //         second = first;
    //         first = arr[n-1];
    //     }

    //     //for the duplicate we can again iterate the array and check 

    //     if(first==second){
    //         for(int i = 0;i<n;i++){
    //             if(arr[i] < second){
    //                 mini = max(mini, arr[i]);
    //             }
    //         }
    //     }

    //     cout<<second<<endl;

    // }

return 0;
}