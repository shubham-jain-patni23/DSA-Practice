#include<iostream>
#include<climits>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach1  ; TC ---> O(n)     ; SC ---> O(1)

    bool neg = false;
    int val = 1;
    int curr = 1;
    int ans = arr[0];
    bool prevneg = false;
    int prevval = 1;
    int cnt = 0 ;

    for(int i =0;i<n;i++){
        if(arr[i] > 0){
            if(prevneg==0){
                prevval *= arr[i];
            }
            cnt++;
            curr = curr * arr[i];
            val = val * arr[i];
            ans = max(ans, curr);
        }
        else if(arr[i]==0){
            ans = max(ans, 0);
            if(prevneg==true){
                if(cnt > 1){
                    int x = val / prevval;
                    ans = max(ans, x);
                }
            }
            val = 1; 
            curr = 1;
            neg = false;
            prevneg = false;
            prevval = 1;
            cnt = 0;
        }
        else{
            cnt++;
            if(neg){
                curr = val; 
                curr = curr * arr[i];
                val = val * arr[i];

                ans = max(ans, curr);
                neg = false;
            }
            else{
                if(prevneg==0){
                    prevneg = true;
                    prevval *= arr[i];
                }
                neg = true;
                val = curr * arr[i];
                curr = 1;

            }
        }
    }

    if(prevneg){
        if(cnt > 1){
            int x = val / prevval;
            ans = max(ans, x);
        }
    }

    cout<<ans<<endl;


    //approach 2 ; the answer will be in all the cases either a prefix of the array or a suffix of the array ; TC ---> O(n) ; SC ---> O(1)

    int pre = 1;
    int suff  = 1;
    ans = INT_MIN;

    for(int i =0;i<n;i++){
        pre *= arr[i];
        suff*= arr[n-  i - 1];
        ans = max(ans, max(pre,suff));
        if(pre==0){
            pre = 1;
        }
        if(suff==0){
            suff = 1;
        }
    }

    cout<<ans<<endl;

return 0;
}