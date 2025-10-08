#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string s; 
    getline(cin ,s);        // to take the complete sentence as input

    int n = s.size();

    // approach1 ; TC ---> O(n) + O(n) + O(n) ===> 3O(n)  ; SC ---> O(1)
    
    //its has a return type of void
    reverse(s.begin(),s.end());         

    string curr = "";
    string ans = "";

    for(int i = 0;i<n;i++){
        if(s[i]==' '){
            if(curr.size()==0){
                continue;
            }
            reverse(curr.begin(), curr.end());      
            ans+= curr;
            ans+=" ";
            curr = "";
        }   
        else{
            curr+= s[i];
        }
    }

    if(s[n-1]!=' '){
        reverse(curr.begin(),curr.end());
        ans+= curr;
    }
    else{
        ans = ans.substr(0,ans.size()-1);
    }

    cout<<ans<<endl;
    cout<<ans.size();

return 0;
}