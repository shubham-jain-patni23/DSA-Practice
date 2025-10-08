#include<iostream>
#include<stack>
using namespace std;

int main(){

    string s;
    cin>>s;

    int n = s.size();

    //approach 1 ; using stack ; TC ---> O(n)  ; SC ---> O(n/2)
    
    stack<int> st;
    string ans = "";

    bool first = true;
    
    for(int i = 0;i<n;i++){
        if(s[i]=='('){
            st.push(s[i]);
            if(!first){
                ans+=s[i];
            }
            else{
                first = false;
            }
        }
        else{
            st.pop();
            if(st.size() > 0){
                ans+= s[i];
            }
            else{
                first =true;
            }
        }
    }

    cout<<ans<<endl;

return 0;
}