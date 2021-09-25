//This program implements the most common heap algorithms - 1.Extract max 2.Increase Key 3.Decrease Key 4.Insert Key 
//  
// Author: RAJ

#include <bits/stdc++.h>
using namespace std;

void maxheapify(vector<int>& arr,int i){
    int size=arr.size();
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,largest);
    }
}

int extractmax(vector<int>& arr){
    if(arr.size()<1){
        cout<<"Heap Underflow\n";
        return -1;
    }
    int max=arr[0];
    arr[0]=arr[arr.size()-1];
    arr.resize(arr.size()-1);
    maxheapify(arr,0);
    return max;
}

void increaseKey(vector<int>& arr,int idx,int key){
    arr[idx]=key;
    while(arr[idx/2]<arr[idx]&&idx>0){
        swap(arr[idx],arr[idx/2]);
        idx=idx/2;
    }
}

int main() {
    vector<int> arr={9,8,7,5,4,3,2};   //Max heap array
    cout<<"Menu : 1.Extract Max 2.Increase Key 3.Decrease Key 4.Insert Key 5.Exit"<<"\n";
    int choice;
    while(1){
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                int max=extractmax(arr);
                cout<<"The maximum element in the heap is: "<<max<<"\n";
            }
            break;
            case 2:{
                cout<<"Enter the index to be updated: ";
                int i;
                cin>>i;
                cout<<"Enter a value greater than "<<arr[i]<<": ";
                int x;
                cin>>x;
                increaseKey(arr,i,x);
                cout<<"The new heap is: ";
                for(int x:arr){
                    cout<<x<<" ";
                }
                cout<<"\n";
            }
            break;
            case 3://decreaseKey(arr,size);
            break;
            case 4://insertKey(arr,size);
            case 5:exit(0);
            break;
            default: exit(0);
        }
        
    }
    
    return 0;
}