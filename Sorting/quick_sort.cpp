#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//in c++ stl, sorting fun uses hybrid sorting algo, called , ''Intro_sort' which is a combination of 'Quick_sort' + 'Heap_sort' + 'Insertion_sort'
// first starts with quick_sort and if quicksort degrades to the worst case then it switches to merge_sort and for small partitions it switches to 
//insertion_sort

//time complexity : best and avg case : O(nlog2n) and in worst case O(N^2)
//space complexity : O(1)

//here I am considering the last ele to be my pivot whose idx is returned by this function
int pivot(int arr[],int low,int high){

    int i = low - 1;        //till i all ele are smaller than pivot ele
    int curr = low;         //curr iterates through the array

    int ele = arr[high];

    while(curr<= (high-1)){
        if(arr[curr] < ele){            
            i++;
            swap(arr,i,curr);
        }
        curr++;
    }
    swap(arr,i+1,high);
return i + 1;
}

//here I am considering the first ele to by my pivot whose idx is returned by this function
int pivot2(int arr[],int low,int high){
    int i = high  + 1;
    int curr = high;

    int ele = arr[low];

    while(curr > low){
        if(arr[curr] > ele){
            i--;
            swap(arr,i,curr);
        }
        curr--;
    }
    swap(arr,i-1,low);
return i-1;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // find element greater than pivot on left side
        while (arr[i] <= pivot && i <= high - 1) i++;
        // find element smaller than pivot on right side
        while (arr[j] > pivot && j >= low + 1) j--;

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]); // place pivot in correct position
return j;
}

int pivot3(int arr[],int low,int high){

    int ele = arr[low];             //considering first ele as pivot ele
    int i = low;
    int j = high;

    while(i<j){

        while(arr[i] <= ele && i<=high-1){
            i++;
        }

        while(arr[j] > ele  && j>=low + 1){
            j--;
        }

        if(i < j){          //j would always stop at an idx which have ele <= pivot_ele and we want to swap pivot_ele so we swap it with j
            swap(arr[i],arr[j]);
        }

    }

    swap(arr[low], arr[j]);
return j;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pivot_pt = partition(arr,low,high);
        quick_sort(arr,low,pivot_pt-1);
        quick_sort(arr,pivot_pt+1,high);
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];  

    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    
    quick_sort(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }


return 0;
}