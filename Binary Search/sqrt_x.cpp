#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int main(){

    int n;
    cin>>n;

    //approach 1;  using inbuilt pow(n,x) fun       ;TC ---> slightly more than O(1) 

    int ans = pow(n,0.5);   

    // In <cmath>, pow is overloaded for different floating-point types: double , float, long double
    // If you pass integers, they are implicitly converted to double, so the double pow(double, double) version is used.
    // Time complexity of pow() = O(1)` (theoretically constant time, though slower than normal arithmetic) as Computing log 
    // and exp is not O(1) – they use iterative approximations (like Taylor series, polynomial approximations, or hardware instructions).
    // it is computed as a^b = e ^ (b * (lna))

    cout<<ans<<endl;

    // approach 2; we can do binary search from 1 to n/2, considering the edge case of 1, TC ---> O(log2n) ; SC ---> O(1)
    // here, we are able to apply binary search as we are search in some range
    // so typically when we have some range and we are asked to find some min or max then there we can apply binary search

    ans;
    int low = 1, high = n/2;

    while(low<=high){
        int mid = low + (high - low)/2;

        long long x = 1LL* mid * mid;
        if(x > 1LL* n){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0;
}