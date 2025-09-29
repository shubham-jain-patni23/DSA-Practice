#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }


    //approach 1; using freq array ;    TC ---> O(n) + O(n) ===> O(n)   ; SC ---> O(n)

    int freq[n + 1] = {0};

    for(int i =0;i<n;i++){
        freq[arr[i]]++;
    }

    int m,r;

    for(int i = 1;i<=n;i++){
        if(freq[i]==2){
            r = i;
        }
        if(freq[i]==0){
            m = i;
        }
    }
    cout<<m<<" "<<r<<endl;


    //approach 2; using sub and div    ; TC ---> O(n) + O(n) = O(2n)  ===> O(n)         ; SC ---> O(1)

    int totalsum = (n*(n + 1) )/ 2; 
    int totalpro = 1;

    for(int i =1;i<= n;i++){
        totalpro*= i;
    }

    int sum = 0, pro = 1;
    for(int i = 0;i<n;i++){
        sum+= arr[i];
        pro *= arr[i];
    }

    int p = totalsum - sum;
    float q = ((float)totalpro ) / ((float)pro);

    cout<<p<<endl;
    cout<<q<<endl;

    int y = (float)p / (q - (float)1);
    int x = q * y;

    cout<<x<<" "<<y<<endl;

return 0;
}