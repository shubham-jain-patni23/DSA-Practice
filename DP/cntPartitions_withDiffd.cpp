#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    int d;
    cin>>d;

    vector<int> arr(n);  

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // same as cnt_subset with sum target, here target = (t + d)/2
    // f + s = total
    // f = s + d
    // f = total + d / 2
    // so, we need to find the cnt of subsets with sum (t + d)/2

    int total = 0 ; 
    for(int i = 0;i<n;i++){
        total+= arr[i];
    }

    if((total + d)%2){   //as 2*f = t + d ; so t + d should always be even
        cout<<0<<endl;
    }
    else{
        int target = (total + d)/2;

        vector<int> prev(target+1,0);
        prev[0] = 1 ; // no. of ways to make 0 without using any ele

        for(int i =1;i<=n;i++){
            vector<int>temp(target+1);
            for(int j =0;j<=target;j++){
                temp[j] = prev[j];
                if((j - arr[i-1]) >=0){
                    temp[j]+= prev[j - arr[i-1]];
                }
            }
            prev = temp;
        }

        cout<<prev[target]<<endl;
    }

return 0;
}