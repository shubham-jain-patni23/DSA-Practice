#include<iostream>
#include<stack>
using namespace std;

// approach 1 ;     Tc ---> O(n^2)    ;SC ---> O(n) due to call stack 
// using recursion for sorting or reversing the stack 

void fun(int x, stack<int> &st){            // O(n)
    if(st.empty()){
        st.push(x);
        return;
    }

    if(x >= st.top()){
        st.push(x);
        return ; 
    }
    int y = st.top();
    st.pop();
    fun(x,st);
    st.push(y);
}

void sortStack(stack<int> &st){         //O(n^2)

    int n = st.size();
    if(n==0 || n==1){
        return ;
    }

    int x = st.top();
    st.pop();

    sortStack(st);           // sort remaining
    fun(x,st);          // push at correct place
}

void pushatend(int x, stack<int>&st){   //O(n)
    if(st.empty()){
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    pushatend(x,st);
    st.push(y);

}

void reverseStack(stack<int> &st){          //O(n^2)

    int n = st.size();
    if(n==0 || n==1){
        return;
    }

    int x = st.top();
    st.pop();
    reverseStack(st);
    pushatend(x,st);

}

int main(){

    int n;
    cin>>n;

    stack<int> st;

    int x;
    for(int i = 1;i<=n;i++){
        cin>>x;
        st.push(x);
    }

    //sortStack(st);
    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

return 0;
}