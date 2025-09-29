#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    //cnt of +ve and -ve ele are not necessarily equal

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach1 ;   TC --->  O(n) + O(n) = O(2n)  ===> O(n)  ; SC ---> O(n)
    //I will first make a cnt of both +ve and -ve ele

    int pos_cnt = 0, neg_cnt = 0;
    vector<int> ans(n);

    for(int i =0;i<n;i++){      // O(n)
        if(arr[i] > 0){
            pos_cnt++;
        }
        else{
            neg_cnt++;
        }
    }

    int x = min(pos_cnt , neg_cnt);

    //pos and neg are the idx for the pos and neg ele we will update them before updating the ele 
    int pos = -2 , neg = -1;

    //pcnt and ncnt are the cnt for how many time we had two times incremented pos or neg idx
    int pcnt = 0, ncnt =0;

    for(int i = 0;i<n;i++){
        if(arr[i] > 0){
            if(pcnt > x){
                pos++;
            }
            else{
                pos+=2;
                pcnt++;
            }
            ans[pos] = arr[i];
        }
        else{
            if(ncnt >= x){
                neg++;
            }
            else{
                neg+=2;
                ncnt++;
            }
            ans[neg] = arr[i];
        }
    }

    for(int i = 0 ;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    //approach2;    TC ---> O(n) + O(min(pos, neg)) + O(leftovers)  = O(n) + O(n)= O(2n)  ; SC ---> O(n) 
    //saving the pos and neg in an array and filling them in the original array
    //here also first we will have to make a cnt which we can done by checking the size of pos and neg

    vector<int> pos2, neg2; 

    for(int i = 0 ;i<n;i++){
        if(arr[i] > 0){
            pos2.push_back(arr[i]);
        }
        else{
            neg2.push_back(arr[i]);
        }
    }

    int x2 = min(pos2.size(), neg2.size());
    
    int i =0;
    for(i =0;i < x2;i++){
        arr[2*i] = pos2[i];
        arr[2*i + 1] = neg2[i];
    }

    if(pos2.size() > x2){
        for(int k = 2*x2 ;k < n;k++){
            arr[k] = pos2[i++];
        }
    }
    else{
        for(int k = 2*x2 ; k < n;k++){
            arr[k] = neg2[i++];
        }
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}