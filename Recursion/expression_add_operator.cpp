#include<iostream>
#include<string>
#include<stack> 
#include<vector>
using namespace std;

void fun_push(stack<char> &st, char ch){
    if(st.empty()){
        st.push(ch);
        return ;
    }

    if(st.top()=='*' && (ch=='+' || ch=='-')){
        st.pop();
        fun_push(st,ch);
        st.push('*');
    }
    else{
        st.push(ch);
    }
}

int val_fun(string s){
    stack<char>st;

    string curr = "";

    for(int i = 0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='*' || s[i]=='-'){
            fun_push(st,s[i]);
        }
        else{
            curr+= s[i];
        }
    }

    while(!st.empty()){
        curr= st.top() + curr;
        st.pop();
    }

    int ans = 0 ;

    stack<int> val;

    for(int i = curr.size() - 1 ; i>=0;i--){
        if(curr[i] >= '0' && curr[i] <='9'){
            st.push((int)(curr[i]-'0'));
        }
        else{
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            int res;
            if(curr[i]=='+'){
                res = first  + second;
            }
            else if(curr[i]=='*'){
                res = first * second;
            }
            else{
                res = first - second;
            }
            st.push(res);
        }
    }

return st.top();
}

int eval(string s){

    int n = s.size();
    int first = (int)s[0] - '0';
    int second = 0 ;
    bool sflag = false;
    string curr = "";
    if(s.size()==1){
        curr = to_string(first);
    }

    for(int i = 1;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            while((i<n) && (s[i]>='0' && s[i]<='9')){
                if(!sflag){
                    first = first * 10 + (int)(s[i]-'0');
                }
                else{
                    second = second * 10 + (int)(s[i] - '0');
                }
                i++;
            }

            if(i==n){
                string temp;
                if(!sflag){
                    temp = to_string(first);
                    curr+= temp;
                }
                else{
                    curr+= to_string(first * second);
                }
            }
            i--;
        }
        else{
            if(!sflag){
                if(s[i]=='+' || s[i]=='-'){
                    curr+= (to_string(first) + s[i]);
                    first = 0 ;
                }
                else{
                    sflag = true;
                }
            }
            else{
                if(s[i]=='+'||s[i]=='-'){
                    curr = curr + to_string(first * second) + s[i];
                    sflag = false; 
                    first = 0; 
                    second = 0 ;
                }
                else{
                    first = first * second ; 
                    second= 0 ; 
                }
            }
        }

    }

    //eval the exp containing only +ve and -ve 

    int ans =0 ; 
    first = (int)curr[0]-'0';
    second = 0; 
    sflag = false;
    char ch = '*'; 

    if(curr.size()==1){
        ans =first;
    }

    for(int i =1 ;i<curr.size();i++){
        // if(i==2){
        //     cout<<curr[i]<<" "<<ch<<" "<<first<<" "<<second<<endl;
        // }
        if(curr[i]>='0' && curr[i]<='9'){
            while((i<curr.size()) && (curr[i]>='0' && curr[i]<='9')){
                if(!sflag){
                    first = first * 10 + (int)(curr[i]-'0');
                }
                else{
                    second = second * 10 + (int)(curr[i] - '0');
                }
                i++;
            }
            if(i==curr.size()){
                if(ch=='+'){
                    ans+= (first + second);
                }
                else if(ch=='-'){
                    ans+= (first - second);
                }
                else{
                    ans = first;
                }
            }
            i--;
        }
        else{
            if(!sflag){
                sflag = true;
                ch = curr[i];
            }
            else{
                if(ch=='+'){
                    first = first + second ; 
                    second = 0 ; 
                    ch =curr[i];
                }
                else{
                    first = first - second ; 
                    second = 0 ;
                    ch = curr[i];
                }
            }
        }
    }

return ans ; 
}

string fun_process(string s){

//     int n = s.size();
//     int first = (int)s[0] - '0';
//     string ans = "";

//     if(s.size()==1){
//         ans =to_string(first);
//     }

//     for(int i = 1;i<n;i++){
//         if(s[i]>='0' && s[i]<='9'){
//             while((i<n) && (s[i]>='0' && s[i]<='9')){
//                 first = first * 10 + (int)(s[i]-'0');
//                 i++;
//             }
//             if(i==n){
//                 ans = ans + to_string(first);
//             }
//             i--;
//         }
//         else{
//             ans = ans + to_string(first) + s[i];
//             first = 0 ; 
//         }
//     }

// return ans;
return "";
}

void fun(string s, int target, int idx, vector<string>&ans ,string temp){

    if(idx==s.size()){
        temp = fun_process(temp);

        int i = 0 ;
        while(i<s.size() && s[i]=='0'){
            i++;
        }
        for(int j = 0; j<temp.size();j++){
            if(i>=s.size()){
                return ; 
            }
            if(temp[j]>='0' && temp[j]<='9'){
                if(temp[j]==s[i]){
                    i++;
                }
                else{
                    return ; 
                }
            }
        }

        int x = eval(temp);
        if(x==target){
            ans.push_back(temp);
        }
        return ;
    }

    // use nothing
    fun(s,target, idx + 1, ans, temp  + s[idx]);

    // use '+'
    fun(s, target, idx + 1, ans , temp + '+' + s[idx]);

    // use '-'
    fun(s, target, idx + 1, ans, temp + '-' + s[idx]);

    // use '*'
    fun(s, target, idx + 1, ans, temp + '*' + s[idx]);

}

int main(){

    string s;
    cin>>s;

    int target;
    cin>>target;

    vector<string> ans;

    string temp = "";
    temp+= s[0];
    fun(s,target,1, ans, temp);
    
    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;

    string p = "1*05";
    cout<<eval(p)<<endl;

return 0;
}