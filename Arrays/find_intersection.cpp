#include<iostream> 
#include<vector>
using namespace std;

int main(){

    int n1, n2;
    cin>>n1>>n2;

    int a[n1] , b[n2];
    
    for(int i = 0;i<n1;i++){
        cin>>a[i];
    }

    for(int i = 0;i<n2;i++){
        cin>>b[i];
    }

    vector<int> ans;

    int i = 0, j =0;

    while(i<n1 && j<n2){         //Time complexity : O(n1 + n2); and space complexity : O(1)
    
        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            // if(i==0 || a[i]!=a[i-1]){                //if repeatetion is not allowed
            //     ans.push_back(a[i]);
            // }

            ans.push_back(a[i]);            // if repeatetion  is allowed

            i++;
            j++;
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }

    cout<<endl;

    //approach 2 

    bool visited[n2] = {0};

    vector<int> temp;

    for(int i = 0;i<n1;i++){                        //Time complexity : O(n1* n2) 
        for(int j = 0;j<n2;j++){                    //Spcace complexity : O(min(n1,n2))
            if(b[j]==a[i] && visited[j]==0){
                temp.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            else if(a[i] < b[j]){
                break;
            }
        }
    }

    for(auto it : temp){
        cout<<it<<" ";
    }

    cout<<endl;
    
return 0;
}