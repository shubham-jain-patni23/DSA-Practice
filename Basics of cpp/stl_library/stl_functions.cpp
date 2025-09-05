#include<bits/stdc++.h>
using namespace std;

bool my_comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first > p2.first) return true;
    return false;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }


    vector<int> v;

    // sort function

    sort(arr,arr+n);         //sort(start add.,end add.) ; start is included but end is not i.e. [start,end)
    sort(v.begin(),v.end());    
    sort(arr+ 2,arr+4);

    //to sort in desc. order 

    sort(arr,arr+n,greater<int>());       //greater<int> is a comparator

    pair<int,int> a[3] = {{1,2},{2,1},{4,1}};

    //sort it acc. to the second ele and if the second ele is same then sort it acc. to the first ele but in desc order

    sort(a,a+n,my_comp);
    //my_comp is self-defined comparator which is a boolean function
    for(int i = 0;i<3;i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;

    }


    //__builtin_popcount() ; it gives the no. of 1's in the binary of any no.

    int num = 7;
    int cnt = __builtin_popcount(num);

    long long num2 = 234233;
    int cnt2  = __builtin_popcountll(num2);         // it is used for long long type of integers

    //next_permutation()

    string s = "123";

    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));            //it gives the next permutation in the dictionary order 
    
    //and if there is no permutation then it returns false (null);
    //but to print all the permutation we have to start with the sorted string as it will print till the desc order 
    

    //max_element() and min_element()

    int maxi = *max_element(arr,arr+n);
    int mini = *min_element(arr,arr+n);


return 0;
}