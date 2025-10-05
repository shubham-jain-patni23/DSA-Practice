#include<iostream>
using namespace std;

int last_bit(int x){
    //int ans = 0 ;
    // while(x%2==0){               //checking last pos of x 
    //     ans++;
    //     x/=2;
    // }

    // int ans = 0;
    // int y= 1;
    // while(x & y ==0){           //using ans
    //     ans++;
    //     y = y>>1;
    // }

    int ans = 0 ;
    while(true){
        int y = 1<<ans;
        if((x & y ) != 0){
            break;
        }
    }

return ans;
}

//NOTE ; x - 1 is same as x till before the last bit e.g if x = 101100 then x - 1 = 101011
//so doing bitwise & of x and (x - 1) will be the same before the last set bit in x ; e.g. (101100) & (101011) = (101000)
//so if take the negation of (x - 1) and if we do its bitwise & with x then all the bits except the first set bit in x will be zero , e.g
//~(101011) = (010100)  and (101100) & (010100) = (000100) 

bool check_bit(int x,int pos){
    int y = 1 << pos;
    
return x & y;
}

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

    int m = -1, r=-1;

    for(int i = 1;i<=n;i++){
        if(freq[i]==2){
            r = i;
        }
        if(freq[i]==0){
            m = i;
        }
        if(m!=-1 && r!=-1){
            break;
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

    int y = (float)p / (q - (float)1);
    int x = q * y;

    cout<<x<<" "<<y<<endl;


    //approach3; using sub and sub of sq ;     TC---> O(n)     ; SC ---> O(1)

    long long totalsq = (1LL*n * (n + 1) *(2*n + 1))/(1LL*6);
    long long sq = 0;

    for(int i = 0;i<n;i++){
        sq += (1LL* arr[i] * arr[i]);
    }

    long long a = totalsum - sum;
    long long b = totalsq - sq;
    
    b = b/ a;   // b = x + y and a = x - y

    long long ans1 = (a + b)/2;
    //long long ans2 = (b - a)/2;    or
    long long ans2 = ans1 - a;

    cout<<ans1<<" "<<ans2<<endl;


    //approach 4; using xor   ; TC ---> O(n) + O(n) + O(n) = O(3n)  ===> O(n)      ; SC ---> O(1)
    //we will first xor all the numbers and number from 1 to n ; it will give x ^ y
    //now we will find a set bit in the x ^ y to differentiate b/w x and y by making groups of ele with have 0 and which have 1 

    x = 0;      //find xor of all and of 1 to n

    for(int i = 0 ;i<n;i++){            //O(n)
        x = x ^ (i + 1);
        x = x ^ arr[i];
    }

    int lbit = last_bit(x);

    int first = 0 ;
    int second = 0;

    for(int i= 0;i<n;i++){      //O(n)
        if(check_bit(i+1,lbit)){
            first = first ^ (i + 1);
        }
        else{
            second = second ^ (i+1);
        }

        if(check_bit(arr[i],lbit)){
            first = first ^ arr[i];
        }
        else{
            second = second ^ arr[i];
        }
    }

    //first = missing  and second = rep

    for(int i = 0;i<n;i++){     //O(n)
        if(arr[i]==second){
            break;
        }
        if(arr[i]==first){
            int temp = first;
            first = second;
            second = temp;
            break;
        }
    }

    cout<<first<<" "<<second<<endl;

return 0;
}