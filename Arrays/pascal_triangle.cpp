#include<iostream>
#include<vector>
using namespace std;

int fac(int n){
    long long ans = 1;
    for(int i = 2;i<=n;i++){
        ans *= i;
    }
return ans;
}

int nCr(int n,int r){           //TC ---> O(r)   ; SC ---> O(1)

    int ans = 1;

    for(int i = 1;i<=r;i++){
        ans = ans * n;
        ans /= i;
        n--;
    }

return ans;
}

vector<int> generate_row(int row){
    long long ans =1 ;
    vector<int> temp;

    temp.push_back(ans);

    for(int i = 1;i<row; i++){
        ans = ans * (row - i);
        ans = ans / i;
        temp.push_back(ans);
    }
return temp;
}

int main(){
    
    int n;
    cin>>n;

    vector<vector<int>> ans;

    for(int i = 0;i<n;i++){             //TC ---> O(n^2)       ; SC ---> O(n^2)
        vector<int> temp(i+1,1);
        for(int j =1; j<i;j++){
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(temp);

    }

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //if only an ele at a particular row and col is asked 

    //approach 1 ; make complete pascal triangle and return the val ; TC ---> O(n^2)  ; SC ---> O(n^2)

    //approach 2 
    //the ele at ith row and jth col is given by iCj in zero bases indexing 
    //nCr = n! / r! (n - r)

    int row,col;
    cin>>row>>col;

    int res = nCr(row - 1, col- 1);         //TC  ---> O(col)
    cout<<res<<endl;
    cout<<endl;

    //if some row of pascal triangle is asked to print
    //approach 1; make complete pascal triangle and print the row : TC ---> O(n^2) ; SC ---> O(n^2)

    //approach 2 : using nCr instead of building complete pascal tree  ; TC ---> O(r * (r + 1)/2) ==> O(r^2)  ; SC ---> O(1)

    cin>>row;

    for(int i = 0;i<row;i++){
        cout<<nCr(row -1, i)<<" ";
    }
    cout<<endl;
    //approach 3 ; we can reduce the cal of ncr  ; TC ----> O(r)   ; SC ----> O(1)

    cin>>row;

    long long curr = 1;
    cout<<1<<" ";

    for(int i = 1;i<row; i++){
        curr = curr * (row - i);
        curr = curr / i;
        cout<<curr<<" ";
    }
    cout<<endl;
    vector<int> a = generate_row(row);

    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<endl;

    //for pascal triangle we can also use this approach of using nCr  ; TC ---> O(n^2)   SC ---> O(n^2)

    cin>>n;

    for(int i = 1;i<=n;i++){
        vector<int> temp = generate_row(i);
        for(auto it : temp){
            cout<<it<<" ";
        }
        cout<<endl;
    }

return 0;
}