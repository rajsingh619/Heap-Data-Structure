// This program implements Heap operations like push,pop using control program.. 
// Author: RAJ

#include <bits/stdc++.h>
using namespace std;
#define maxsize 1000

vector<int> heap;                      //we define an array for heap                 

void heap_push(int val){
    if(heap.size()>=maxsize){
        cout<<"Heap overflow"<<"\n";
    }
    heap.push_back(val);
    int curr=heap.size()-1;
    while(curr>0&&heap[(curr)/2]<heap[curr]){
        swap(heap[curr],heap[(curr)/2]);
        curr=(curr)/2;
    }
}

void maxheapify(int idx){
    int left=2*idx+1;
    int right=2*idx+2;
    int largest=idx;
    if(left<heap.size()&&heap[left]>heap[largest]){
        largest=left;
    }
    if(right<heap.size()&&heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=idx){
        swap(heap[largest],heap[idx]);
        maxheapify(largest);
    }
}

int heap_pop(){
    if(heap.size()<=0){
        cout<<"Heap underflow\n";
        return -1;
    }
    int max=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.resize(heap.size()-1);
    maxheapify(0);
    return max;

}




int main() {
    int choice;
    while(1){
        cout<<"Menu: 1.Push an element 2.Pop an element 3.Display Heap 4.Exit: \n";
        cout<<"Enter your choice : ";
        cin>>choice;
        int x;
        switch(choice){
            case 1:{
                cout<<"Enter the element: ";
                cin>>x;
                heap_push(x);
            }
            break;
            case 2:{
                cout<<"popped: "<<heap_pop()<<"\n";
            }
            break;
            case 3:{
                cout<<"\n"<<"Current heap is: ";
                for(int i:heap){
                    cout<<i<<" ";
                }
                cout<<"\n";
            }
            break;
            case 4:{
                exit(0);
            } 
              
        }
    }


    
    return 0;
}