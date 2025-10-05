#include<iostream>
#include<algorithm>
using namespace std;

// 0 means lesser , 1 means equal , 2 means more from first arr
//fun to check whether taking mid no. of elements from first arr make the ele be form the median, x is total ele before median
int isTrue(int a[],int b[],int n1,int n2,int mid,int x){        // O(1)
    if(mid > n1){          
        return 0;
    }

    int other = x - mid;
    if(other > n2){
        return 2;
    }

    //idx of the last ele from the second arr
    int idx = other  - 1; 

    //condition that we could have taken more from first arr
    if(mid < n1 && a[mid] < b[idx]){
        return 2;
    }

    //condition that we could have taken more from second arr
    if(other < n2){
        if(mid > 0 && a[mid-1] > b[other]){
            return 0;
        }
    }
return 1;
}

//it returns the ele which have x lesser or equal ele than it from both a and b arr
int fun(int a[],int b[],int n1,int n2,int x){    

    //to check if the ele is found in the first arr

    int low = 0 , high = n1-1;

    while(low<=high){                       //O(log2n * log2m)
        int mid = low + (high - low)/2;

        int lb = (int)(lower_bound(b , b + n2, a[mid]) - b);        //log2m
        int up =  (int)(upper_bound(b , b + n2, a[mid]) - b);       //log2m

        int start = mid + lb;
        int end = mid + up;

        //x is req

        if(x>= start && x<= end){
            return a[mid];
        }
        else if(x < start){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    low = 0, high = n2 - 1;

    while(low<=high){    //O(log2m * log2n)
        int mid = low + (high - low)/2;

        int lb = (int)(lower_bound(a , a + n1, b[mid]) - a);
        int up =  (int)(upper_bound(a , a + n1, b[mid]) - a);

        int start = mid + lb;
        int end = mid + up;

        //x is req

        if(x>= start && x<= end){
            return b[mid];
        }
        else if(x < start){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
return -1;
}

//fun returns the ele which has only x ele greater than it 
int fun2(int a[],int b[],int n1,int n2,int x){
    
    // searching the ele in the first arr
    int low, high = n1-1;
    if(n1 < (x + 1)){
        low = 0 ;
    }
    else{
        low = n1 - (x + 1);
    }

    while(low <= high){
        int mid = low + (high - low)/2;

        int curr = n1 - (mid + 1);          
        int need = x - curr;           //as we have seleted low so need can't be less than 0

        if(n2 >= need){
            int first = n2 - need;

            if(first==n2 || b[first] >= a[mid]){

                if(first==0 || b[first -1] <= a[mid]){
                    return a[mid];
                }
                else{       //that means there are more than x ele greater than a[mid] we will go to right
                    low = mid + 1;
                }

            }
            else{           //that means total greater ele are lesser than x , we will go to the left
                high = mid - 1;
            }

        }
        else{           //if b has lesser ele than needed than we will try to have more ele in a arr 
            high = mid -1;
        }
    }

    // searching the ele in the second arr
    low, high = n2-1;
    if(n2 < (x + 1)){
        low = 0 ;
    }
    else{
        low = n2 - (x + 1);
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        int curr = n2 - (mid + 1);          
        int need = x - curr ;           //as we have seleted low so need can't be less than 0

        if(n1 >= need){
            int first = n1 - need;

            if(first==n1 || a[first] >= b[mid]){

                if(first==0 || a[first -1] <= b[mid]){
                    return b[mid];
                }
                else{       //that means there are more than x ele greater than a[mid] we will go to right
                    low = mid + 1;
                }

            }
            else{           //that means total greater ele are lesser than x , we will go to the left
                high = mid - 1;
            }

        }
        else{           //if b has lesser ele than needed than we will try to have more ele in a arr 
            high = mid -1;
        }
    }
return -1;
}

int main(){

    int n1;
    cin>>n1;

    int n2;
    cin>>n2;

    int a[n1];
    int b[n2];

    for(int i = 0 ;i<n1;i++){
        cin>>a[i];
    }

    for(int i = 0;i<n2;i++){
        cin>>b[i];
    }

    // approach 1 ; TC ---> O((n+m)log2(n+m)) + O(n+m)
    // just merging both arr into some temp arr and sorting the both arr and then finding the median ; 

    // approach 2 ; we can merge both arrays in sorted manner in TC => O(n + m)  and SC => O(n+m) as both are sorted

    //approach 3 ; TC ---> O(n + m) ; SC ---> O(1)
    // doing linear search till the mid and then finding the median ; 

    int total = n1 + n2; 
    double first, second = 0; 

    int i  = 0 , j = 0;
    int cnt = 0;
    int x = ((n1 + n2 ) + 2 - 1)/2;

    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            cnt++;
            if(cnt==x){
                first = a[i];
                i++;
                if(total%2==0){
                    if(i<n1){
                        second = min(a[i], b[j]);
                    }
                    else{
                        second = b[j];
                    }
                }
                break;
            }
            i++;
        }
        else{
            cnt++;
            if(cnt==x){
                first = b[j];
                j++;
                if(total%2==0){
                    if(j<n2){
                        second = min(a[i], b[j]);
                    }
                    else{
                        second = a[i];
                    }
                }
                break;
            }
            
            j++;
        }
    }

    if(cnt < x){
        while(i< n1){
            cnt++;
            if(cnt==x){
                first = a[i];
                i++;
                if(total%2==0){
                    second = a[i];
                }
                break;
            }
            i++;
        }

        while(j < n2){
            cnt++;
            if(cnt==x){
                first = b[j];
                j++;
                if(total%2==0){
                    second = b[j];
                }
                break;
            }
            j++;
        }
    }

    double ans = first;

    if(total%2==0){
        ans = (ans + second)/2;
    }

    cout<<ans<<endl;

    // approach 4;   TC ---> O(4log2nlog2m)       ; SC ---> O()
    // we are using fun of TC - O(2log2n* log2m) which returns the ele which has x ele lesser than it considering both the arrays

    // through this we kind of merged two sorted arr in log2n * log2m time although it will O(n + m) to access them 
    // but if the work is desired only from the ele then it may work
    // for(int i = 0;i<=8;i++){
    //     cout<<fun(a,b,n1,n2,i)<<endl;
    // }

    ans = fun(a,b,n1,n2,x-1);         //2log2n * log2m

    if(total%2==0){
        ans =( ans + fun(a,b,n1,n2,x)) / 2;            //2log2n * log2m    
    }
    cout<<ans<<endl;

    // approach 5 ;  TC ---> O(2log2(n*m))   ===> O(log2(n*m))   ; SC ---> O(1)
    // we are using fun2 of TC - O(log2(n*m)) which returns the ele which has x ele greater than it considering both the arrays
    // in fun2 we are just making use of the arrays being sorted to check the cnt of greater ele from a particular ele in O(1)
    // whereas in fun to check the cnt we were taking O(log2n) complexity

    // for(int i = 0;i<=10;i++){
    //     cout<<fun2(a,b,n1,n2,i)<<endl;
    // }

    ans = fun2(a,b,n1,n2,x-1);

    if(total%2==0){
        ans = ans + (double)fun2(a,b,n1,n2,x);
        ans = ans / 2.0;
    }

    cout<<ans<<endl;

    // approach 6 ;  TC ---> O(log2 min(n1,n2)) * O(1)  ===> O(min(n1,n2)) ; SC ---> O(1)
    // we know how many no. are there before mid, so we are trying to find how many of them are from first arr
    // min ele from first arr can be 0 and the max can be(x-1) i.e. total elements before median
    // apply bs over the range 0 to (x-1) and check whether is it possible or not 
    // if possible then check the min of next 2 ele in both the arr which will be median in case of odd 
    // and in case of even two ele we have to check 

    int y = x - 1;      //ele before mid

    int low = 0 , high = y;
    // we can max of n1 ele from the first arr so high i.e. the max ele that we can from the first ele will be min(n1, y)
    // we will apply binary search on the arr with smaller size
    high = min(high, n1);
    ans = 0 ; 

    while(low<=high){
        int mid = low + (high - low)/2;
        int temp = isTrue(a,b,n1,n2,mid,y);
        int other = y - mid;

        if(temp == 1){  
            if((mid < n1) && (other < n2)){
                if(a[mid] <= b[other]){
                    ans = a[mid];
                    mid++;
                }
                else{
                    ans = b[other];
                    other++;
                }

                if(total%2==0){
                    if((mid < n1) && (other < n2)){
                        if(a[mid] <= b[other]){
                            ans = ans  + (double)a[mid];
                            ans = ans / 2.0;
                        }
                        else{
                            ans = ans  + (double)b[other];
                            ans = ans / 2.0;
                        }
                    }
                    else if(mid < n1){
                        ans = ans + (double)a[mid];
                        ans = ans / 2.0;
                    }
                    else{
                        ans = ans + (double)b[other];
                        ans = ans / 2.0;
                    }
                }

            }
            else if(mid < n1){
                ans = a[mid];
                if(total%2==0){
                    ans = ans + (double)a[mid + 1];
                    ans = ans / 2.0;
                }
            }
            else{
                ans = b[other];
                if(total%2==0){
                    ans = ans + (double)b[other + 1];
                    ans = ans/2.0;
                }
            }
            break;
        }
        else if(temp == 0){     // we need to take lesser from first arr
            high = mid -1;
        }
        else{       //temp == 2     // we need to take more from first arr
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0 ;
}