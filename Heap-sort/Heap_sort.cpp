// This program implements Heap sort algorithm for array using heap. 
// Author: RAJ

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr,int curr,int size){
    int left=2*curr+1;
    int right=2*curr+2;
    int largest=curr;
    if(left<size&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=curr){
        swap(arr[curr],arr[largest]);
        heapify(arr,largest,size);
    }

}

void heapsort(vector<int>& arr){
    int size=arr.size();
    //First we convert the given array into heap data structure using heapify algo.
    for(int i=size/2-1;i>=0;i--){               
        heapify(arr,i,size);
    }

    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }

}


int main() {
    vector<int> arr={3,1,2,6,8,9,5,4,10};
    heapsort(arr);
    cout<<"sorted array is: ";
    for(int x:arr){
        cout<<x<<" ";
    }
    
    return 0;
}