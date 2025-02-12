#include <bits/stdc++.h>
using namespace std;


struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    void MinHeapify(int index);
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    };
};
void heapifyUp(int *&harr,int index){
    int parent = (index-1)/2;
    
    if(index>0 && harr[parent]>harr[index]){
        swap(harr[parent],harr[index]);
        heapifyUp(harr,parent);
    }
}
int MinHeap::extractMin() 
{
    // Your code here
    if(heap_size==0)
        return -1;
    
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
        
    int mini = harr[0];
    
    swap(harr[0] , harr[heap_size-1]);
    heap_size--;
    
    MinHeapify(0);
    
    return mini;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    swap(harr[i] , harr[heap_size-1]);
    heap_size--;
    
    if(i>0 && harr[i]<harr[(i-1)/2])
        heapifyUp(harr,i);
    else
        MinHeapify(i);
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    // Your code here
    if(heap_size == capacity)
        return;
        
    heap_size++;
    harr[heap_size-1] = k;
    
    heapifyUp(harr,heap_size-1);
}

//Function to change value at ith index and store that value at first index.
// void MinHeap::decreaseKey(int i, int new_val) 
// {
//     harr[i] = new_val;
//     while (i != 0 && harr[parent(i)] > harr[i]) {
//         swap(harr[i], harr[parent(i)]);
//         i = parent(i);
//     }
// }

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}