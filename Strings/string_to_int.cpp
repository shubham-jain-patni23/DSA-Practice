#include<iostream>
#include<climits>
#include<string>
using namespace std;


int main(){

    string s;
    cin>>s;

    int n =s.size();

    bool pos = true;
    long long ans = 0;
    int i =0;

    while(i<n && s[i]==' '){
        i++;
    }

    if(i<n){
        if(s[i]=='-'){
            pos = false;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
    }

    for(; i< n;i++){
        if(s[i]>='0' && s[i]<='9'){
            long long x = ans * 10;
            long long y = (int)(s[i] - '0');
            ans= x  + y;
            if(pos){
                if(ans > INT_MAX){
                    ans = INT_MAX;
                    break;
                }
            }
            else{
                if(ans > (1LL*INT_MAX + 1)){
                    ans = INT_MIN;
                    break;
                }
            }
        }
        else{
            break;
        }
    }

    if(!pos){
        if(ans != INT_MIN){
            ans = -ans;
        }
    }

    cout<<ans<<endl;

return 0;
}